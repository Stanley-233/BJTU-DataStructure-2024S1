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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *endIndex;
    QSpinBox *startIndex;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *loadButton;
    QPushButton *startInfoButton;
    QPushButton *allRoutesButton;
    QPushButton *twoShortPathButton;
    QPushButton *multiShortPathButton;
    QVBoxLayout *verticalLayout_3;
    QPlainTextEdit *msgArea;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(559, 763);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(10);
        graphicsView->setFont(font);

        verticalLayout->addWidget(graphicsView);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        endIndex = new QSpinBox(centralwidget);
        endIndex->setObjectName("endIndex");
        endIndex->setFont(font);
        endIndex->setMinimum(1);
        endIndex->setMaximum(10);

        gridLayout->addWidget(endIndex, 2, 1, 1, 1);

        startIndex = new QSpinBox(centralwidget);
        startIndex->setObjectName("startIndex");
        startIndex->setFont(font);
        startIndex->setMinimum(1);
        startIndex->setMaximum(10);

        gridLayout->addWidget(startIndex, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(loadButton->sizePolicy().hasHeightForWidth());
        loadButton->setSizePolicy(sizePolicy1);
        loadButton->setFont(font);

        verticalLayout_2->addWidget(loadButton);

        startInfoButton = new QPushButton(centralwidget);
        startInfoButton->setObjectName("startInfoButton");
        sizePolicy1.setHeightForWidth(startInfoButton->sizePolicy().hasHeightForWidth());
        startInfoButton->setSizePolicy(sizePolicy1);
        startInfoButton->setFont(font);

        verticalLayout_2->addWidget(startInfoButton);

        allRoutesButton = new QPushButton(centralwidget);
        allRoutesButton->setObjectName("allRoutesButton");
        sizePolicy1.setHeightForWidth(allRoutesButton->sizePolicy().hasHeightForWidth());
        allRoutesButton->setSizePolicy(sizePolicy1);
        allRoutesButton->setFont(font);

        verticalLayout_2->addWidget(allRoutesButton);

        twoShortPathButton = new QPushButton(centralwidget);
        twoShortPathButton->setObjectName("twoShortPathButton");
        sizePolicy1.setHeightForWidth(twoShortPathButton->sizePolicy().hasHeightForWidth());
        twoShortPathButton->setSizePolicy(sizePolicy1);
        twoShortPathButton->setFont(font);

        verticalLayout_2->addWidget(twoShortPathButton);

        multiShortPathButton = new QPushButton(centralwidget);
        multiShortPathButton->setObjectName("multiShortPathButton");
        sizePolicy1.setHeightForWidth(multiShortPathButton->sizePolicy().hasHeightForWidth());
        multiShortPathButton->setSizePolicy(sizePolicy1);
        multiShortPathButton->setFont(font);

        verticalLayout_2->addWidget(multiShortPathButton);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        msgArea = new QPlainTextEdit(centralwidget);
        msgArea->setObjectName("msgArea");
        sizePolicy1.setHeightForWidth(msgArea->sizePolicy().hasHeightForWidth());
        msgArea->setSizePolicy(sizePolicy1);
        msgArea->setFont(font);
        msgArea->setReadOnly(true);

        verticalLayout_3->addWidget(msgArea);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\214\227\344\272\244\350\207\252\345\212\251\346\270\270 -23301171", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\345\212\240\350\275\275\346\225\260\346\215\256", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\265\267\347\202\271\347\274\226\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\347\273\210\347\202\271\347\274\226\345\217\267", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "\345\212\240\350\275\275\346\225\260\346\215\256", nullptr));
        startInfoButton->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\350\265\267\347\202\271\344\277\241\346\201\257", nullptr));
        allRoutesButton->setText(QCoreApplication::translate("MainWindow", "\347\224\261\345\215\225\347\202\271\351\201\215\345\216\206\345\205\250\345\233\276", nullptr));
        twoShortPathButton->setText(QCoreApplication::translate("MainWindow", "\350\256\241\347\256\227\344\270\244\347\202\271\350\267\257\345\276\204", nullptr));
        multiShortPathButton->setText(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215\345\205\250\345\233\276\346\230\276\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
