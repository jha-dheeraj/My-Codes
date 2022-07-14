#include"Desktop.hpp"

void Desktop::setMonitor(std::string monitor)
{
    this->monitor=monitor;
}

void Desktop::setMouse(std::string mouse)
{
    this->mouse=mouse;
}

void Desktop::setKeyboard(std::string keyboard)
{
    this->keyboard=keyboard;
}

void Desktop::setRam(std::string ram)
{
    this->Ram=ram;
}

void Desktop::setProcessor(std::string processor)
{
    this->Processor=processor;
}

void Desktop::showSpecs()
{
        std::cout<<"This class configuring following coponents"<<std::endl;
        std::cout<< "Monitor = "<< this->monitor <<std::endl;
        std::cout<<"Mouse= "<< this->mouse <<std::endl;
        std::cout<<"Keyboard= "<< this->keyboard <<std::endl;
        std::cout<<"Ram = "<< this->Ram <<std::endl;
        std::cout<<"Processor = "<< this->Processor << std::endl;
        std::cout<<"_______________________________________________________"<<std::endl;
}