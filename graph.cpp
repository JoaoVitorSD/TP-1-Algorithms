#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int num_vertices){
   graph = new list<City> *[num_vertices];
   length = num_vertices;
   for (int i = 0; i < num_vertices; i++){
      graph[i] = new list<City>();
   }
}

void Graph::addVertex(const int originId,  City city)
{
   graph[originId]->push_back(city);
}

void Graph::print()
{

   for (int i = 0; i < length; i++){
      for (City c : *graph[i]){
         cout << i << " " << c.getCityId() << " " << c.getDistance() << "\n";
      }
   }
}

int Graph::dijkstra(int destinyCityId){
   int *distance = new int[length];
   bool finded = false;
   list<int> *priorityQueue = new list<int>;

   priorityQueue->push_back(0);

   distance[0] = 0;
   for (int i = 1; i < length; i++){
      distance[i] = INF;
   }

   for (int i = 1;!priorityQueue->empty();i++){

      int first = priorityQueue->front();
      priorityQueue->pop_front();

      for (City c : *graph[first]){
         if (distance[c.getCityId()] > distance[first] + c.getDistance() || distance[c.getCityId()] == INF){
            distance[c.getCityId()] = distance[first] + c.getDistance();
            //Se não tiver sido explorado, adiciona a lista de prioridade
            if (distance[c.getCityId()] != INF){
               priorityQueue->push_front(c.getCityId());
            }
            if (c.getCityId() == length - 1&& i%2!=1)
            {
               finded = true;
            }
         }
      }
      if (finded)
      {
         return distance[destinyCityId];
      }
   }
   return -1;
}