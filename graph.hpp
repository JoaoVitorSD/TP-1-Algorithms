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

    int destinyCity;

public:
    const Graph(int num_vertices);
    void addVertex(const int originId,const City city);
    void print();
    int dijkstra();
    bool notVisited(const int vertex, const int parent);
    void remove(const int vertex, const int parent);



private:
};

#endif // GRAPH_HPP