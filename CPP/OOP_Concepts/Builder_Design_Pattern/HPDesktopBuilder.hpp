#ifndef _HP_DESKTOP_BUILDER_
#define _HP_DESKTOP_BUILDER_

#include"DesktopBuilder.hpp"

class HPDesktopBuilder : public DesktopBuilder
{
    void buildMonitor();
    void buildMouse();
    void buildKeyboard();
    void buildProcessor();
    void buildRam();
};

#endif //_HP_DESKTOP_BUILDER_