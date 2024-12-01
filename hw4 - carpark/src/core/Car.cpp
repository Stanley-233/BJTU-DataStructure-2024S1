//
// Created by stanl on 24-10-11.
//

#include "Car.h"

#include <QString>
#include <QVector>
#include <QRandomGenerator>

Car::Car(QString name, QTime inTime, int parkTime) {
    this->name = name;
    this->inParkTime = inTime;
    this->intendedSecs = parkTime;
}

QString Car::generatePlate() {
    QVector<QString> provinces = {
        "京", "沪", "粤", "苏", "浙", "鲁", "晋", "川", "鄂", "冀",
        "豫", "辽", "黑", "湘", "赣", "闽", "桂", "贵", "青",
        "藏", "宁", "新", "港", "澳", "台"
    };
    QRandomGenerator *gen = QRandomGenerator::global();
    // 省份前缀
    QString plate = provinces[gen->bounded(provinces.size())];
    char letter = 'A' + gen->bounded(26);
    plate += letter;
    // 数字和字母部分
    for (int i = 0; i < 5; ++i) {
        if (gen->bounded(2)) {
            char digit = '0' + gen->bounded(10);
            plate += digit;
        } else {
            char letter1 = 'A' + gen->bounded(26);
            plate += letter1;
        }
    }
    return plate;
}

int Car::generateTime() {
    QRandomGenerator *gen = QRandomGenerator::global();
    int seconds = gen->bounded(20, 81); //上限不包括81
    return seconds;
}
