#include"client.hpp"

int main()
{
    std::string test;
    std::cout<<"Enter the type of vehicle to be constructed:"<<std::endl;
    std::cin>>test;
    Vehicle* p=Factory::getVehicle(test);
    if(p)
        p->createVehicle();
    return 0;
}