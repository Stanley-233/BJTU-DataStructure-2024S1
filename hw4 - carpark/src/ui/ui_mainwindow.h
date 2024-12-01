/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *startAction;
    QAction *stopAction;
    QAction *feeAction;
    QAction *historyFeeAction;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *operationLayout;
    QLabel *entry1Label;
    QPushButton *entry1AddButton;
    QLineEdit *entry1Display;
    QLabel *entry2Label;
    QPushButton *entry2AddButton;
    QLineEdit *entry2Display;
    QLabel *label_8;
    QSpinBox *spinBox;
    QLabel *label_9;
    QLineEdit *lineEmptySlots;
    QLabel *label;
    QLineEdit *lineDate;
    QLabel *label_2;
    QLineEdit *lineTime;
    QLabel *label_6;
    QLineEdit *lineEntryName;
    QLabel *label_7;
    QLineEdit *lineEntryTime;
    QLabel *label_3;
    QLineEdit *lineOutCar;
    QLabel *label_4;
    QLineEdit *lineParkTime;
    QLabel *label_5;
    QLineEdit *lineFee;
    QGraphicsView *parkView;
    QVBoxLayout *parkMsgLayout;
    QTextEdit *entryMsgArea;
    QTextEdit *exitMsgArea;
    QMenuBar *menubar;
    QMenu *startMenu;
    QMenu *filesMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1068, 720);
        startAction = new QAction(MainWindow);
        startAction->setObjectName("startAction");
        stopAction = new QAction(MainWindow);
        stopAction->setObjectName("stopAction");
        feeAction = new QAction(MainWindow);
        feeAction->setObjectName("feeAction");
        historyFeeAction = new QAction(MainWindow);
        historyFeeAction->setObjectName("historyFeeAction");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        operationLayout = new QVBoxLayout();
        operationLayout->setObjectName("operationLayout");
        entry1Label = new QLabel(centralwidget);
        entry1Label->setObjectName("entry1Label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(entry1Label->sizePolicy().hasHeightForWidth());
        entry1Label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(10);
        entry1Label->setFont(font);
        entry1Label->setScaledContents(false);
        entry1Label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(entry1Label);

        entry1AddButton = new QPushButton(centralwidget);
        entry1AddButton->setObjectName("entry1AddButton");
        sizePolicy.setHeightForWidth(entry1AddButton->sizePolicy().hasHeightForWidth());
        entry1AddButton->setSizePolicy(sizePolicy);
        entry1AddButton->setFont(font);

        operationLayout->addWidget(entry1AddButton);

        entry1Display = new QLineEdit(centralwidget);
        entry1Display->setObjectName("entry1Display");
        sizePolicy.setHeightForWidth(entry1Display->sizePolicy().hasHeightForWidth());
        entry1Display->setSizePolicy(sizePolicy);
        entry1Display->setFont(font);
        entry1Display->setAlignment(Qt::AlignmentFlag::AlignCenter);
        entry1Display->setReadOnly(true);

        operationLayout->addWidget(entry1Display);

        entry2Label = new QLabel(centralwidget);
        entry2Label->setObjectName("entry2Label");
        sizePolicy.setHeightForWidth(entry2Label->sizePolicy().hasHeightForWidth());
        entry2Label->setSizePolicy(sizePolicy);
        entry2Label->setFont(font);
        entry2Label->setScaledContents(false);
        entry2Label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(entry2Label);

        entry2AddButton = new QPushButton(centralwidget);
        entry2AddButton->setObjectName("entry2AddButton");
        sizePolicy.setHeightForWidth(entry2AddButton->sizePolicy().hasHeightForWidth());
        entry2AddButton->setSizePolicy(sizePolicy);
        entry2AddButton->setFont(font);

        operationLayout->addWidget(entry2AddButton);

        entry2Display = new QLineEdit(centralwidget);
        entry2Display->setObjectName("entry2Display");
        sizePolicy.setHeightForWidth(entry2Display->sizePolicy().hasHeightForWidth());
        entry2Display->setSizePolicy(sizePolicy);
        entry2Display->setFont(font);
        entry2Display->setAlignment(Qt::AlignmentFlag::AlignCenter);
        entry2Display->setReadOnly(true);

        operationLayout->addWidget(entry2Display);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(label_8);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setFont(font);
        spinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(spinBox);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(label_9);

        lineEmptySlots = new QLineEdit(centralwidget);
        lineEmptySlots->setObjectName("lineEmptySlots");
        sizePolicy.setHeightForWidth(lineEmptySlots->sizePolicy().hasHeightForWidth());
        lineEmptySlots->setSizePolicy(sizePolicy);
        lineEmptySlots->setFont(font);
        lineEmptySlots->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEmptySlots->setReadOnly(true);

        operationLayout->addWidget(lineEmptySlots);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(label);

        lineDate = new QLineEdit(centralwidget);
        lineDate->setObjectName("lineDate");
        sizePolicy.setHeightForWidth(lineDate->sizePolicy().hasHeightForWidth());
        lineDate->setSizePolicy(sizePolicy);
        lineDate->setFont(font);
        lineDate->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineDate->setReadOnly(true);

        operationLayout->addWidget(lineDate);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(label_2);

        lineTime = new QLineEdit(centralwidget);
        lineTime->setObjectName("lineTime");
        sizePolicy.setHeightForWidth(lineTime->sizePolicy().hasHeightForWidth());
        lineTime->setSizePolicy(sizePolicy);
        lineTime->setFont(font);
        lineTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineTime->setReadOnly(true);

        operationLayout->addWidget(lineTime);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(label_6);

        lineEntryName = new QLineEdit(centralwidget);
        lineEntryName->setObjectName("lineEntryName");
        sizePolicy.setHeightForWidth(lineEntryName->sizePolicy().hasHeightForWidth());
        lineEntryName->setSizePolicy(sizePolicy);
        lineEntryName->setFont(font);
        lineEntryName->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(lineEntryName);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(label_7);

        lineEntryTime = new QLineEdit(centralwidget);
        lineEntryTime->setObjectName("lineEntryTime");
        sizePolicy.setHeightForWidth(lineEntryTime->sizePolicy().hasHeightForWidth());
        lineEntryTime->setSizePolicy(sizePolicy);
        lineEntryTime->setFont(font);
        lineEntryTime->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(lineEntryTime);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(label_3);

        lineOutCar = new QLineEdit(centralwidget);
        lineOutCar->setObjectName("lineOutCar");
        sizePolicy.setHeightForWidth(lineOutCar->sizePolicy().hasHeightForWidth());
        lineOutCar->setSizePolicy(sizePolicy);
        lineOutCar->setFont(font);
        lineOutCar->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineOutCar->setReadOnly(true);

        operationLayout->addWidget(lineOutCar);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(label_4);

        lineParkTime = new QLineEdit(centralwidget);
        lineParkTime->setObjectName("lineParkTime");
        sizePolicy.setHeightForWidth(lineParkTime->sizePolicy().hasHeightForWidth());
        lineParkTime->setSizePolicy(sizePolicy);
        lineParkTime->setFont(font);
        lineParkTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineParkTime->setReadOnly(true);

        operationLayout->addWidget(lineParkTime);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        operationLayout->addWidget(label_5);

        lineFee = new QLineEdit(centralwidget);
        lineFee->setObjectName("lineFee");
        sizePolicy.setHeightForWidth(lineFee->sizePolicy().hasHeightForWidth());
        lineFee->setSizePolicy(sizePolicy);
        lineFee->setFont(font);
        lineFee->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineFee->setReadOnly(true);

        operationLayout->addWidget(lineFee);


        horizontalLayout->addLayout(operationLayout);

        parkView = new QGraphicsView(centralwidget);
        parkView->setObjectName("parkView");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(parkView->sizePolicy().hasHeightForWidth());
        parkView->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        parkView->setFont(font1);
        parkView->setFocusPolicy(Qt::FocusPolicy::TabFocus);

        horizontalLayout->addWidget(parkView);

        parkMsgLayout = new QVBoxLayout();
        parkMsgLayout->setObjectName("parkMsgLayout");
        entryMsgArea = new QTextEdit(centralwidget);
        entryMsgArea->setObjectName("entryMsgArea");
        sizePolicy.setHeightForWidth(entryMsgArea->sizePolicy().hasHeightForWidth());
        entryMsgArea->setSizePolicy(sizePolicy);
        entryMsgArea->setFont(font1);
        entryMsgArea->setReadOnly(true);

        parkMsgLayout->addWidget(entryMsgArea);

        exitMsgArea = new QTextEdit(centralwidget);
        exitMsgArea->setObjectName("exitMsgArea");
        sizePolicy.setHeightForWidth(exitMsgArea->sizePolicy().hasHeightForWidth());
        exitMsgArea->setSizePolicy(sizePolicy);
        exitMsgArea->setFont(font1);
        exitMsgArea->setReadOnly(true);

        parkMsgLayout->addWidget(exitMsgArea);


        horizontalLayout->addLayout(parkMsgLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1068, 33));
        startMenu = new QMenu(menubar);
        startMenu->setObjectName("startMenu");
        filesMenu = new QMenu(menubar);
        filesMenu->setObjectName("filesMenu");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(startMenu->menuAction());
        menubar->addAction(filesMenu->menuAction());
        startMenu->addAction(startAction);
        startMenu->addAction(stopAction);
        filesMenu->addAction(feeAction);
        filesMenu->addAction(historyFeeAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246\345\234\272\347\256\241\347\220\206\347\263\273\347\273\237 - 23301171", nullptr));
        startAction->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\250\241\346\213\237", nullptr));
        stopAction->setText(QCoreApplication::translate("MainWindow", "\347\273\210\346\255\242\346\250\241\346\213\237", nullptr));
        feeAction->setText(QCoreApplication::translate("MainWindow", "\346\224\266\350\264\271\351\245\274\345\233\276", nullptr));
        historyFeeAction->setText(QCoreApplication::translate("MainWindow", "\345\216\206\345\217\262\346\224\266\350\264\271\351\245\274\345\233\276", nullptr));
        entry1Label->setText(QCoreApplication::translate("MainWindow", "\345\205\245\345\217\2431\345\275\223\345\211\215\346\216\222\351\230\237\344\272\272\346\225\260", nullptr));
        entry1AddButton->setText(QCoreApplication::translate("MainWindow", "\345\205\245\345\217\2431\345\242\236\345\212\240", nullptr));
        entry2Label->setText(QCoreApplication::translate("MainWindow", "\345\205\245\345\217\2432\345\275\223\345\211\215\346\216\222\351\230\237\344\272\272\346\225\260", nullptr));
        entry2AddButton->setText(QCoreApplication::translate("MainWindow", "\345\205\245\345\217\2432\345\242\236\345\212\240", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\346\216\222\351\230\237\344\272\272\346\225\260", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\347\251\272\350\275\246\344\275\215\346\225\260", nullptr));
        lineEmptySlots->setText(QCoreApplication::translate("MainWindow", "12", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\350\277\233\345\205\245\347\232\204\350\275\246", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\277\233\345\205\245\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\345\207\272\345\216\273\347\232\204\350\275\246", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\201\234\350\275\246\346\227\266\351\225\277", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\224\266\350\264\271", nullptr));
        startMenu->setTitle(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        filesMenu->setTitle(QCoreApplication::translate("MainWindow", "\347\273\237\350\256\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
