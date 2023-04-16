#include <iostream>
#include "graph.hpp"
#include <list>
#define INF -1

using namespace std;

int main(int argc, char const *argv[]) {
    int n, a;

    cin>> n>> a;

    int **graph = new int *[n];

    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[a];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a; j++)
        {
            int origin, destin, weight;
            if(weight%2!=0){
                continue;
            }
            cin >> origin >> destin >> weight;
            graph[origin-1][destin-1] = weight;
        }
    }
    return 0;
}