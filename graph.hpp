#ifndef GRAPH_HPP
#define GRAPH_HPP
#define INF 0x3f3f3f3f

#include <vector>
#include <list>
#include "city.hpp"
#include "priority_queue.hpp"

using namespace std;
class Graph {
    list<City> **graph;
    int length;
    int distanceCity;
    int destinyCity;

public:
    Graph(int num_vertices);
    void addVertex(const int originId,const City city);
    void print();
    int dijkstra();
    bool notVisited(list<int> ** visited,const int vertex, const int parent);
    void dfs(list<pair<int,int>> visited, const int vertex, const int distance, const int edgeCount);
    int dfsUtil();
    void remove(list<int> ** visited, const int vertex, const int parent);

private:
};

#endif // GRAPH_HPP