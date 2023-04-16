#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int num_vertices) {
   this->graph = new list<list<City>>;
}
