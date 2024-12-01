//
// Created by stanl on 24-10-18.
//

#include "DataBase.h"

DataBase::DataBase() {
    openDatabase();
    table_name = QString("car_records").append(QDateTime::currentDateTime().toString("_yyyy_MM_dd_hh_mm_ss"));
}

bool DataBase::openDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("park.db");
    if (!db.open()) {
        qWarning() << "数据库未打开！" << db.lastError().text();
        return false;
    }
    QSqlQuery query;
    QString createTableSql = QString("CREATE TABLE IF NOT EXISTS ")
    .append(table_name)
    .append(" (id INTEGER PRIMARY KEY AUTOINCREMENT,")
    .append("in_time TEXT NOT NULL,")
    .append("car_name TEXT NOT NULL,")
    .append("out_time TEXT NOT NULL,")
    .append("fee REAL NOT NULL);");
    query.exec(createTableSql);
    return true;
}

void DataBase::closeDatabase() {
    if (db.isOpen()) {
        db.close();
    }
}

bool DataBase::insertRecord(QString inTime, QString carName, QString outTime, float fee) {
    QSqlQuery query;
    QString insertSql = QString("INSERT INTO ")
                                .append(table_name)
                                .append(" (in_time, car_name, out_time, fee) VALUES (:in_time, :car_name, :out_time, :fee);");
    query.prepare(insertSql);
    query.bindValue(":in_time", inTime);
    query.bindValue(":car_name", carName);
    query.bindValue(":out_time", outTime);
    query.bindValue(":fee", fee);
    if (!query.exec()) {
        qWarning() << "插入错误:" << query.lastError().text();
        return false;
    }
    return true;
}

QVector<float> DataBase::getAllFees() const {
    QVector<float> fees;
    if (!db.isOpen()) {
        qWarning() << "数据库未打开!";
        return fees;
    }
    QString selectSql = QString("SELECT fee FROM ").append(table_name);
    QSqlQuery query(selectSql);
    while (query.next()) {
        float fee = query.value(0).toFloat();
        fees.append(fee);
    }
    return fees;
}

QVector<float> DataBase::getAllFees(QString time) const {
    QVector<float> fees;
    if (!db.isOpen()) {
        qWarning() << "数据库未打开!";
        return fees;
    }
    QString selectSql = QString("SELECT fee FROM ").append("car_records_").append(time);
    QSqlQuery query(selectSql);
    while (query.next()) {
        float fee = query.value(0).toFloat();
        fees.append(fee);
    }
    return fees;
}

