//
// Created by stanl on 24-10-18.
//

#ifndef DATABASE_H
#define DATABASE_H

#include "../core/Core.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class DataBase {
public:
    DataBase();
    ~DataBase() = default;
    bool openDatabase();
    void closeDatabase();
    bool insertRecord(QString inTime, QString carName, QString outTime, float fee);
    QVector<float> getAllFees() const;
    QVector<float> getAllFees(QString time) const;

private:
    QSqlDatabase db;
    QString table_name;
};



#endif //DATABASE_H
