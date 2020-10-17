#pragma once

namespace cw
{
    class application
    {
    public:

        // 
        int start();
        void quit(int exitcode = 0);

        virtual void run();

        // Contains all the setup for ncurses.
        application();
    
    protected:

    private:
        bool running = false;

    };
}
