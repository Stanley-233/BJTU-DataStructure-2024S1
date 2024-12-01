#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWaitCondition>
#include <QGraphicsItem>

#include "ui_mainwindow.h"
#include "../core/Core.h"
#include "../data/DataBase.h"
#include "../data/MapWithLimit.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    static MainWindow* getInstance() {
        if (!instance) {
            instance = new MainWindow();
        }
        return instance;
    }
    // 删除拷贝构造函数和赋值操作符
    MainWindow(const MainWindow&) = delete;
    MainWindow& operator=(const MainWindow&) = delete;

private:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow* instance; // 静态指针

signals:
    void requestAddCarDisplay(Car car);
    void requestRemoveCarDisplay(Car car);
    void requestAddRecord(Car, QTime outTime, float fee);

private slots:
    inline void addCarDisplay(const Car& car);
    inline void removeCarDisplay(const Car& car);
    inline void addRecord(const Car& car, QTime outTime, float fee);

public slots:
    void on_entry1AddButton_clicked();
    void on_entry2AddButton_clicked();
    void on_startAction_triggered();
    void on_stopAction_triggered();
    void on_feeAction_triggered();
    void on_historyFeeAction_triggered();

private:
    QPixmap carPic;
    QPixmap parkPic;
    QTimer *timer;
    QGraphicsScene* scene;
    QGraphicsItem* carItems[12];
    QGraphicsTextItem* carText[12];
    DataBase dbHandler;
    QFont font = QFont("Arial", 9);
    bool started = false;
    QMutex mutex;
    QMutex entryMsgMutex;
    QMutex exitMsgMutex;
    QMutex displayMutex;
    MapWithLimit<QTime, Car> carSlots = MapWithLimit<QTime,Car>(12);
    int capacity;
    Entry* entry1 = nullptr;
    Entry* entry2 = nullptr;
    Exit* exit1 = nullptr;
    Exit* exit2 = nullptr;
    inline void startTimer();
    inline void initGraphics();

public:
    Ui::MainWindow *ui;
    bool isFull = false;
    QWaitCondition fullWait;
    void entryMsg(const Car& car, QString msg) {
        QMutexLocker locker(&entryMsgMutex);
        ui->entryMsgArea->append(msg);
        ui->lineEntryName->setText(car.name);
        ui->lineEntryTime->setText(car.inParkTime.toString());
    }
    void updateEntry() {
        ui->entry1Display->setText(QString::number(entry1->getSize()));
        ui->entry2Display->setText(QString::number(entry2->getSize()));
    }
    void exitMsg(QString msg) {
        QMutexLocker locker(&exitMsgMutex);
        ui->exitMsgArea->append(msg);
    }
    void updateExit(const QString& threadName, const Car& car);
    void insertCar(Car car);
    static float calculateFee(int seconds);
};
#endif // MAINWINDOW_H
