#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../data/Calculator.h"
#include "HistoryWindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    updateText();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_num0Button_clicked() {
    display.push_back("0");
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    operandTyped = false;
    preIsNum = true;
}

void MainWindow::on_num1Button_clicked() {
    display.push_back('1');
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    operandTyped = false;
    preIsNum = true;
}

void MainWindow::on_num2Button_clicked() {
    display.push_back('2');
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    operandTyped = false;
    preIsNum = true;
}

void MainWindow::on_num3Button_clicked() {
    display.push_back('3');
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    operandTyped = false;
    preIsNum = true;
}

void MainWindow::on_num4Button_clicked() {
    display.push_back('4');
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    operandTyped = false;
    preIsNum = true;
}

void MainWindow::on_num5Button_clicked() {
    display.push_back('5');
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    operandTyped = false;
    preIsNum = true;
}

void MainWindow::on_num6Button_clicked() {
    display.push_back('6');
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    operandTyped = false;
    preIsNum = true;
}

void MainWindow::on_num7Button_clicked() {
    display.push_back('7');
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    operandTyped = false;
    preIsNum = true;
}

void MainWindow::on_num8Button_clicked() {
    display.push_back('8');
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    operandTyped = false;
    preIsNum = true;
}

void MainWindow::on_num9Button_clicked() {
    display.push_back('9');
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    operandTyped = false;
    preIsNum = true;
}

void MainWindow::on_addButton_clicked() {
    if (!operandTyped) {
        display.push_back("+");
        operandTyped = true;
    } else {
        display.chop(1);
        display.push_back('+');
    }
    isPosTyped = true;
    preIsDot = false;
    preIsRightBracket = false;
    updateText();
}

void MainWindow::on_minusButton_clicked() {
    if (isPosTyped && operandTyped) {
        display.chop(1);
        display.push_back('-');
    } else if (!isNegTyped) {
        display.push_back("-");
    }
    isNegTyped = true;
    operandTyped = true;
    preIsDot = false;
    preIsRightBracket = false;
    updateText();
}

void MainWindow::on_crossButton_clicked() {
    if (!operandTyped) {
        display.push_back("*");
        operandTyped = true;
    } else {
        display.chop(1);
        display.push_back('*');
    }
    isPosTyped = false;
    isNegTyped = false;
    preIsDot = false;
    preIsRightBracket = false;
    updateText();
}

void MainWindow::on_divButton_clicked() {
    if (!operandTyped) {
        display.push_back("/");
    } else {
        display.chop(1);
        display.push_back('/');
    }
    isPosTyped = false;
    isNegTyped = false;
    preIsDot = false;
    preIsRightBracket = false;
    updateText();
}

void MainWindow::on_equalButton_clicked() {
    display.push_back("=");
    try {
        Calculator::calculate(&display,this);
    } catch (const std::exception& e) {
        QMessageBox::critical(this,"输入错误",QString("请检查输入是否符合规范！"));
        on_clearButton_clicked();
    }
    historyList << display;
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    preIsDot = false;
    preIsRightBracket = false;
    operandTyped = false;
}

void MainWindow::on_dotButton_clicked() {
    if (!operandTyped && !preIsDot) {
        display.push_back(".");
        updateText();
        isPosTyped = false;
        isNegTyped = false;
        operandTyped = true;
        preIsDot = true;
    }
}

void MainWindow::on_clearButton_clicked() {
    display.clear();
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    operandTyped = false;
    preIsDot = false;
    preIsRightBracket = false;
}

void MainWindow::on_backspaceButton_clicked() {
    display.chop(1);
    updateText();
    operandTyped = false;
    isPosTyped = false;
    isNegTyped = false;
}

void MainWindow::on_pow2Button_clicked() {
    if (preIsNum) {
        display.push_back("^2");
        isPosTyped = false;
        isNegTyped = false;
        updateText();
    }
}

void MainWindow::on_sqrtButton_clicked() {
    if (preIsNum) {
        display.push_back("^0.5");
        isPosTyped = false;
        isNegTyped = false;
        updateText();
    }
}

void MainWindow::on_reciprocalButton_clicked() {
    if (preIsNum) {
        display.push_back("^(-1)");
        isPosTyped = false;
        isNegTyped = false;
        updateText();
    }
}

void MainWindow::on_leftBracketButton_clicked() {
    if (!preIsRightBracket) {
        display.push_back("(");
        isPosTyped = false;
        isNegTyped = false;
        updateText();
    }
}

void MainWindow::on_rightBracketButton_clicked() {
    display.push_back(")");
    updateText();
    isPosTyped = false;
    isNegTyped = false;
    preIsRightBracket = true;
}

void MainWindow::on_action234_triggered() {
    auto *historyWindow = new HistoryWindow(historyList, this);
    historyWindow->exec();
}
