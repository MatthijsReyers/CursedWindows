#pragma once

#include "widget.hpp"

#include <memory>
#include <mutex>

namespace cw
{
    class application
    {
    public:
        application();

        int start();
        void quit(int exitcode = 0);

        void setMainWidget(std::shared_ptr<Widget> widget);
        std::shared_ptr<Widget> getMainWidget();

    protected:
    
        /**
         * The run method should contain all of the application specific setup
         * and serves as the main entry point of the application. 
         * 
         * It is unimplemented by default and any implementations of the 
         * cw::application class must implement this method as it is called by
         * the start() method.
         */
        virtual void run() = 0;

    private:
        std::shared_ptr<Widget> mainWidget;
        bool running = false;
        int exitcode = 0;
    };
}
