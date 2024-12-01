#include "ui/mainwindow.h"

#include <QApplication>
#include <QPushButton>
#include <iostream>

int main(int argc, char *argv[])
{
    try {
        loop:
        QApplication a(argc, argv);
        auto w = MainWindow::getInstance();
        w->show();
        return a.exec();
    } catch (const std::exception &e) {
        qDebug() << QString(e.what());
        goto loop;
    }
    // std::map<QTime, std::string> timeMap;
    //
    // // 插入元素
    // timeMap.insert({QTime(10, 30), "Meeting"});
    // timeMap.insert({QTime(9, 15), "Breakfast"});
    // timeMap.insert({QTime(13, 0), "Lunch"});
    // timeMap.insert({QTime(8, 0), "Gym"});
    //
    // // 输出有序的元素
    // for (const auto& pair : timeMap) {
    //     std::cout << pair.first.toString().toStdString() << ": " << pair.second << std::endl;
    // }
    //
    // return 0;
}
