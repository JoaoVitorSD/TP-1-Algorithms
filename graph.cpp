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

int Graph::dijkstra(int originCityId, int destinyCityId){
   int * distance = new int[length];
   bool finded  =false;
   list<int> * priorityQueue = new list<int>;
   priorityQueue->push_back(originCityId);

   for( int i = 0; i < length ; i++){
      distance[i]= INF;
   }
   distance[originCityId] = 0;

   while(!priorityQueue->empty()){
      int first = priorityQueue->front();
      priorityQueue->pop_front();

      for(City c: *graph[first]){
         cout<< c.getCityId()<< " "<< c.getDistance()<<" ";
         if (distance[c.getCityId()] > distance[first] + c.getDistance() || distance[c.getCityId()] == INF)
         {
            cout << "City - " << c.getCityId() << " Distance - " << c.getDistance() << "\n";
            distance[first] = distance[c.getCityId()] + c.getDistance();
            priorityQueue->push_back(c.getCityId());
            if(c.getCityId()==originCityId) finded=true;
         }
      }
      if(finded){
         return distance[destinyCityId];
      }
   }
   return -1;
}