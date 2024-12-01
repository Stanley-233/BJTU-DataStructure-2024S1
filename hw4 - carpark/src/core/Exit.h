//
// Created by stanl on 24-10-17.
//

#ifndef EXIT_H
#define EXIT_H

#include <QMutex>
#include <QThread>

#include "Car.h"
#include "../data/Queue.h"

class Exit : public QThread {
    Q_OBJECT
    // Consumer
    QString name;
    int capacity;
    Queue<Car> cars;
    QMutex mutex;

public:
    explicit Exit(QString name, int cap) : name(name), capacity(cap), cars(Queue<Car>(cap)) {}
    void run() override;

    void putCar(Car car);

    int getSize() const {
        return cars.getSize();
    }

    bool full() const {
        return getSize() == capacity;
    }
};



#endif //EXIT_H
