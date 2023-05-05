#ifndef NodeCity_AUX_HPP
#define NodeCity_AUX_HPP

using namespace std;
#include <list>
#include <queue>
#include "city.hpp"
class NodeCityAux
{
    

public:
    City *city;
    int prev;
    NodeCityAux *next;
    NodeCityAux( City * city, int prev);

private:
};

#endif // NodeCity_HPP