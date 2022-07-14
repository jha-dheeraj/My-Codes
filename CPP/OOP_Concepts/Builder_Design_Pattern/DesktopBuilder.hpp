#ifndef _DESKTOP_BUILDER_HPP_
#define _DESKTOP_BUILDER_HPP_

#include"Desktop.hpp"

class DesktopBuilder 
{
    protected:
        Desktop* desktop;
    public:
        DesktopBuilder()
        {
            desktop = new Desktop();
        }

        virtual void buildMonitor() = 0;
        virtual void buildMouse() = 0;
        virtual void buildKeyboard() = 0;
        virtual void buildProcessor() = 0;
        virtual void buildRam() = 0;
        virtual Desktop* getDesktop()
        {
            return desktop;
        }


};

#endif //_DESKTOP_BUILDER_HPP_