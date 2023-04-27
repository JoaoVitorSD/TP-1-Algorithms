#include "city.hpp"
#include <iostream>

City::City(const int cityId, const int distance){
    this->cityId = cityId;
    this->distance = distance;
}

bool City::operator==(const City &s){ return s.cityId == cityId; }
bool City::operator!=(const City &s){ return !operator==(s); }