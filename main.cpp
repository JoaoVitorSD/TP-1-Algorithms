#include <iostream>
#include "graph.hpp"
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, a;

    cin >> n >> a;

    Graph * graph = new Graph(n);


    for (int j = 0; j < a; j++){
        int origin, destiny, weight;
        cin >> origin >> destiny >> weight;
        if (weight % 2 != 0)
        {
            continue;
        }
        graph->addVertex(origin-1,  City(destiny-1, weight));
        graph->addVertex(destiny-1, City(origin-1, weight));
     
    }
    std::cout<<graph->dijkstra(n-1);
    return 0;
}