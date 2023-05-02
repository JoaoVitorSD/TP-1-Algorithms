#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

using namespace std;
#include <list>
#include <queue>
#include "NodeCity.hpp"
class PriorityQueue
{
    NodeCity * head;


    int length;

public:
    PriorityQueue();
    void addCity( City * city);
    void print();
    // void print();
    bool notEmpty();
    int popFirst();

private:
};

#endif // PRIORITY_QUEUE_HPP