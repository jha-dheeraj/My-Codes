#ifndef _FACTORY_HPP_
#define _FACTORY_HPP_

#include"bike.hpp"
#include"car.hpp"

class Factory
{
    public:
        static Vehicle* getVehicle(std::string vType);

};

#endif