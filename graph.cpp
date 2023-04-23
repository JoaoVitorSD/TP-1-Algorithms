#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int num_vertices)
{
   graph = new list<City> *[num_vertices];
   length = num_vertices;
   for (int i = 0; i < num_vertices; i++)
   {
      graph[i] = new list<City>();
   }
}

void Graph::addVertex(const int originId, City city)
{
   graph[originId]->push_back(city);
}

void Graph::print()
{

   for (int i = 0; i < length; i++)
   {
      for (City c : *graph[i])
      {
         cout << i << " " << c.getCityId() << " " << c.getDistance() << "\n";
      }
   }
}

int Graph::dijkstra(int destinyCityId)
{
   int *distance = new int[length];
   bool finded = false;

   list<int> *priorityQueue = new list<int>;
   list<int> *path = new list<int>();
   priorityQueue->push_back(0);

   int pathed = false;

   distance[0] = 0;
   for (int i = 1; i < length; i++)
   {
      distance[i] = INF;
   }

   while (!priorityQueue->empty())
   {

      //TODO implementar lista de prioridade

      int first = priorityQueue->front();
      priorityQueue->pop_front();

      path->push_back(first);

      pathed = false;
      for (City c : *graph[first]) 
      {
         if (distance[c.getCityId()] > distance[first] + c.getDistance() || distance[c.getCityId()] == INF)
         {
            // Se não tiver sido explorado, adiciona a lista de prioridade

            if (distance[c.getCityId()] == INF && c.getCityId() != length-1)
            {
               // cout << "path: "<< first+1<< " "<< c.getCityId()+1<< endl;
               priorityQueue->push_front(c.getCityId());
               pathed = true;
            }
            // cout << first<<" " <<distance[first] << endl;
            if (c.getCityId() != length - 1)
            {
               distance[c.getCityId()] = distance[first] + c.getDistance();
            }
            else if (c.getCityId() == length - 1 && path->size() % 2 == 0)
            {
               // cout<< "FINDED "<< path->size()<<endl;
               finded = true;
               distance[c.getCityId()] = distance[first] + c.getDistance();
            }
         }
      }
      if (!pathed)
      {
         path->pop_back();
      }
      if (finded)
      {
         return distance[destinyCityId];
      }
   }
   return -1;
}