#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../data/Database.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    speech = new QTextToSpeech(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked() {
    auto db = Database();
    graph = Graph(db.loadSpots(),db.loadRoutes());
    auto scene = new QGraphicsScene(ui->graphicsView);
    scene->setSceneRect(0,0,750,500);
    QPixmap spots(":/imgs/spots.png");
    scene->addPixmap(spots);
    QPen pen(Qt::black,2);
    for (int i = 0; i < graph.routes.size(); i += 2) {
        int startx = graph.routes[i].startx;
        int starty = graph.routes[i].starty;
        int endx = graph.routes[i].endx;
        int endy = graph.routes[i].endy;
        QGraphicsLineItem* line = scene->addLine(startx, starty, endx, endy, pen);
        line->setVisible(true);
        paths.emplace_back(line);
        QGraphicsTextItem *textItem = scene->addText(QString::number(graph.routes[i].length).append("m"));
        textItem->setPos((startx+endx)/2.0 - 16, (starty+endy)/2.0 - 10);
        textItem->setFont(QFont("Arial", 10));
        textItem->setDefaultTextColor(Qt::black);
        pathLengths.emplace_back(textItem);
    }
    ui->graphicsView->setScene(scene);
    #ifdef __ANDROID__
        ui->graphicsView->scale(0.75,0.75);
    #endif
    ui->loadButton->setDisabled(true);
}

void MainWindow::on_startInfoButton_clicked() {
    ui->msgArea->clear();
    int index = ui->startIndex->text().toInt() - 1;
    int id = graph.spots[index].id + 1;
    QString name = graph.spots[index].name;
    QString info = graph.spots[index].info;
    ui->msgArea->appendPlainText(QString("景点编号：").append(QString::number(id)));
    ui->msgArea->appendPlainText(QString("名称：").append(name));
    ui->msgArea->appendPlainText(QString("景点介绍：").append(info));
    if (id == 1) {
        QPixmap sy(":/imgs/sy.jpg");
        syItem = ui->graphicsView->scene()->addPixmap(sy);
        syItem->setPos(300,150);
        syItem->setScale(0.25);
        syItem->setVisible(true);
    } else {
        syItem->setVisible(false);
    }
    speech->say(ui->msgArea->toPlainText());
}

void MainWindow::on_allRoutesButton_clicked() {
    syItem->setVisible(false);
    ui->msgArea->clear();
    int begin = ui->startIndex->text().toInt() - 1;
    std::vector<int> routes = graph.traverse_all_spots(begin);
    for (int i = 0; i < paths.size(); i++) {
        paths[i]->setVisible(false);
        pathLengths[i]->setVisible(false);
    }
    for (int & route : routes) {
        if (route < 0) route += 20;
        QString msg = QString("路径 ID: %1 - %2").arg(route).arg(graph.routes[route*2].info);
        ui->msgArea->appendPlainText(msg);
        paths[route]->setVisible(true);
        pathLengths[route]->setVisible(true);
    }
}

void MainWindow::on_twoShortPathButton_clicked() {
    syItem->setVisible(false);
    ui->msgArea->clear();
    int begin = ui->startIndex->text().toInt() - 1;
    int end = ui->endIndex->text().toInt() - 1;
    if (begin == end) {
        QMessageBox::critical(this,tr("错误"),tr("起始点不可与终点相同!"));
        return;
    }
    std::vector<int> routes = graph.shortest_path(begin,end);
    for (int i = 0; i < paths.size(); i++) {
        paths[i]->setVisible(false);
        pathLengths[i]->setVisible(false);
    }
    int total = 0;
    for (int & route : routes) {
        if (route < 0) route += 20;
        QString msg = QString("%1").arg(graph.routes[route*2].info);
        total += graph.routes[route*2].length;
        ui->msgArea->appendPlainText(msg);
        paths[route]->setVisible(true);
        pathLengths[route]->setVisible(true);
    }
    ui->msgArea->appendPlainText(QString("总路程：%1m").arg(total));
}

void MainWindow::on_multiShortPathButton_clicked() {
    syItem->setVisible(false);
    for (int i = 0; i < paths.size(); i++) {
        paths[i]->setVisible(true);
        pathLengths[i]->setVisible(true);
    }
}
