//
// Created by stanl on 24-10-17.
//

#ifndef ENTRY_H
#define ENTRY_H

#include "Car.h"
#include "../data/Queue.h"

#include <QMutex>
#include <QThread>
// class Entry : QThread {
//     // Producer
//     int capacity;
//     Queue<Car> cars;
//     QMutex mutex
// public:
//     Entry(int cap);
//     void run() override;
//     [[nodiscard]] bool addCar();
//     [[nodiscard]] int getSize() const {
//         return cars.getSize();
//     }
// };

class Entry : public QThread { // 继承 QThread
    Q_OBJECT
    QString name;
    int capacity;
    Queue<Car> cars;
    QMutex mutex;

public:
    Entry(QString name, int cap) : name(name), capacity(cap), cars(Queue<Car>(cap)) {}

    void run() override;

    bool addCar(Car& out);

    int getSize() const {
        return cars.getSize();
    }
};

#endif //ENTRY_H
