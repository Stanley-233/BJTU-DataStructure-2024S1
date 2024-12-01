//
// Created by stanl on 24-11-22.
//

#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDir>

#include "Graph.h"

class Database {
    QSqlDatabase db;
public:
    Database();
    ~Database();
    std::vector<Graph::Spot> loadSpots();
    std::vector<Graph::Route> loadRoutes();
};

#endif //DATABASE_H
