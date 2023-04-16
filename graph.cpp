#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int num_vertices) {
   graph = new list<City>*[num_vertices+1];
   length = num_vertices;
   for(int i = 0; i < num_vertices+1;i++){
      graph[i] = new list<City>();
   }
}

void Graph::addVertex(const int originId,const City city){
   graph[originId]->push_back(city);
}

void Graph::print(){

   for(int i = 0; i < length ; i++){
      for( City c : *graph[i]){
         cout<<i<<" "<<c.getCityId()<<" "<<c.getDistance()<<"\n";
      }
   }
}