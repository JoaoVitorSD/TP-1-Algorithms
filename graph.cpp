#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int num_vertices)
{
   graph = new list<City> *[num_vertices];
   length = num_vertices;

   destinyCity = length-1;
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

int Graph::dijkstra()
{
   int *distance = new int[length];
   int *pathDistance = new int[length];
   bool finded = false;

   PriorityQueue *priorityQueue = new PriorityQueue();

   priorityQueue->addCity(new City(0,0));


   distance[0] = 0;
   pathDistance[0] = 0;
   for (int i = 1; i < length; i++)
   {
      distance[i] = INF;
   }

   while (priorityQueue->notEmpty())
   {

      //TODO implementar lista de prioridade

      int first = priorityQueue->popFirst();

      cout <<"City: "<<first+1<< " PATH : " << pathDistance[first] << "\n";

      for (City c : *graph[first]) 
      {
         cout << "   Destiny: "<< c.getCityId()+1<<" DISTANCE: "<< c.getDistance()<< " "<< distance[c.getCityId()]<<"\n";
         if (distance[c.getCityId()] == INF && c.getCityId()!= destinyCity){
            cout << "   PUSHED: "<< c.getCityId()+1<<"\n";
            priorityQueue->addCity(new City(c.getCityId(), c.getDistance()));
            pathDistance[c.getCityId()] = pathDistance[first] + 1;
            distance[c.getCityId()] = distance[first] + c.getDistance();

         }else if (distance[c.getCityId()] > distance[first] + c.getDistance() || c.getCityId() == destinyCity)
            {
               // Se não tiver sido explorado, adiciona a lista de prioridade

               if (c.getCityId() != destinyCity)
               {
                  distance[c.getCityId()] = distance[first] + c.getDistance();
               }
               else if (c.getCityId() == destinyCity && (pathDistance[first] + 1) % 2 == 0)
               {
                  finded = true;
                  distance[c.getCityId()] = distance[first] + c.getDistance();
               }
            }
      }
      if (finded)
      {
         return distance[destinyCity];
      }
   }
   return -1;
}