#include "priority_queue.hpp"
#include <iostream>
PriorityQueue::PriorityQueue()
{

    head = nullptr;
}

void PriorityQueue::addCity(City *city)
{
    if (head == nullptr)
    {
        head = new NodeCity(city);
        return;
    }
    if(head->next == nullptr){
        head->next = new NodeCity(city);
        return;
    }
    NodeCity *auxNode = head->next;
    NodeCity *prevNode = auxNode;
    while (auxNode->next != nullptr)
    {
        prevNode = auxNode;
        auxNode = auxNode->next;
        if (prevNode->city->getDistance() > city->getDistance())
        {
            NodeCity *newNode = new NodeCity(city);
            prevNode->next = newNode;
            newNode->next = auxNode;

            auxNode = head->next;
            while (auxNode != nullptr)
            {
                auxNode = auxNode->next;
            }
            return;
        }
    }
    prevNode->next = new NodeCity(city);
    auxNode = head->next;
    while (auxNode != nullptr)
    {
        auxNode = auxNode->next;
    }
}

int PriorityQueue::popFirst()
{

    int cityId = head->city->getCityId();
    NodeCity *auxNode = head->next;
    NodeCity *auxHead = head;
    head = head->next;

    delete auxHead;


    while (auxNode != nullptr)
    {
        auxNode = auxNode->next;
    }
    return cityId;
}
bool PriorityQueue::notEmpty()
{
    return head != nullptr;
}