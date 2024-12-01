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
#include <QtGui/QActionEvent>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action234;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textDisplay;
    QGridLayout *buttonsLayout;
    QPushButton *crossButton;
    QPushButton *equalButton;
    QPushButton *num5Button;
    QPushButton *num8Button;
    QPushButton *num6Button;
    QPushButton *num1Button;
    QPushButton *num4Button;
    QPushButton *pow2Button;
    QPushButton *addButton;
    QPushButton *sqrtButton;
    QPushButton *dotButton;
    QPushButton *clearButton;
    QPushButton *num2Button;
    QPushButton *reciprocalButton;
    QPushButton *backspaceButton;
    QPushButton *num7Button;
    QPushButton *num9Button;
    QPushButton *minusButton;
    QPushButton *num3Button;
    QPushButton *divButton;
    QPushButton *leftBracketButton;
    QPushButton *rightBracketButton;
    QPushButton *num0Button;
    QMenuBar *menubar;
    QMenu *menuHistory;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(444, 755);
        action234 = new QAction(MainWindow);
        action234->setObjectName("action234");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        textDisplay = new QTextEdit(centralwidget);
        textDisplay->setObjectName("textDisplay");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textDisplay->sizePolicy().hasHeightForWidth());
        textDisplay->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        textDisplay->setFont(font);
        textDisplay->setReadOnly(true);

        verticalLayout_2->addWidget(textDisplay);

        buttonsLayout = new QGridLayout();
        buttonsLayout->setObjectName("buttonsLayout");
        crossButton = new QPushButton(centralwidget);
        crossButton->setObjectName("crossButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(crossButton->sizePolicy().hasHeightForWidth());
        crossButton->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(16);
        crossButton->setFont(font1);

        buttonsLayout->addWidget(crossButton, 3, 3, 1, 1);

        equalButton = new QPushButton(centralwidget);
        equalButton->setObjectName("equalButton");
        sizePolicy1.setHeightForWidth(equalButton->sizePolicy().hasHeightForWidth());
        equalButton->setSizePolicy(sizePolicy1);
        equalButton->setFont(font1);

        buttonsLayout->addWidget(equalButton, 6, 3, 1, 1);

        num5Button = new QPushButton(centralwidget);
        num5Button->setObjectName("num5Button");
        sizePolicy1.setHeightForWidth(num5Button->sizePolicy().hasHeightForWidth());
        num5Button->setSizePolicy(sizePolicy1);
        num5Button->setFont(font1);

        buttonsLayout->addWidget(num5Button, 4, 1, 1, 1);

        num8Button = new QPushButton(centralwidget);
        num8Button->setObjectName("num8Button");
        sizePolicy1.setHeightForWidth(num8Button->sizePolicy().hasHeightForWidth());
        num8Button->setSizePolicy(sizePolicy1);
        num8Button->setFont(font1);

        buttonsLayout->addWidget(num8Button, 3, 1, 1, 1);

        num6Button = new QPushButton(centralwidget);
        num6Button->setObjectName("num6Button");
        sizePolicy1.setHeightForWidth(num6Button->sizePolicy().hasHeightForWidth());
        num6Button->setSizePolicy(sizePolicy1);
        num6Button->setFont(font1);

        buttonsLayout->addWidget(num6Button, 4, 2, 1, 1);

        num1Button = new QPushButton(centralwidget);
        num1Button->setObjectName("num1Button");
        sizePolicy1.setHeightForWidth(num1Button->sizePolicy().hasHeightForWidth());
        num1Button->setSizePolicy(sizePolicy1);
        num1Button->setFont(font1);

        buttonsLayout->addWidget(num1Button, 5, 0, 1, 1);

        num4Button = new QPushButton(centralwidget);
        num4Button->setObjectName("num4Button");
        sizePolicy1.setHeightForWidth(num4Button->sizePolicy().hasHeightForWidth());
        num4Button->setSizePolicy(sizePolicy1);
        num4Button->setFont(font1);

        buttonsLayout->addWidget(num4Button, 4, 0, 1, 1);

        pow2Button = new QPushButton(centralwidget);
        pow2Button->setObjectName("pow2Button");
        sizePolicy1.setHeightForWidth(pow2Button->sizePolicy().hasHeightForWidth());
        pow2Button->setSizePolicy(sizePolicy1);
        pow2Button->setFont(font1);

        buttonsLayout->addWidget(pow2Button, 2, 1, 1, 1);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        sizePolicy1.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy1);
        addButton->setFont(font1);

        buttonsLayout->addWidget(addButton, 5, 3, 1, 1);

        sqrtButton = new QPushButton(centralwidget);
        sqrtButton->setObjectName("sqrtButton");
        sizePolicy1.setHeightForWidth(sqrtButton->sizePolicy().hasHeightForWidth());
        sqrtButton->setSizePolicy(sizePolicy1);
        sqrtButton->setFont(font1);

        buttonsLayout->addWidget(sqrtButton, 2, 2, 1, 1);

        dotButton = new QPushButton(centralwidget);
        dotButton->setObjectName("dotButton");
        sizePolicy1.setHeightForWidth(dotButton->sizePolicy().hasHeightForWidth());
        dotButton->setSizePolicy(sizePolicy1);
        dotButton->setFont(font1);

        buttonsLayout->addWidget(dotButton, 6, 2, 1, 1);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        sizePolicy1.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy1);
        clearButton->setFont(font1);

        buttonsLayout->addWidget(clearButton, 1, 2, 1, 1);

        num2Button = new QPushButton(centralwidget);
        num2Button->setObjectName("num2Button");
        sizePolicy1.setHeightForWidth(num2Button->sizePolicy().hasHeightForWidth());
        num2Button->setSizePolicy(sizePolicy1);
        num2Button->setFont(font1);

        buttonsLayout->addWidget(num2Button, 5, 1, 1, 1);

        reciprocalButton = new QPushButton(centralwidget);
        reciprocalButton->setObjectName("reciprocalButton");
        sizePolicy1.setHeightForWidth(reciprocalButton->sizePolicy().hasHeightForWidth());
        reciprocalButton->setSizePolicy(sizePolicy1);
        reciprocalButton->setFont(font1);

        buttonsLayout->addWidget(reciprocalButton, 2, 0, 1, 1);

        backspaceButton = new QPushButton(centralwidget);
        backspaceButton->setObjectName("backspaceButton");
        sizePolicy1.setHeightForWidth(backspaceButton->sizePolicy().hasHeightForWidth());
        backspaceButton->setSizePolicy(sizePolicy1);
        backspaceButton->setFont(font1);

        buttonsLayout->addWidget(backspaceButton, 1, 3, 1, 1);

        num7Button = new QPushButton(centralwidget);
        num7Button->setObjectName("num7Button");
        sizePolicy1.setHeightForWidth(num7Button->sizePolicy().hasHeightForWidth());
        num7Button->setSizePolicy(sizePolicy1);
        num7Button->setFont(font1);

        buttonsLayout->addWidget(num7Button, 3, 0, 1, 1);

        num9Button = new QPushButton(centralwidget);
        num9Button->setObjectName("num9Button");
        sizePolicy1.setHeightForWidth(num9Button->sizePolicy().hasHeightForWidth());
        num9Button->setSizePolicy(sizePolicy1);
        num9Button->setFont(font1);

        buttonsLayout->addWidget(num9Button, 3, 2, 1, 1);

        minusButton = new QPushButton(centralwidget);
        minusButton->setObjectName("minusButton");
        sizePolicy1.setHeightForWidth(minusButton->sizePolicy().hasHeightForWidth());
        minusButton->setSizePolicy(sizePolicy1);
        minusButton->setFont(font1);

        buttonsLayout->addWidget(minusButton, 4, 3, 1, 1);

        num3Button = new QPushButton(centralwidget);
        num3Button->setObjectName("num3Button");
        sizePolicy1.setHeightForWidth(num3Button->sizePolicy().hasHeightForWidth());
        num3Button->setSizePolicy(sizePolicy1);
        num3Button->setFont(font1);

        buttonsLayout->addWidget(num3Button, 5, 2, 1, 1);

        divButton = new QPushButton(centralwidget);
        divButton->setObjectName("divButton");
        sizePolicy1.setHeightForWidth(divButton->sizePolicy().hasHeightForWidth());
        divButton->setSizePolicy(sizePolicy1);
        divButton->setFont(font1);

        buttonsLayout->addWidget(divButton, 2, 3, 1, 1);

        leftBracketButton = new QPushButton(centralwidget);
        leftBracketButton->setObjectName("leftBracketButton");
        sizePolicy1.setHeightForWidth(leftBracketButton->sizePolicy().hasHeightForWidth());
        leftBracketButton->setSizePolicy(sizePolicy1);
        leftBracketButton->setFont(font1);

        buttonsLayout->addWidget(leftBracketButton, 1, 0, 1, 1);

        rightBracketButton = new QPushButton(centralwidget);
        rightBracketButton->setObjectName("rightBracketButton");
        sizePolicy1.setHeightForWidth(rightBracketButton->sizePolicy().hasHeightForWidth());
        rightBracketButton->setSizePolicy(sizePolicy1);
        rightBracketButton->setFont(font1);

        buttonsLayout->addWidget(rightBracketButton, 1, 1, 1, 1);

        num0Button = new QPushButton(centralwidget);
        num0Button->setObjectName("num0Button");
        sizePolicy1.setHeightForWidth(num0Button->sizePolicy().hasHeightForWidth());
        num0Button->setSizePolicy(sizePolicy1);
        num0Button->setFont(font1);

        buttonsLayout->addWidget(num0Button, 6, 0, 1, 2);


        verticalLayout_2->addLayout(buttonsLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 444, 33));
        menuHistory = new QMenu(menubar);
        menuHistory->setObjectName("menuHistory");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHistory->menuAction());
        menuHistory->addAction(action234);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\345\231\250 - By 23301171", nullptr));
        action234->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\256\241\347\256\227\345\216\206\345\217\262", nullptr));
        crossButton->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        equalButton->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        num5Button->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        num8Button->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        num6Button->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        num1Button->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        num4Button->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pow2Button->setText(QCoreApplication::translate("MainWindow", "x^2", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        sqrtButton->setText(QCoreApplication::translate("MainWindow", "sqrt(x)", nullptr));
        dotButton->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
        num2Button->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        reciprocalButton->setText(QCoreApplication::translate("MainWindow", "1/x", nullptr));
        backspaceButton->setText(QCoreApplication::translate("MainWindow", "\345\233\236\351\200\200", nullptr));
        num7Button->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        num9Button->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        minusButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        num3Button->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        divButton->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        leftBracketButton->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        rightBracketButton->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        num0Button->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        menuHistory->setTitle(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
