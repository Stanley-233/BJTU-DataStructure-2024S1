//
// Created by stanl on 24-9-27.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <qstring.h>
#include <QWidget>

class Calculator {
public:
    static double operate(double left, const QString& operand, double right,QWidget*);
    static void calculate(QString*,QWidget*);
};


#endif //CALCULATOR_H
