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
   list<int> **visited = new list<int> *[length];

   PriorityQueue *priorityQueue = new PriorityQueue();

   priorityQueue->addCity(new City(0, 0));

   pathDistance[0] = 0;
   for (int i = 0; i < length; i++)
   {
      distance[i] = INF;
      visited[i] = new list<int>();
      pathDistance[i] = 1;
      for (City c : *graph[i])
      {
         visited[i]->push_front(c.getCityId());
      }
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
            
               if (distance[c.getCityId()]/(pathDistance[first]+1)> ((distance[first] + c.getDistance())/(pathDistance[c.getCityId()]+1)))
               {
                  pathDistance[c.getCityId()] = pathDistance[first] + 1;
                  distance[c.getCityId()] = distance[first] + c.getDistance();
                  priorityQueue->addCity(new City(c.getCityId(), (distance[first] + c.getDistance())/pathDistance[c.getCityId()]));
               }
         }
         if ((pathDistance[first] + 1) % 2 == 0 && distance[c.getCityId()] > distance[first] + c.getDistance())
         {

            finded = true;
            distance[c.getCityId()] = distance[first] + c.getDistance();
         }
      }
   }
   return finded ? distance[destinyCity] : -1;
}
int Graph::dfs(list<int> **visited, const int vertex, const int distance, const int edgeCount){

   for(City c: *graph[vertex]){
      if(c.getCityId() == destinyCity && edgeCount%2==0){
         return distance+c.getDistance();
      }
      else if(notVisited(visited, vertex, c.getCityId())){
         remove(visited, vertex, c.getCityId());
         dfs(visited, c.getCityId(), distane+c.getDistance(), edgeCount+1)
      }
   }
   return -1;
}
bool Graph::notVisited(list<int> **notVisitedsVertex, const int vertex, const int parent)
{
   for (int i : *notVisitedsVertex[vertex])
   {
      if (i == parent)
      {
         return true;
      }
   }
   return false;
}

void Graph::remove(list<int> **notVisitedsVertex, const int vertex, const int parent)
{
   notVisitedsVertex[vertex]->remove(parent);
}