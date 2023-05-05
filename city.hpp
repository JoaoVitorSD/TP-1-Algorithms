#ifndef CITY_HPP   
#define CITY_HPP

class City{

    public:
        City(const int cityId, const int distance);
        int getCityId(){return cityId;}
        int getDistance(){return distance;}
        bool operator==(const City &s);
        bool operator!=(const City &s);
     int cityId;
     int distance;

    private:
};

#endif              