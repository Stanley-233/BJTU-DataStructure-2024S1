//
// Created by stanl on 24-11-22.
//

#include "Database.h"

#include <iostream>
#include <QPlainTextEdit>
#include <QSqlError>

Database::Database() {
    QString dbPath = QDir::homePath() + "/bjtu_travel.db";
    // QString dbPath = QDir::homePath() + "/bjtu_travel_" + QString::number(QTime::currentTime().hour()) + ".db";
    if (!QFile::exists(dbPath)) {
        QFile::copy(":/bjtu_travel.db", dbPath);
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
    } else {
        qDebug() << "Database opened successfully!";
    }
}

Database::~Database() {
    if (db.isOpen()) db.close();
}

std::vector<Graph::Spot> Database::loadSpots() {
    std::vector<Graph::Spot> spots;
    const auto sql = QString("SELECT * FROM spot");
    QSqlQuery query(sql);
    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString info = query.value(2).toString();
        spots.emplace_back(id, name, info);
    }
    std::sort(spots.begin(), spots.end(), [](const Graph::Spot &spot1, const Graph::Spot &spot2) {
        return spot1.id < spot2.id;
    });
    return spots;
}

std::vector<Graph::Route> Database::loadRoutes() {
    std::vector<Graph::Route> routes;
    const auto sql = QString("SELECT * FROM route");
    QSqlQuery query(sql);
    while (query.next()) {
        int id = query.value(0).toInt();
        int begin = query.value(1).toInt();
        int end = query.value(2).toInt();
        int length = query.value(3).toInt();
        QString info = query.value(4).toString();
        int startx = query.value(5).toInt();
        int starty = query.value(6).toInt();
        int endx = query.value(7).toInt();
        int endy = query.value(8).toInt();
        routes.emplace_back(id, begin, end, length, info, startx, starty, endx, endy);
        routes.emplace_back(id - 20, end, begin, length, info, endx, endy, startx, starty);
    }
    return routes;
}

