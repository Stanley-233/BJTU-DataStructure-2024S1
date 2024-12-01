#include "mainwindow.h"

#include <QTimer>
#include <QFile>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QInputDialog>

#include "FeeDialog.h"
#include "ui_mainwindow.h"
#include "../core/Car.h"

MainWindow* MainWindow::instance = nullptr;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    parkPic = QPixmap("img/park.jpg");
    carPic = QPixmap("img/car.jpg");
    dbHandler.openDatabase();
    connect(this, &MainWindow::requestAddCarDisplay, this, &MainWindow::addCarDisplay);
    connect(this, &MainWindow::requestRemoveCarDisplay, this, &MainWindow::removeCarDisplay);
    connect(this,&MainWindow::requestAddRecord,this,&MainWindow::addRecord);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_entry1AddButton_clicked() {
    if (started) {
        Car car;
        if (entry1->addCar(car)) {
            ui->entry1Display->setText(QString::number(entry1->getSize()));
        }
    }
}

void MainWindow::on_entry2AddButton_clicked() {
    if (started) {
        Car car;
        if (entry2->addCar(car)) {
            ui->entry2Display->setText(QString::number(entry2->getSize()));
        }
    }
}

void MainWindow::on_startAction_triggered() {
    if (!started) {
        ui->spinBox->setReadOnly(true);
        capacity = ui->spinBox->text().toInt();
        entry1 = new Entry(QString("入口1"),capacity);
        entry2 = new Entry(QString("入口2"),capacity);
        exit1 = new Exit(QString("出口1"),capacity);
        exit2 = new Exit(QString("出口2"),capacity);
        ui->lineDate->setText(QDateTime::currentDateTime().date().toString());
        ui->lineTime->setText(QDateTime::currentDateTime().time().toString());
        started = true;
        entry1->start();
        entry2->start();
        exit1->start();
        exit2->start();
        startTimer();
        initGraphics();
    }
}

void MainWindow::on_stopAction_triggered() {
    started = false;
    ui->spinBox->setReadOnly(false);
    QGraphicsScene* scene = ui->parkView->scene();
    if (scene) {
        scene->clear();
    }
    QFile log("log.txt");
    if (!log.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing:" << log.errorString();
    }
    QTextStream out(&log);
    out << ui->entryMsgArea->toPlainText() << Qt::endl;
    out << ui->exitMsgArea->toPlainText() << Qt::endl;
    log.close();
    ui->entryMsgArea->clear();
    ui->exitMsgArea->clear();
    entry1->terminate();
    entry2->terminate();
    exit1->terminate();
    exit2->terminate();
    timer->stop();
}

inline void MainWindow::startTimer() {
    timer = new QTimer();
    connect(timer, &QTimer::timeout, [&] {
        auto now = QTime::currentTime();
        ui->lineEmptySlots->setText(QString::number(12-carSlots.size()));
        ui->lineTime->setText(now.toString());
        if (carSlots.full()) {
            isFull = true;
        } else {
            isFull = false;
            fullWait.wakeOne();
        }
        // 处理
        if (!carSlots.empty()) {
            auto firstKey = carSlots.firstKey();
            // ui->exitMsgArea->append(QString("firstKey:").append(firstKey.toString()));
            auto nowToFirst = now.secsTo(firstKey);
            // ui->exitMsgArea->append(QString("nowToFirst:").append(QString::number(nowToFirst)));
            if (nowToFirst <= 0) {
                auto car = carSlots.get(firstKey);
                QRandomGenerator *generator = QRandomGenerator::global(); // 获取全局随机数生成器
                int exitChoice = generator->bounded(2); // 生成0或1
                if (exitChoice == 0) {
                    if (!exit1->full()) {
                    exit1->putCar(car);
                    exitMsg(QString("向[出口1]发送车 ").append(car.name));
                    } else {
                        exit2->putCar(car);
                        exitMsg(QString("向[出口2]发送车 ").append(car.name));
                    }
                } else {
                    if (!exit2->full()) {
                        exit2->putCar(car);
                        exitMsg(QString("向[出口2]发送车 ").append(car.name));
                    } else {
                        exit1->putCar(car);
                        exitMsg(QString("向[出口1]发送车 ").append(car.name));
                    }
                }
                carSlots.erase(firstKey);
                emit requestRemoveCarDisplay(car);
            }
        }
    });
    timer->start(1000);
}

void MainWindow::insertCar(Car car) {
    QMutexLocker locker(&mutex);
    auto key = car.inParkTime.addSecs(car.intendedSecs);
    car.inParkTime = QTime::currentTime();
    try {
        carSlots.insert(key, car);
        emit requestAddCarDisplay(car);
    } catch (std::exception& e) {}
}

float MainWindow::calculateFee(int seconds) {
    auto feeUnit = seconds / 15;
    return feeUnit * 1.5f;
}

void MainWindow::updateExit(const QString& threadName, const Car& car) {
    QMutexLocker locker(&mutex);
    ui->lineOutCar->setText(car.name);
    auto now = QTime::currentTime();
    int seconds = car.inParkTime.secsTo(now);
    ui->lineParkTime->setText(QString::number(seconds).append("秒"));
    auto fee = calculateFee(seconds);
    ui->lineFee->setText(QString::number(fee).append("元"));
    auto message = QString("[%1]: %2 在 %3 离开停车场, 收费 %4")
      .arg(threadName)
      .arg(car.name)
      .arg(QTime::currentTime().toString())
      .arg(fee);
    exitMsg(message);
    emit requestAddRecord(car,now,fee);
}

inline void MainWindow::initGraphics() {
    scene = new QGraphicsScene(ui->parkView);
    ui->parkView->setScene(scene);
    scene->setBackgroundBrush(Qt::lightGray);
    scene->setSceneRect(QRect(0, 0, 600, 400));
    scene->addPixmap(parkPic);
    std::fill(std::begin(carItems), std::end(carItems), nullptr);
    std::fill(std::begin(carText), std::end(carText), nullptr);
}

inline void MainWindow::addCarDisplay(const Car& car) {
    QMutexLocker locker(&displayMutex);
    QVector<int> availableKeys;
    availableKeys.clear();
    for (int i = 0; i < 12; i++) {
        if (carItems[i] == nullptr) {
            availableKeys.push_back(i);
        }
    }
    int index = QRandomGenerator::global()->bounded(availableKeys.size());
    int i = availableKeys[index];
    int x,y;
    if (i < 3) {
        x = 85 + i * 70;
    } else if (i < 6) {
        x = 110 + i * 70;
    } else if (i < 9) {
        x = 85 + (i-6) * 70;
    } else {
        x = 110 + (i-6) * 70;
    }
    i < 6 ? y = 20 : y = 265;
    carItems[i] = scene->addPixmap(carPic);
    carItems[i]->setPos(x, y);
    auto text = scene->addText(car.name);
    text->setFont(font);
    text->setDefaultTextColor(Qt::white);
    text->setPos(x, y);
    carText[i] = text;
    locker.unlock();
}

inline void MainWindow::removeCarDisplay(const Car& car) {
    QMutexLocker locker(&displayMutex);
    for (int i = 0; i < 12; i++) {
        if (carItems[i] != nullptr && carText[i] != nullptr && carText[i]->toPlainText() == car.name) {
            scene->removeItem(carItems[i]);
            delete carItems[i];
            carItems[i] = nullptr;
            scene->removeItem(carText[i]);
            delete carText[i];
            carText[i] = nullptr;
            locker.unlock();
            break;
        }
    }
}

void MainWindow::addRecord(const Car &car, const QTime outTime, const float fee) {
    dbHandler.insertRecord(car.inParkTime.toString(), car.name, outTime.toString(), fee);
}

void MainWindow::on_feeAction_triggered() {
    if (started) {
        QMessageBox::warning(this,"警告","请在终止模拟后方可统计！");
        return;
    }
    QVector<float> fees = dbHandler.getAllFees();
    auto feeDialog = new FeeDialog(fees);
    feeDialog->exec();
}

void MainWindow::on_historyFeeAction_triggered() {
    if (started) {
        QMessageBox::warning(this,"警告","请在终止模拟后方可统计！");
        return;
    }
    auto time = QInputDialog::getText(this, tr("表名"),tr("请以yyyy_mm_dd_hh_mm_ss的格式键入你想查询的历史记录："));
    if (time.isEmpty()) return;
    QVector<float> fees = dbHandler.getAllFees(time);
    auto feeDialog = new FeeDialog(fees);
    feeDialog->exec();
}
