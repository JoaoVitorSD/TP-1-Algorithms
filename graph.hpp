#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <list>
#include "city.hpp"

using namespace std;
class Graph {
    list<list<City>> *graph;
public:
    Graph(int num_vertices);
    void addEdge(const int cityId);
    void addVertex(const City city);
    int shorterDistance(const int originCityId, const int destinyCityid);


private:
};

#endif // GRAPH_HPP