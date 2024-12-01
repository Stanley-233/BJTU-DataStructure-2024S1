#include "ui/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    // int a[10] = {1,2,3,4,5,6,7,8,9,10};
    // auto stack = new Stack(a[0]);
    // for (int i = 1; i < 10; i++) {
    //     stack->push(a[i]);
    // }
    // for (int i = 0; i < 10; i++) {
    //     std::cout << stack->pop() << " ";
    // }
}
