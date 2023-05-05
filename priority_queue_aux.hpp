#ifndef PRIORITY_QUEUE_AUX_HPP
#define PRIORITY_QUEUE_AUX_HPP

using namespace std;
#include <list>
#include <queue>
#include "NodeCityAux.hpp"
class PriorityQueueAux
{
    NodeCityAux * head;


    int length;

public:
    PriorityQueueAux();
    void addCity( City * city, int prev);
    void print();
    // void print();
    bool notEmpty();
    pair<int,int> popFirst();

private:
};

#endif // PRIORITY_QUEUE_HPP