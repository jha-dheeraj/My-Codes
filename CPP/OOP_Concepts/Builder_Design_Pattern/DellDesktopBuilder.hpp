#ifndef _DELL_DESKTOP_BUILDER_
#define _DELL_DESKTOP_BUILDER_

#include"DesktopBuilder.hpp"

class DellDesktopBuilder : public DesktopBuilder
{
    void buildMonitor();
    void buildMouse();
    void buildKeyboard();
    void buildProcessor();
    void buildRam();
};

#endif //_DELL_DESKTOP_BUILDER_