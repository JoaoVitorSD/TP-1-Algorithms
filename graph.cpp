#include "graph.hpp"
#include <iostream>
#include "priority_queue_aux.hpp"
#include <algorithm>

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
   for (City c : *graph[originId])
   {
      if (c.getCityId() == city.getCityId())
      {
         return;
      }
   }
   graph[originId]->push_back(city);
   graph[city.getCityId()]->push_back(City(originId, city.getDistance()));
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
Graph Graph::bfs()
{

   list<int> *pq = new list<int>();

   bool **visited = new bool *[length];
   int *pathDistance = new int[length];
   bool *candidates = new bool[length];
   bool * saved = new bool [length];
   for (int i = 0; i < length; i++)
   {
      candidates[i] = false;
      saved[i] = false;
          pathDistance[i] = 0;
      visited[i] = new bool[length];
      for (int j = 0; j < length; j++)
      {
         visited[i][j] = false;
      }
   }

   pathDistance[0] = 0;

   for (City c : *graph[destinyCity])
   {
      candidates[c.getCityId()] = true;
   }

   pq->push_front(0);
   Graph graphAux = Graph(length);
   while (!pq->empty())
   {
      int u = pq->front();
      pq->pop_front();

      for (City c : *graph[u])
      {
{

         if (visited[u][c.getCityId()])
         {
            continue;
         }
         else
         {
            visited[u][c.getCityId()] = true;
         }

}
         if (candidates[c.getCityId()])
         {
            pathDistance[c.getCityId()] = pathDistance[u] + 1;
            pq->push_front(c.getCityId());
            if (pathDistance[c.getCityId()] % 2 == 1)
            {
               saved[c.getCityId()] = true;
               graphAux.addVertex(u, City(c.getCityId(), c.getDistance()));
            }
         }
         else if (c.getCityId() != destinyCity)
         {
            pathDistance[c.getCityId()] = pathDistance[u] + 1;
            graphAux.addVertex(u, City(c.getCityId(), c.getDistance()));
            pq->push_front(c.getCityId());
         }
      }
   }
   for(City c : *graph[destinyCity]){
      if(saved[c.getCityId()]){
         graphAux.addVertex(c.getCityId(), City(destinyCity, c.getDistance()));
      }
   }
   return graphAux;
}
int Graph::dijkstra()
{
   int *distance = new int[length];
   int *pathDistance = new int[length];
   bool finded = false;
   list<int> pq = list<int>();


   pathDistance[0] = 0;
   bool *candidates = new bool[length];
   pq.push_front(0);
   for (int i = 0; i < length; i++)
   {
      candidates[i] = false;
      if(i>0){
      pq.push_back(i);
      }
      distance[i] = INF;
      pathDistance[i] = 0;
   }
   pathDistance[0] = 0;
   distance[0] = 0;

   for (City c : *graph[destinyCity])
   {
      candidates[c.getCityId()] = true;
   }

   while (!pq.empty())
   {

      // TODO implementar lista de prioridade

      int first = pq.front();
      pq.pop_front();
      for (City c : *graph[first])
      {
         if (distance[c.getCityId()] > distance[first] + c.getDistance())
         {
            distance[c.getCityId()] = distance[first] + c.getDistance();
         }
      }
   }
      if (distance[destinyCity] == INF)
      {
         return -1;
      }
      return distance[destinyCity];
}
