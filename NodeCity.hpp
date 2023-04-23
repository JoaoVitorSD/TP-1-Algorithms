#ifndef NodeCity_HPP
#define NodeCity_HPP

using namespace std;
#include <list>
#include <queue>
#include "city.hpp"
class NodeCity
{
    

public:
    City *city;
    
    NodeCity *next;
    NodeCity( City * city);

private:
};

#endif // NodeCity_HPP