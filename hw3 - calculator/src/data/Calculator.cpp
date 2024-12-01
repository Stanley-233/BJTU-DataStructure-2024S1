//
// Created by stanl on 24-9-27.
//

#include "Calculator.h"

#include <QMessageBox>

#include "Stack.h"

void Calculator::calculate(QString* display, QWidget *parent) {
    // 解析表达式
    QString number;
    std::vector<QString> inputs;
    for (auto i : *display) {
        if (i == '.') {
            number.append(i);
        } else {
            if (!i.isNumber()) {
                // 是操作符的情况
                if (number.isEmpty()) {
                    if (i == '=') {
                        inputs.emplace_back("#");
                    } else {
                        inputs.emplace_back(i);
                    }
                } else {
                    inputs.emplace_back(number);
                    inputs.emplace_back(i);
                    number.clear();
                }
            } else {
                // 是数字的情况
                number.append(i);
            }
        }
    }
    // 计算
    std::map<QString,int> precedence;
    precedence["("] = 1;
    precedence[")"] = 5;
    precedence["+"] = 2;
    precedence["-"] = 2;
    precedence["*"] = 3;
    precedence["/"] = 3;
    precedence["^"] = 4;
    precedence["#"] = 0;
    precedence["="] = 0;
    Stack<double> OPND;
    Stack<QString> OPTR;
    OPTR.push(QString("#"));
    bool hasOperandBefore = false;
    for (int i = 0; i < inputs.size(); i++) {
        const auto& input = inputs.at(i);
        // QMessageBox::information(this,"Operation",input);
        bool ok = false;
        double num = input.toDouble(&ok);
        if (ok) {
            OPND.push(num);
            hasOperandBefore = false;
        } else {
            // 是运算符
            int precedenceNow = precedence[input];
            int precedenceTop = precedence[OPTR.getTop()];
            // 前面有符号，即负数、左括号的情况
            if (hasOperandBefore) {
                if (precedenceNow == 2) {
                    // 负号
                    i++;
                    const auto& next = inputs.at(i);
                    num = next.toDouble(&ok);
                    num = -num;
                    OPND.push(num);
                } else if (precedenceNow == 1) {
                    // 左括号直接入栈
                    OPTR.push(input);
                    hasOperandBefore = true;
                } else if (precedenceNow == 5) {
                    OPTR.pop();
                    hasOperandBefore = false;
                } else {
                    OPTR.push(input);
                }
            }
            else {
                if (precedenceNow == 1) {
                    // 左括号直接入栈
                    OPTR.push(input);
                    hasOperandBefore = true;
                } else {
                    if (precedenceNow >= precedenceTop) {
                        if (precedenceNow == 5) {
                            auto top = OPTR.pop();
                            precedenceTop = precedence[top];
                            // 不是左括号时执行循环
                            while (precedenceTop != 1) {
                                double right = OPND.pop();
                                double left = OPND.pop();
                                OPND.push(operate(left,top,right,parent));
                                top = OPTR.pop();
                                precedenceTop = precedence[top];
                            }
                            hasOperandBefore = false;
                        } else {
                            OPTR.push(input);
                            hasOperandBefore = true;
                        }
                    } else if (precedenceNow < precedenceTop) {
                        double right = OPND.pop();
                        double left = OPND.pop();
                        QString operand = OPTR.pop();
                        OPND.push(operate(left,operand,right,parent));
                        if (precedenceNow != 0) i--;
                    }
                }
            }
        }
    }
    while (OPND.getSize() != 1) {
        // 输入串末尾为#，OPTR内每个元素必定优先级高
        int precedenceTop = precedence[OPTR.getTop()];
        if (precedenceTop == 1) {
            // 脱括号
            OPTR.pop();
        }
        double right = OPND.pop();
        double left = OPND.pop();
        QString operand = OPTR.pop();
        OPND.push(operate(left,operand,right,parent));
    }
    display->append(QString::number(OPND.getTop()));
}


double Calculator::operate(double left, const QString& operand, double right, QWidget *parent) {
    // QMessageBox::information(this,"Operation",operand);
    if (operand == "+") {
        return left + right;
    } if (operand == "-") {
        return left - right;
    } if (operand == "*") {
        return left * right;
    } if (operand == "/") {
        if (right == 0.0) QMessageBox::critical(parent,"数学错误","0不可作除数");
        return left / right;
    } if (operand == "^") {
        return pow(left,right);
    }
}
