#ifndef GRAPH_HPP
#define GRAPH_HPP
#define INF 0x3f3f3f3f

#include <vector>
#include <list>
#include "city.hpp"

using namespace std;
class Graph {
    list<City> **graph;
    int length;
public:
    Graph(int num_vertices);
    void addVertex(const int originId,const City city);
    void print();
    int dijkstra(int destinyCityId);

private:
};

#endif // GRAPH_HPP