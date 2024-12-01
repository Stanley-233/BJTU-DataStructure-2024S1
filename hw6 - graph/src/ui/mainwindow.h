#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMessageBox>
#include <QTextToSpeech>
#include <QVoice>

#include "../data/Graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Graph graph = Graph();
    std::vector<QGraphicsItem*> paths;
    std::vector<QGraphicsTextItem*> pathLengths;
    QTextToSpeech *speech;
    QGraphicsPixmapItem* syItem;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadButton_clicked();
    void on_startInfoButton_clicked();
    void on_allRoutesButton_clicked();
    void on_twoShortPathButton_clicked();
    void on_multiShortPathButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
