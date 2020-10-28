#pragma once

#include "widget.hpp"

#include <memory>

namespace cw
{
    class application
    {
    public:

        // Contains all the setup for ncurses.
        // ====================================================================
        application();

        // Should be called to begin the event loop and drawing of UI elements.
        // ====================================================================
        int start();

        // Can be called from within run to properly exit the application.
        // ====================================================================
        void quit(int exitcode = 0);



        void setMainWidget(std::shared_ptr<Widget> widget);
        std::shared_ptr<Widget> getMainWidget();

    protected:
    
        // Should be overwritten by the user and contain most of the business 
        // logic of the application.
        // ====================================================================
        virtual void run() {};

    private:
        std::shared_ptr<Widget> mainWidget;
        bool running = false;
        int exitcode = 0;
    };
}
