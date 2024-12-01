#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

struct FileData;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void on_compressButton_clicked();
    void on_decompressButton_clicked();
    void on_openHufButton_clicked();
    void on_decompressAllButton_clicked();
    void onItemDoubleClicked();

private:
    std::vector<FileData> packInfo;
    int getSelectedRow() const;
    std::vector<int> getSelectedRows() const;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
