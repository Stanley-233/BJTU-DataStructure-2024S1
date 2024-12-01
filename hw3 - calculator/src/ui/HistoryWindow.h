//
// Created by stanl on 24-9-29.
//

#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <qdialog.h>

#include "mainwindow.h"

class HistoryWindow : public QDialog {
    public:
    explicit HistoryWindow(const QStringList &lines, MainWindow *parent = nullptr);
};


#endif //HISTORYWINDOW_H
