#include "priority_queue_aux.hpp"
#include <iostream>


PriorityQueueAux::PriorityQueueAux()
{

    head = nullptr;
}

void PriorityQueueAux::addCity(City *city, int prev)
{
    NodeCityAux *auxNode = head;

    NodeCityAux * newNode = new NodeCityAux(city, prev);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    if(head->city->getDistance()> city->getDistance()){
        newNode->next = head;
        head = newNode;
        return;
    }

    while (auxNode->next != nullptr && auxNode->next->city->getDistance()<city->getDistance())
    {
        auxNode = auxNode->next;
    }

    newNode->next = auxNode->next;
    auxNode->next = newNode;
}
void PriorityQueueAux::print(){
    NodeCityAux *auxNode = head;
    while (auxNode!= nullptr)
    {
        std::cout << auxNode->city->getCityId()+1 << " " << auxNode->city->getDistance() <<" ";
        auxNode = auxNode->next;
    }
    cout<<endl;
}
pair<int,int>   PriorityQueueAux::popFirst()
{


    int cityId = head->city->getCityId();
    int prev = head->prev;

    NodeCityAux * aux = head;
    head = head->next;

    delete aux;

    return make_pair(cityId, prev);
}
bool PriorityQueueAux::notEmpty()
{
    return head != nullptr;
}