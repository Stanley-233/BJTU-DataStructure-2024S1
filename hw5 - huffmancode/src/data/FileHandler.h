//
// Created by stanl on 24-11-4.
//

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QBitArray>
#include <QFileInfo>
#include <utility>

struct FileData {
    QString fileName;
    QMap<unsigned char, unsigned int> weight;
    QBitArray data;
    int oriSize;
    // 重载序列化流
    friend QDataStream &operator <<(QDataStream &out, const FileData &fileInfo) {
        out << fileInfo.fileName << fileInfo.weight << fileInfo.oriSize << fileInfo.data;
        return out;
    }
    friend QDataStream &operator >>(QDataStream &in, FileData &fileInfo) {
        in >> fileInfo.fileName >> fileInfo.weight >> fileInfo.oriSize >> fileInfo.data;
        return in;
    }
    FileData() = default;
    FileData(QString file_name, int ori_size, QMap<unsigned char, unsigned int> weight, QBitArray data)
        : fileName(std::move(file_name)),
          oriSize(ori_size),
          weight(std::move(weight)),
          data(std::move(data)){}
    int getCompressedSize() const {
        // 计算压缩数据的字节数
        int compressedDataSize = (data.size() + 7) / 8; // 向上取整
        // 计算文件名的字节数
        int fileNameSize = fileName.toUtf8().size();
        // 计算权重的字节数
        int weightSize = weight.size() * (sizeof(unsigned char) + sizeof(unsigned int));
        return compressedDataSize + fileNameSize + weightSize + 4;
    }
};

class FileHandler {
    static int progress;
public:
    static void compress(const std::vector<QFileInfo>&, const QString&);
    static std::vector<FileData> getPackInfo(const QString&);
    static void decompress(const FileData&, const QString&);
    static int getProgress() {
        return progress;
    }
};



#endif //FILEHANDLER_H
