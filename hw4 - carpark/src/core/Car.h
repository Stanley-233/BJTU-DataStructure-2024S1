//
// Created by stanl on 24-10-11.
//

#ifndef CAR_H
#define CAR_H

#include <qdatetime.h>

class Car {
public:
    QString name;
    QTime inParkTime;
    int intendedSecs;
    Car(){}
    explicit Car(QString, QTime, int);
    static QString generatePlate();
    static int generateTime();
};

#endif //CAR_H
