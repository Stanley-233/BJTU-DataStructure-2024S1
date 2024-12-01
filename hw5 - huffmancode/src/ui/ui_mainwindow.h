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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *buttonsLayout;
    QPushButton *compressButton;
    QPushButton *openHufButton;
    QPushButton *decompressButton;
    QPushButton *decompressAllButton;
    QHBoxLayout *filesLayout;
    QTableWidget *filesTableWidget;
    QPlainTextEdit *logEdit;
    QProgressBar *progressBar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(871, 634);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setObjectName("buttonsLayout");
        compressButton = new QPushButton(centralwidget);
        compressButton->setObjectName("compressButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(compressButton->sizePolicy().hasHeightForWidth());
        compressButton->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(12);
        compressButton->setFont(font);

        buttonsLayout->addWidget(compressButton);

        openHufButton = new QPushButton(centralwidget);
        openHufButton->setObjectName("openHufButton");
        sizePolicy.setHeightForWidth(openHufButton->sizePolicy().hasHeightForWidth());
        openHufButton->setSizePolicy(sizePolicy);
        openHufButton->setFont(font);

        buttonsLayout->addWidget(openHufButton);

        decompressButton = new QPushButton(centralwidget);
        decompressButton->setObjectName("decompressButton");
        sizePolicy.setHeightForWidth(decompressButton->sizePolicy().hasHeightForWidth());
        decompressButton->setSizePolicy(sizePolicy);
        decompressButton->setFont(font);

        buttonsLayout->addWidget(decompressButton);

        decompressAllButton = new QPushButton(centralwidget);
        decompressAllButton->setObjectName("decompressAllButton");
        sizePolicy.setHeightForWidth(decompressAllButton->sizePolicy().hasHeightForWidth());
        decompressAllButton->setSizePolicy(sizePolicy);
        decompressAllButton->setFont(font);

        buttonsLayout->addWidget(decompressAllButton);


        verticalLayout_2->addLayout(buttonsLayout);

        filesLayout = new QHBoxLayout();
        filesLayout->setObjectName("filesLayout");
        filesTableWidget = new QTableWidget(centralwidget);
        filesTableWidget->setObjectName("filesTableWidget");

        filesLayout->addWidget(filesTableWidget);

        logEdit = new QPlainTextEdit(centralwidget);
        logEdit->setObjectName("logEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logEdit->sizePolicy().hasHeightForWidth());
        logEdit->setSizePolicy(sizePolicy1);
        logEdit->setReadOnly(true);

        filesLayout->addWidget(logEdit);


        verticalLayout_2->addLayout(filesLayout);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setMaximum(100);
        progressBar->setValue(0);

        verticalLayout_2->addWidget(progressBar);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 871, 33));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\234\215\345\244\253\346\233\274\345\216\213\347\274\251 - 23301171", nullptr));
        compressButton->setText(QCoreApplication::translate("MainWindow", "\345\216\213\347\274\251", nullptr));
        openHufButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\216\213\347\274\251\345\214\205", nullptr));
        decompressButton->setText(QCoreApplication::translate("MainWindow", "\350\247\243\345\216\213\351\200\211\344\270\255\346\226\207\344\273\266", nullptr));
        decompressAllButton->setText(QCoreApplication::translate("MainWindow", "\350\247\243\345\216\213\345\205\250\351\203\250\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
