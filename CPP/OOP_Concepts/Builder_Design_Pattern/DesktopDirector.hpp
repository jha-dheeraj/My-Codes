#ifndef _DESKTOPDIRECTOR_HPP_
#define _DESKTOPDIRECTOR_HPP_

#include"DesktopBuilder.hpp"

class DesktopDirector
{
    private:
        DesktopBuilder* desktopBuilder;

    public:
        DesktopDirector(DesktopBuilder* pdesktopBuilder)
        {
            desktopBuilder = pdesktopBuilder;
        }

        Desktop* buildDesktop()
        {
            desktopBuilder->buildMonitor();
            desktopBuilder->buildKeyboard();
            desktopBuilder->buildMouse();
            desktopBuilder->buildProcessor();
            desktopBuilder->buildRam();

            return desktopBuilder->getDesktop();
        }
};

#endif //_DESKTOPDIRECTOR_HPP_