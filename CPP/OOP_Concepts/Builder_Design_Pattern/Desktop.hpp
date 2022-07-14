#ifndef _DESKTOP_HPP_
#define _DESKTOP_HPP_

#include<iostream>
#include<string>

class Desktop 
{
    private:
        std::string monitor;
        std::string mouse;
        std::string keyboard;
        std::string Ram;
        std::string Processor;

    public:
        void setMonitor(std::string monitor);
        void setMouse(std::string mouse);
        void setKeyboard(std::string keyboard);
        void setRam(std::string ram);
        void setProcessor(std::string processor);
        void showSpecs();
        


};

#endif