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


   list<int> **visited = new list<int>*[length];

   PriorityQueue *priorityQueue = new PriorityQueue();

   priorityQueue->addCity(new City(0,0));


   pathDistance[0] = 0;
   for (int i = 0; i < length; i++)
   {
      distance[i] = INF;
      visited[i] = new list<int>();
      for(City c: *graph[i]){
         visited[i]->push_front(c.getCityId());
      }
   }
   distance[0] = 0;

   while (priorityQueue->notEmpty())
   {

      //TODO implementar lista de prioridade

      int first = priorityQueue->popFirst();


      for (City c : *graph[first]) 
      {
         if (c.getCityId()!= destinyCity && notVisited(visited,first,c.getCityId())){
            remove(visited, first,c.getCityId());
            priorityQueue->addCity(new City(c.getCityId(), c.getDistance()));
            pathDistance[c.getCityId()] = pathDistance[first] + 1;
            distance[c.getCityId()] = distance[first] + c.getDistance();
         }
         if (distance[c.getCityId()] > distance[first] + c.getDistance() || c.getCityId() == destinyCity)
            {
               // Se não tiver sido explorado, adiciona a lista de prioridade

               if (c.getCityId() != destinyCity)
               {
                  distance[c.getCityId()] = distance[first] + c.getDistance();
                  pathDistance[c.getCityId()] = pathDistance[first] + 1;
               }
               else if (c.getCityId() == destinyCity && (pathDistance[first] + 1) % 2 == 0)
               {
                  finded = true;
                  distance[c.getCityId()] = distance[first] + c.getDistance();
               }else{
                  // Decrementar a distância de first
                  // distance[first] = distance[first]-;
               }
            }
      }
   }
   return finded? distance[destinyCity]:-1;
}

bool Graph::notVisited(list<int> ** notVisitedsVertex, const int vertex, const int parent){
   for(int i : *notVisitedsVertex[vertex]){
      if(i ==parent){
         return true;
      }
   }
   return false;
}
void Graph::remove(list<int> ** notVisitedsVertex, const int vertex, const int parent){
   notVisitedsVertex[vertex]->remove(parent);
}