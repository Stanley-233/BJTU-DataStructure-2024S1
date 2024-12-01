//
// Created by stanl on 24-10-8.
//

#include "HistoryWindow.h"

#include <QPushButton>

HistoryWindow::HistoryWindow(const QStringList &lines, MainWindow *parent) {
    parent->clearDisplay();
    auto *layout = new QVBoxLayout(this);
    QFont font("Arial", 14);
    auto clearButton = new QPushButton("清除历史记录",this);
    clearButton->setFont(font);
    layout->addWidget(clearButton);
    connect(clearButton, &QPushButton::clicked, this, [layout, clearButton]{
        for (int i = layout->count() - 1; i >= 0; --i) {
            QLayoutItem *item = layout->itemAt(i);
            if (item->widget() != clearButton) {
                delete item->widget(); // Delete the widget
                layout->removeItem(item); // Remove item from layout
            }
        }
    });
    // 遍历 QStringList，逐行添加 QPushButton
    for (const QString &line : lines) {
        auto button = new QPushButton(line, this);
        button->setFont(font);
        layout->addWidget(button);
        connect(button, &QPushButton::clicked, this, [this, line, parent] {
            parent->historyUpdateText(line);
            this->close();
        });
    }
    auto height = lines.size() * 20;
    setLayout(layout);
    setWindowTitle("历史记录");
    resize(500, height); // 设定窗口大小
}
