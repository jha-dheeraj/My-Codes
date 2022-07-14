#include"factory.hpp"

Vehicle* Factory::getVehicle(std::string vType)
{
    Vehicle* temp;
    if(vType=="car")
    {
        temp = new Car();
    }else if(vType=="bike")
    {
        temp = new Bike();
    }else
    {
        std::cout<<"Wrong Vehicle Type."<<std::endl;
        temp = nullptr;
    }
    return temp;
}