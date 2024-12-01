//
// Created by stanl on 24-10-19.
//

#ifndef FEEDIALOG_H
#define FEEDIALOG_H

#include <QDialog>


#include "mainwindow.h"

class FeeDialog : public QDialog {
    Q_OBJECT

    public:
    explicit FeeDialog(const QVector<float>& fees);
};



#endif //FEEDIALOG_H
