//
// Created by stanl on 24-10-17.
//

#include "Exit.h"

#include "../ui/mainwindow.h"

[[noreturn]] void Exit::run() {
    while(true) {
        QMutexLocker lock(&mutex);
        if (!cars.empty()) {
            Car car = cars.deque();
            MainWindow::getInstance()->updateExit(name, car);
        }
        lock.unlock();
        sleep(5);
    }
}

void Exit::putCar(Car car) {
    QMutexLocker lock(&mutex);
    cars.enque(car);
}
