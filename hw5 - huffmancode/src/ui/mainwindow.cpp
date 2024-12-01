#include "mainwindow.h"

#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QThread>

#include "./ui_mainwindow.h"
#include "../data/FileHandler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_compressButton_clicked() {
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("选择被压缩的多个文件"), "", tr("所有文件 (*)"));
    if (fileNames.isEmpty()) {
        QMessageBox::warning(this,tr("错误"),tr("选择不可为空"));
        return;
    }
    ui->logEdit->appendPlainText("被选择的文件路径：");
    std::vector<QFileInfo> selectedFiles;
    for (const QString &fileName : fileNames) {
        ui->logEdit->appendPlainText(fileName);
        QFileInfo info(fileName);
        selectedFiles.push_back(info);
    }
    QString savePath = QFileDialog::getSaveFileName(this, tr("选择保存路径并输入压缩包名"), "", tr("HUF 文件 (*.huf)"));
    if (savePath.isEmpty()) {
        QMessageBox::warning(this,tr("警告"),tr("选择不可为空！请重新选择。"));
        return;
    }
    ui->logEdit->appendPlainText("压缩包生成位置：");
    ui->logEdit->appendPlainText(savePath);
    // 定期更新进度
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, timer] {
        int progress = FileHandler::getProgress();
        ui->logEdit->appendPlainText(QString("当前进度: %1%").arg(progress));
        ui->progressBar->setValue(progress);
        if (progress >= 100) {
            timer->stop();
            ui->logEdit->appendPlainText("压缩完成。");
        }
    });
    timer->start(500);
    // 创建解压线程
    auto *thread = new QThread;
    connect(thread, &QThread::started, [this, selectedFiles, savePath] {
        FileHandler::compress(selectedFiles, savePath);
    });
    thread->start();
}

void MainWindow::on_openHufButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("选择压缩包"), "", tr("HUF 文件 (*.huf)"));
    if (fileName.isEmpty()) {
        QMessageBox::warning(this,tr("警告"),tr("选择不可为空！请重新选择。"));
        return;
    }
    ui->logEdit->appendPlainText("被选择的压缩包路径：");
    ui->logEdit->appendPlainText(fileName);
    packInfo = FileHandler::getPackInfo(fileName);

    ui->filesTableWidget->setRowCount(0);
    ui->filesTableWidget->setColumnCount(5);
    ui->filesTableWidget->setHorizontalHeaderLabels({tr("文件名"), tr("原始大小(bytes)"), tr("压缩后大小(bytes)"), tr("压缩比"),tr("节省空间率")});
    for (const FileData& fileData : packInfo) {
        int rowCount = ui->filesTableWidget->rowCount();
        ui->filesTableWidget->insertRow(rowCount);
        // 文件名
        ui->filesTableWidget->setItem(rowCount, 0, new QTableWidgetItem(fileData.fileName));
        // 原始大小
        ui->filesTableWidget->setItem(rowCount, 1, new QTableWidgetItem(QString::number(fileData.oriSize)));
        // 压缩后大小
        unsigned int compressedSize = fileData.getCompressedSize();
        ui->filesTableWidget->setItem(rowCount, 2, new QTableWidgetItem(QString::number(compressedSize)));
        // 压缩比
        double compressionRatio = static_cast<double>(fileData.oriSize) / compressedSize;
        ui->filesTableWidget->setItem(rowCount, 3, new QTableWidgetItem(QString::number(compressionRatio * 100, 'f', 2) + "%"));
        // 节省空间率
        double savedRatio = 1 - compressedSize / static_cast<double>(fileData.oriSize);
        ui->filesTableWidget->setItem(rowCount, 4, new QTableWidgetItem(QString::number(savedRatio * 100, 'f', 2) + "%"));
    }
    ui->filesTableWidget->resizeRowsToContents();
    ui->filesTableWidget->resizeColumnsToContents();
    ui->filesTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->filesTableWidget, &QTableWidget::itemDoubleClicked, this, &MainWindow::onItemDoubleClicked);
}

void MainWindow::on_decompressButton_clicked() {
    if (packInfo.empty()) {
        QMessageBox::warning(this, tr("警告"), tr("没有选择被解压的压缩包！请先打开后再解压。"));
        return;
    }
    QString extractPath = QFileDialog::getExistingDirectory(this, tr("选择解压缩目录"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (extractPath.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("没有选择目录！请重新选择。"));
        return;
    }
    auto rows = getSelectedRows();
    if (rows.empty()) {
        QMessageBox::warning(this, tr("警告"), tr("没有选择被解压文件！"));
        return;
    }
    ui->logEdit->appendPlainText("解压缩文件将保存到: " + extractPath);
    // TODO
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, timer] {
        int progress = FileHandler::getProgress();
        ui->logEdit->appendPlainText(QString("当前进度: %1%").arg(progress));
        ui->progressBar->setValue(progress);
        if (progress >= 100) {
            timer->stop();
            ui->logEdit->appendPlainText("解压完成。");
        }
    });
    timer->start(500);

    auto *thread = new QThread;
    connect(thread, &QThread::started, [this, extractPath, rows] {
        for (int i : rows) {
            auto fileData = packInfo[i];
            ui->logEdit->appendPlainText(QString("正在解压%1").arg(fileData.fileName));
            FileHandler::decompress(fileData, extractPath);
        }
    });
    thread->start();
}

void MainWindow::on_decompressAllButton_clicked() {
    if (packInfo.empty()) {
        QMessageBox::warning(this, tr("警告"), tr("没有选择被解压的压缩包！请先打开后再解压。"));
        return;
    }
    QString extractPath = QFileDialog::getExistingDirectory(this, tr("选择解压缩目录"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (extractPath.isEmpty()) {
        QMessageBox::warning(this, tr("警告"), tr("没有选择目录！请重新选择。"));
        return;
    }
    ui->logEdit->appendPlainText("解压缩文件将保存到: " + extractPath);
    // 定期更新进度
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, timer] {
        int progress = FileHandler::getProgress();
        ui->logEdit->appendPlainText(QString("当前进度: %1%").arg(progress));
        ui->progressBar->setValue(progress);
        if (progress >= 100) {
            timer->stop();
            ui->logEdit->appendPlainText("解压完成。");
        }
    });
    timer->start(500); // 每0.5秒更新一次
    auto *thread = new QThread;
    connect(thread, &QThread::started, [this, extractPath] {
        for (const FileData& fileData : packInfo) {
            ui->logEdit->appendPlainText(QString("正在解压%1").arg(fileData.fileName));
            FileHandler::decompress(fileData, extractPath);
        }
    });
    thread->start();
}

int MainWindow::getSelectedRow() const {
    QList<QTableWidgetItem*> selectedItems = ui->filesTableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        return selectedItems.first()->row();
    }
    return -1;
}

std::vector<int> MainWindow::getSelectedRows() const {
    QList<QTableWidgetItem*> selectedItems = ui->filesTableWidget->selectedItems();
    std::vector<int> selectedRows;
    for (QTableWidgetItem* item : selectedItems) {
        int row = item->row();
        // 检查 row 是否已存在于 selectedRows，避免重复
        if (std::find(selectedRows.begin(), selectedRows.end(), row) == selectedRows.end()) {
            selectedRows.push_back(row);
        }
    }
    return selectedRows; // 返回所有选中的行索引
}

void MainWindow::onItemDoubleClicked() {
    auto reply = QMessageBox::question(this, tr("选项"), tr("你要打开这个文件吗？（文件将解压到当前目录下）"), QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) return;
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [this, timer] {
        int progress = FileHandler::getProgress();
        ui->logEdit->appendPlainText(QString("当前进度: %1%").arg(progress));
        ui->progressBar->setValue(progress);
        if (progress >= 100) {
            timer->stop();
            ui->logEdit->appendPlainText("解压完成。");
        }
    });
    timer->start(500);

    int row = getSelectedRow();
    FileData data = packInfo[row];
    QString extractPath = QDir::current().absolutePath();
    auto *thread = new QThread;
    connect(thread, &QThread::started, [this, data, extractPath] {
        FileHandler::decompress(data, extractPath);
        QString outPath = extractPath + "/" + data.fileName;
        std::string command;
        #ifdef _WIN32
            // Windows
            command = "start \"\" \"" + outPath.toStdString() + "\"";
        #elif defined(__APPLE__)
            // macOS
            command = "open \"" + outPath.toStdString() + "\"";
        #else
            // Linux
            command = "xdg-open \"" + outPath.toStdString() + "\"";
        #endif
        if (system(command.c_str()) != 0) {
            QMessageBox::critical(this, tr("错误"), tr("无法打开文件！"));
        }
    });
    thread->start();
}
