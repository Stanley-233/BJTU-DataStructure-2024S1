//
// Created by stanl on 24-11-21.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <QString>
#include <vector>
#include <algorithm>
#include <map>

class Graph {
public:
    struct Spot {
        int id;
        QString name;
        QString info;
        Spot(const int id, QString name, QString info)
            : id(id),
              name(std::move(name)),
              info(std::move(info)) {
        }
        Spot() = default;
        ~Spot() = default;
    };
    struct Route {
        int id;
        int start;
        int end;
        int length;
        QString info;
        int startx;
        int starty;
        int endx;
        int endy;
        Route(const int id, const int start, const int end, const int length, QString info,
            const int startx, const int starty, const int endx, const int endy)
              : id(id),
                start(start),
                end(end),
                length(length),
                info(std::move(info)),
                startx(startx),
                starty(starty),
                endx(endx),
                endy(endy) {}

        Route() = default;
        ~Route() = default;
    };
private:
    // 邻接表
    std::vector<std::vector<Route>> adjList;
    std::vector<Route> generate_mst(int begin) const;
    void dfs(int begin, std::vector<int>&, std::vector<bool>&);

public:
    std::vector<Spot> spots;
    std::vector<Route> routes;
    Graph() = default;
    ~Graph() = default;
    Graph(const std::vector<Spot>& spots, const std::vector<Route>& routes);
    // dijkstra algorithm
    std::map<int,std::vector<int>> shortest_path(int begin);
    std::vector<int> shortest_path(int begin, int end);
    // Spawning a minimal spanning tree, then traverse it
    std::vector<int> traverse_all_spots(int begin);
};


#endif //GRAPH_H
