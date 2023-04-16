#include <iostream>
#include "graph.hpp"
#include <list>
#define INF -1

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
        graph->addVertex(origin, City(destiny, weight));
     
    }
    graph->print();
    return 0;
}