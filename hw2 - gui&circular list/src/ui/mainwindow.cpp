#include <iostream>
#include <QMessageBox>
#include <QGraphicsPixmapItem>

#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "../data/LoopList.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    memset(data,-1,sizeof(data));
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::on_startButton_clicked);
    connect(ui->calButton, &QPushButton::clicked, this, &MainWindow::on_calButton_clicked);
    this->setFixedSize(width(),height());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_startButton_clicked() {
    memset(data,-1,sizeof(data));
    bool ok1,ok2;
    int num = ui->numText->toPlainText().toInt(&ok1);
    int key = ui->keyText->toPlainText().toInt(&ok2);
    if (ok1 && ok2 && num >= key && num >= 3) {
        auto outScene = new QGraphicsScene(ui->outArea);
        outScene->setBackgroundBrush(Qt::lightGray);
        outScene->setSceneRect(0,0,1,1);
        ui->outArea->setScene(outScene);

        size = num;
        LoopList list(num);
        result = list.solveRing(key,data);
        auto scene = new QGraphicsScene(ui->mainArea);
        ui->mainArea->setScene(scene);
        scene->setBackgroundBrush(Qt::lightGray);
        scene->setSceneRect(0,0,(num/2)*160+200,500);
        QPixmap monkey("img/monkey.png");
        QGraphicsPixmapItem *monkeys[100];
        int curX = 50, curY = 50;
        int i = 0;
        QPen pen(Qt::red, 2);
        if (num % 2 == 0) {
            scene->addRect(100,100,(num/2-1)*150,200,pen);
        } else {
            scene->addRect(100,100,(num/2)*150,200,pen);
        }

        for (i = 0; i < num / 2; ++i) {
            monkeys[i] = scene->addPixmap(monkey);
            monkeys[i]->setPos(curX,curY);
            monkeys[i]->setScale(0.5);
            auto textItem = scene->addText(QString::number(i+1), QFont("Arial", 12));
            textItem->setPos(curX,curY);
            curX += 150;
        }
        if (num % 2 == 0) {
            curX -= 150;
        }
        curY += 200;
        // Arrow
        QPolygon triangle1;
        triangle1 << QPoint(curX+50,curY-30) << QPoint(curX+40,curY-40) << QPoint(curX+60,curY-40);
        auto triangle1Item = new QGraphicsPolygonItem(triangle1);
        triangle1Item->setBrush(Qt::red);
        triangle1Item->setPen(pen);
        scene->addItem(triangle1Item);
        QPolygon triangle2;
        triangle2 << QPoint(100,curY-50) << QPoint(90,curY-40) << QPoint(110,curY-40);
        auto triangle2Item = new QGraphicsPolygonItem(triangle2);
        triangle2Item->setBrush(Qt::red);
        triangle2Item->setPen(pen);
        scene->addItem(triangle2Item);

        for (; i < num; ++i) {
            monkeys[i] = scene->addPixmap(monkey);
            monkeys[i]->setPos(curX,curY);
            monkeys[i]->setScale(0.5);
            auto textItem = scene->addText(QString::number(i+1), QFont("Arial", 12));
            textItem->setPos(curX,curY);
            curX -= 150;
        }
        start_clicked = true;
    } else {
        QMessageBox::critical(this,"错误","输入不合法：\n1.猴子数目至少为3\n2.在两个输入框都输入后再单击按钮\n3.出列序号必须小于猴子数");
    }
}

void MainWindow::on_calButton_clicked() {
    if (!start_clicked) {
        QMessageBox::critical(this,"错误","未初始化数据！");
    }
    // 大王
    auto mainScene = new QGraphicsScene(ui->mainArea);
    ui->mainArea->setScene(mainScene);
    mainScene->setBackgroundBrush(Qt::lightGray);
    mainScene->setSceneRect(0,0,500,500);
    QPixmap king("img/king.png");
    auto kingItem = mainScene->addPixmap(king);
    kingItem->setScale(2);
    auto kingTextItem = mainScene->addText(QString::number(result), QFont("Arial", 18));
    kingTextItem->setPos(kingItem->pos().x(),kingItem->pos().y());
    // 出列顺序
    auto outScene = new QGraphicsScene(ui->outArea);
    ui->outArea->setScene(outScene);
    outScene->setBackgroundBrush(Qt::lightGray);
    outScene->setSceneRect(0,0,(size-1)*100,100);
    QPixmap monkey("img/monkey.png");
    QGraphicsPixmapItem *monkeys[100];
    int i = 0;
    while (data[i] != -1) {
        monkeys[i] = outScene->addPixmap(monkey);
        monkeys[i]->setPos(i*100,0);
        monkeys[i]->setScale(0.4);
        auto outTextItem = outScene->addText(QString::number(data[i]), QFont("Arial", 12));
        outTextItem->setPos(i*100,0);
        i++;
    }
}