#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "../data/Stack.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void on_num0Button_clicked();
    void on_num1Button_clicked();
    void on_num2Button_clicked();
    void on_num3Button_clicked();
    void on_num4Button_clicked();
    void on_num5Button_clicked();
    void on_num6Button_clicked();
    void on_num7Button_clicked();
    void on_num8Button_clicked();
    void on_num9Button_clicked();
    void on_addButton_clicked();
    void on_minusButton_clicked();
    void on_crossButton_clicked();
    void on_divButton_clicked();
    void on_equalButton_clicked();
    void on_dotButton_clicked();
    void on_clearButton_clicked();
    void on_backspaceButton_clicked();
    void on_pow2Button_clicked();
    void on_sqrtButton_clicked();
    void on_reciprocalButton_clicked();
    void on_leftBracketButton_clicked();
    void on_rightBracketButton_clicked();
    void on_action234_triggered();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void historyUpdateText(QString str) {
        ui->textDisplay->setText(str);
    }
    void clearDisplay() {
        ui->textDisplay->clear();
    };

private:
    QString display;
    Ui::MainWindow *ui;
    bool operandTyped = false;
    bool preIsRightBracket = false;
    bool preIsDot = false;
    bool isPosTyped = false;
    bool isNegTyped = false;
    bool preIsNum = false;
    QStringList historyList;
    void updateText() {
        ui->textDisplay->setText(display);
    }
};
#endif // MAINWINDOW_H
