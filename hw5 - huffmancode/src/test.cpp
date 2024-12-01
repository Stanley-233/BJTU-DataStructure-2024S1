#include <QCoreApplication>
#include <iostream>
#include <bitset>
#include <QUrl>
#include <QDir>

#include "data/FileHandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "--------------Huffman文件压缩编码---------------" << std::endl;
    std::cout << "请输入文件名: ";

    std::string name;
    std::cin >> name;
    QString fileName = QString::fromStdString(name);
    QFile file(fileName);

    QString packName = "test.huf";
    std::vector<QFile*> files;
    files.push_back(new QFile(QString::fromStdString(name)));

    FileHandler::compress(files, packName);

    std::cout << "压缩成功！" << std::endl;

    QString outName;
    auto compressData = FileHandler::getPackInfo(packName);
    for (int i = 0; i < compressData.size(); i++) {
        auto info = compressData[i];
        std::cout << info.fileName.toStdString() << " " << info.oriSize << " " << info.getCompressedSize() << std::endl;
        outName = QString("out_").append(info.fileName);
        FileHandler::decompress(info,outName);
    }

    std::cout << "解压成功！" << std::endl;

    QString outPath = QDir::currentPath() + "/" + outName;
    std::string command;
#ifdef _WIN32
    // Windows
    command = "start \"\" \"" + outPath.toStdString() + "\"";
#else
    // Unix/Linux
    command = "xdg-open \"" + outPath.toStdString() + "\""; // 对于大多数 Linux 发行版
    // command = "open \"" + outPath.toStdString() + "\""; // macOS
#endif
    if (system(command.c_str()) != 0) {
        std::cerr << "无法打开文件: " << outPath.toStdString() << std::endl;
    }
}
