#include "graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int num_vertices)
{
   graph = new list<City> *[num_vertices];
   length = num_vertices;

   destinyCity = length - 1;
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
         cout << i + 1 << " -> " << c.getCityId() + 1 << " " << c.getDistance() << "\n";
      }
   }
}

int Graph::dijkstra()
{
   int *distance = new int[length];
   int *pathDistance = new int[length];
   bool finded = false;
   PriorityQueue *priorityQueue = new PriorityQueue();

   priorityQueue->addCity(new City(0, 0));

   pathDistance[0] = 0;
   for (int i = 0; i < length; i++)
   {
      distance[i] = INF;
      pathDistance[i] = 1;
   }
   pathDistance[0] = 0;
   distance[0] = 0;

   while (priorityQueue->notEmpty())
   {

      // TODO implementar lista de prioridade

      int first = priorityQueue->popFirst();

      for (City c : *graph[first])
      {
         if (c.getCityId() != destinyCity)
         {
               if ((distance[c.getCityId()]> ((distance[first] + c.getDistance()))))
               {
                  pathDistance[c.getCityId()] = pathDistance[first] + 1;
                  distance[c.getCityId()] = distance[first] + c.getDistance();
                  priorityQueue->addCity(new City(c.getCityId(), distance[c.getCityId()]));
               }
         }else if ((pathDistance[first] + 1) % 2 == 0 && distance[c.getCityId()] > distance[first] + c.getDistance())
         {
            finded = true;
            distance[c.getCityId()] = distance[first] + c.getDistance();
         }else{
            cout << first;
            int closeDistance = auxDijkstra(first);
            cout << "Distance "<< (distance[first] + c.getDistance()+ closeDistance);
            finded = true;
            if(closeDistance!=-1){
            distance[c.getCityId()] = distance[first] + c.getDistance() + closeDistance;
            }
         }
      }
   }
   return finded ? distance[destinyCity] : -1;
}

int Graph::auxDijkstra(int destiny)
{
   int *distance = new int[length];
   int *pathDistance = new int[length];
   bool finded = false;
   PriorityQueue *priorityQueue = new PriorityQueue();

   priorityQueue->addCity(new City(destiny, 0));

   for (int i = 0; i < length; i++)
   {
      distance[i] = INF;
      pathDistance[i] = 0;
   }
   pathDistance[destiny] = 0;
   distance[destiny] = 0;

   while (priorityQueue->notEmpty())
   {

      // TODO implementar lista de prioridade

      int first = priorityQueue->popFirst();

      for (City c : *graph[first])
      {
            if(c.getCityId()==destiny){
               cout << endl<<first<<" "<<pathDistance[first]<<" "<<distance[first] <<"\n";
            }
            if (distance[c.getCityId()] > ((distance[first] + c.getDistance())) )
            {
                  pathDistance[c.getCityId()] = pathDistance[first] + 1;
                  distance[c.getCityId()] = distance[first] + c.getDistance();
                  priorityQueue->addCity(new City(c.getCityId(), distance[c.getCityId()]));
            }else if(c.getCityId()==destiny&& pathDistance[first]%2==0&& pathDistance[first]>1){
               return distance[first] + c.getDistance();
            }
   }
   }
   return  -1;
}