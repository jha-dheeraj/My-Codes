#include<iostream>


class Vehicle // Abstract Class
{
    public:
        virtual void CreateCar()=0; //pure virtual function
};

class car : public Vehicle
{
    public:
        void CreateCar()
        {
            std::cout<<"Creating car..."<<std::endl;
        }

};

int main()
{
    Vehicle *a1=new car;
    a1->CreateCar();
    return 0;
}