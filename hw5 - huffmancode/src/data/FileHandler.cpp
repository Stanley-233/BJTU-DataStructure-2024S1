//
// Created by stanl on 24-11-4.
//

#include "FileHandler.h"

#include <iostream>

#include "HuffmanTree.h"

constexpr int SERIALIZE_VER = QDataStream::Qt_6_8;

int FileHandler::progress = 0;

void FileHandler::compress(const std::vector<QFileInfo>& files, const QString& packName) {
    progress = 0;
    std::vector<FileData> file_datas;
    for (QFileInfo file_info : files) {
        const auto file = new QFile(file_info.absoluteFilePath());
        file->open(QIODevice::ReadOnly);
        QMap<unsigned char, unsigned int> weight;
        // 读取文件并统计字节权重
        while (!file->atEnd()) {
            unsigned char ch;
            file->getChar(reinterpret_cast<char*>(&ch));
            weight[ch]++;
        }
        HuffmanTree huffmanTree(weight);
        QMap<unsigned char, QString> huffmanCodes = huffmanTree.getHuffmanCodes();
        // 转换编码
        QBitArray bits;
        QString currentCode;
        file->seek(0);
        int oriSize = static_cast<int>(file->size());
        int count = 0;
        while (!file->atEnd()) {
            unsigned char ch;
            file->getChar(reinterpret_cast<char*>(&ch));
            currentCode = huffmanCodes[ch];
            const auto currentSize = bits.size();
            bits.resize(currentSize + currentCode.length()); // 调整大小
            // 逐位添加到 QBitArray 中
            for (int i = 0; i < currentCode.length(); ++i) {
                if (currentCode[i] == '1') {
                    bits[currentSize + i] = true;
                } else {
                    bits[currentSize + i] = false;
                }
            }
            count++;
            if (count % 5000 == 0) {
                progress = 100.0 * count / oriSize;
            }
        }
        QString oriFileName = file_info.baseName().append(".").append(file_info.suffix());
        auto data = FileData(oriFileName,oriSize,weight,bits);
        file_datas.push_back(data);
        file->close();
    }
    // 序列化写文件
    auto package = QFile(packName);
    package.open(QIODevice::WriteOnly);
    QDataStream out(&package);
    out.setVersion(SERIALIZE_VER);
    out << static_cast<int>(file_datas.size());
    for (const auto& data : file_datas) {
        out << data;
    }
    package.close();
    progress = 100.0;
}

std::vector<FileData> FileHandler::getPackInfo(const QString &packName) {
    auto package = QFile(packName);
    package.open(QIODevice::ReadOnly);
    QDataStream in(&package);
    in.setVersion(SERIALIZE_VER);
    int fileCount;
    in >> fileCount;
    std::vector<FileData> file_datas;
    file_datas.resize(fileCount);
    for (int i = 0; i < fileCount; ++i) {
        in >> file_datas[i];
    }
    package.close();
    return file_datas;
}

void FileHandler::decompress(const FileData& data, const QString& outPath) {
    progress = 0;
    HuffmanTree huffmanTree(data.weight);
    QString outName = outPath + "/" + data.fileName;
    auto outFile = QFile(outName);
    outFile.open(QIODevice::WriteOnly);
    QDataStream out(&outFile);
    // 解码压缩数据
    QMap<unsigned char,QString> code = huffmanTree.getHuffmanCodes();
    QMap<QString, unsigned char> reverseCodeMap;
    for (auto it = code.begin(); it != code.end(); ++it) {
        reverseCodeMap[it.value()] = it.key();
    }
    QString currentCode;
    QByteArray decodedData;
    auto compressedSize = data.data.size();
    for (int i = 0; i < compressedSize; ++i) {
        // 构建当前编码
        currentCode.append(data.data[i] ? '1' : '0');
        // 检查当前编码是否在反转编码表中
        if (reverseCodeMap.contains(currentCode)) {
            // 找到匹配，添加到解码数据中
            decodedData.append(static_cast<char>(reverseCodeMap[currentCode]));
            currentCode.clear(); // 清空当前编码以开始下一个字符
        }
        if (i % 5000 == 0) {
            progress = 100.0 * i / compressedSize;
        }
    }
    // 写入解码后的数据到输出文件
    outFile.write(decodedData);
    outFile.close(); // 关闭输出文件
    progress = 100.0;
}
