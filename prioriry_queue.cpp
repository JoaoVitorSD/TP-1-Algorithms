#include "priority_queue.hpp"
#include <iostream>
PriorityQueue::PriorityQueue()
{

    head = nullptr;
}

void PriorityQueue::addCity(City *city)
{
    NodeCity *auxNode = head;

    NodeCity *newNode = new NodeCity(city);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    if (head->city->getDistance() > city->getDistance())
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    while (auxNode->next != nullptr && auxNode->next->city->getDistance() < city->getDistance())
    {
        auxNode = auxNode->next;
    }

    newNode->next = auxNode->next;
    auxNode->next = newNode;
}
void PriorityQueue::print()
{
    NodeCity *auxNode = head;
    while (auxNode != nullptr)
    {
        std::cout << auxNode->city->getCityId() + 1 << " " << auxNode->city->getDistance() << " ";
        auxNode = auxNode->next;
    }
    cout << endl;
}
int PriorityQueue::popFirst()
{

    int cityId = head->city->getCityId();

    NodeCity *aux = head;
    head = head->next;

    delete aux;

    return cityId;
}
bool PriorityQueue::notEmpty()
{
    return head != nullptr;
}