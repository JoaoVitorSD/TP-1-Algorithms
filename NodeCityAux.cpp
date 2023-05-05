#include "NodeCityAux.hpp"

NodeCityAux::NodeCityAux(City *city, int prev){
    this->city = city;
    this-> next = nullptr;
    this-> prev = prev;
}


