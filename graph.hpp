#ifndef GRAPH_HPP
#define GRAPH_HPP
#define INF 0x3f3f3f3f

#include <vector>
#include <list>
#include "city.hpp"
#include "priority_queue.hpp"

using namespace std;
class Graph {
public:
    int length;

    int destinyCity;

    list<City> **graph;
    Graph(int num_vertices);
    void addVertex(const int originId,const City city);
    void print();
    int dijkstra();
    Graph bfs();
private:
};

#endif // GRAPH_HPP