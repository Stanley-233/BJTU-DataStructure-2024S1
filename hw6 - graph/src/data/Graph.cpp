//
// Created by stanl on 24-11-21.
//

#include "Graph.h"

#include <filesystem>
#include <queue>

Graph::Graph(const std::vector<Spot>& spots, const std::vector<Route>& routes) {
    this->spots = spots;
    this->routes = routes;
    adjList.resize(spots.size());
    for (int i = 0; i < spots.size(); i++) {
        for (const auto& route : routes) {
            if (i != route.start) continue;
            adjList[i].emplace_back(route);
        }
    }
}

// Prim algorithm
std::vector<Graph::Route> Graph::generate_mst(int begin) const {
    std::vector<Route> mstEdges; // 存储MST的边
    std::vector inMST(adjList.size(), -1); // 标记顶点是否在MST中
    std::vector<int> vertices;
    std::vector<Route> mstRoutes;
    std::vector<Route> minEdges;
    int cur = begin;
    for (int i = 0; i < adjList.size() - 1; i++) {
        vertices.push_back(cur);
        inMST[cur] = 1;
        for (const auto& i : adjList[cur]) {
            if (inMST[i.end] == 1) continue;
            minEdges.emplace_back(i);
        }
        for (int k = 0; k < minEdges.size(); k++) {
            for (const auto& j : vertices) {
                if (minEdges[k].end != j) continue;
                minEdges.erase(minEdges.begin() + k);
            }
        }
        std::sort(minEdges.begin(), minEdges.end(), [](const Route& a, const Route& b) {
            return a.length < b.length;
        });
        auto minEdge = minEdges.front();
        minEdges.erase(minEdges.begin());
        cur = minEdge.end;
        mstRoutes.emplace_back(minEdge);
    }
    return mstRoutes;
}

void Graph::dfs(int begin, std::vector<int>& cur, std::vector<bool>& visited) {
    visited[begin] = true;
    for (const auto& route : adjList[begin]) {
        int next = route.end;
        cur.push_back(route.id);
        if (!visited[next]) {
            dfs(next, cur,visited);
        }
        cur.push_back(route.id);
    }
}

std::vector<int> Graph::traverse_all_spots(int begin) {
    std::vector<Route> mst = generate_mst(begin);
    auto mstGraph = Graph(spots, mst);
    std::vector<int> ret;
    std::vector visited(spots.size(), false);

    mstGraph.dfs(begin, ret, visited);
    // for (const auto& route: mst) {
    //     ret.emplace_back(route.id);
    // }
    return ret;
}

std::vector<int> Graph::shortest_path(int begin, int end) {
    std::map<int,std::vector<int>> ret = shortest_path(begin);
    return ret.at(end);
}

// return the shortest path from begin, return a map<end,id_of_all_routes>
std::map<int,std::vector<int>> Graph::shortest_path(int begin) {
    int n = adjList.size();
    std::vector minPaths(n, std::numeric_limits<int>::max());
    minPaths[begin] = 0; // 起点到自身的距离为0
    std::vector prev(n, -1); // 前驱节点
    std::vector visited(n, 0); // 是否找到
    using P = std::pair<int, int>;
    std::priority_queue<P, std::vector<P>, std::greater<>> pq;
    pq.emplace(0, begin);
    std::map<int, std::vector<int>> result;
    for (int i = 0; i < n; ++i) {
        result[i] = {};
    }
    while (!pq.empty()) {
        int cur_dis = pq.top().first;
        int cur_vert = pq.top().second;
        pq.pop();
        if (visited[cur_vert]) continue;
        visited[cur_vert] = 1;
        // 遍历所有邻接边
        for (const auto& route : adjList[cur_vert]) {
            int neighbor = route.end;
            int newDist = cur_dis + route.length;
            for (int i = 0; i < visited.size(); i++) {
                if (visited[i] == 1 & i == neighbor) {
                    goto end;
                }
            }
            if (newDist < minPaths[neighbor]) {
                minPaths[neighbor] = newDist;
                prev[neighbor] = cur_vert;
                pq.emplace(newDist, neighbor);
                result.at(neighbor) = result.at(cur_vert);
                result.at(neighbor).emplace_back(route.id);
            }
            end: 1 == 1;
        }
    }
    return result;
}
