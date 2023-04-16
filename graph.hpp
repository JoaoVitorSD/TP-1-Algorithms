#ifndef GRAPH_HPP
#define GRAPH_HPP

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
    int shorterDistance(const int originCityId, const int destinyCityid);
    void print();

private:
};

#endif // GRAPH_HPP