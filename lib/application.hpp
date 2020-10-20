#pragma once

namespace cw
{
    class application
    {
    public:
        application() {};

        // Contains all the setup for ncurses.
        int start();
        void quit(int exitcode = 0);

        virtual void setup();
        virtual void run();
    
    protected:

    private:
        bool running = false;

    };
}
