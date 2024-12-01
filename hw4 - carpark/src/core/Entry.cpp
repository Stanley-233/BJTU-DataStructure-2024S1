//
// Created by stanl on 24-10-17.
//

#include "Entry.h"

#include <QRandomGenerator>

#include "../ui/mainwindow.h"

[[noreturn]] void Entry::run() {
    while (true) {
        QMutexLocker locker(&mutex);
        if (!cars.empty()) {
            Car car = cars.deque();
            // 满的时候在insertCar阻塞；MainWindow的Timer更新是否为满的判断，如果为满，在MainWindow里面唤醒线程重新竞争入库
            auto randomSleep = QRandomGenerator::global()->bounded(100);
            msleep(randomSleep);
            while (MainWindow::getInstance()->isFull) {
                MainWindow::getInstance()->fullWait.wait(&mutex);
            }
            MainWindow::getInstance()->insertCar(car);
            car.inParkTime = QTime::currentTime();
            auto key = car.inParkTime.addSecs(car.intendedSecs);
            QString message = QString("[%1]: %2 在 %3 进入停车场，将在 [%4] 离开")
                  .arg(name)
                  .arg(car.name)
                  .arg(QTime::currentTime().toString())
                  .arg(key.toString());
            MainWindow::getInstance()->entryMsg(car,message);
            MainWindow::getInstance()->updateEntry();
        }
        locker.unlock();
        sleep(3);
    }
}

bool Entry::addCar(Car& out) {
    QMutexLocker locker(&mutex);
    if (cars.getSize() != capacity) {
        out = Car(Car::generatePlate(), QTime::currentTime(), Car::generateTime());
        cars.enque(out);
        return true;
    }
    return false;
}
