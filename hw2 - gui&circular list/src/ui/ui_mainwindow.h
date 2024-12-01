/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *keyText;
    QLabel *keyLabel;
    QTextEdit *numText;
    QLabel *numLabel;
    QPushButton *startButton;
    QGraphicsView *mainArea;
    QGraphicsView *outArea;
    QPushButton *calButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 872);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        keyText = new QTextEdit(centralwidget);
        keyText->setObjectName("keyText");
        keyText->setGeometry(QRect(480, 20, 111, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(12);
        keyText->setFont(font);
        keyLabel = new QLabel(centralwidget);
        keyLabel->setObjectName("keyLabel");
        keyLabel->setGeometry(QRect(370, 20, 81, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(10);
        keyLabel->setFont(font1);
        numText = new QTextEdit(centralwidget);
        numText->setObjectName("numText");
        numText->setGeometry(QRect(150, 20, 121, 41));
        numText->setFont(font);
        numLabel = new QLabel(centralwidget);
        numLabel->setObjectName("numLabel");
        numLabel->setGeometry(QRect(60, 20, 81, 41));
        numLabel->setFont(font1);
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(660, 20, 91, 41));
        QFont font2;
        font2.setPointSize(10);
        startButton->setFont(font2);
        mainArea = new QGraphicsView(centralwidget);
        mainArea->setObjectName("mainArea");
        mainArea->setGeometry(QRect(30, 80, 841, 611));
        outArea = new QGraphicsView(centralwidget);
        outArea->setObjectName("outArea");
        outArea->setGeometry(QRect(30, 720, 841, 111));
        calButton = new QPushButton(centralwidget);
        calButton->setObjectName("calButton");
        calButton->setGeometry(QRect(780, 20, 91, 41));
        calButton->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\214\264\345\255\220\351\200\211\345\244\247\347\216\213 -\350\265\265\345\212\261\346\201\222", nullptr));
        keyLabel->setText(QCoreApplication::translate("MainWindow", "\345\207\272\345\210\227\347\274\226\345\217\267", nullptr));
        numLabel->setText(QCoreApplication::translate("MainWindow", "\347\214\264\345\255\220\346\200\273\346\225\260", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        calButton->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
