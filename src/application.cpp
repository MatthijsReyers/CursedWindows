
#include "./../lib/application.hpp"

#include <ncurses.h>
#include <locale.h>
#include <iostream>
#include <sstream>

namespace cw
{
    /**
     * Contains all setup code needed for ncurses
     */
    application::application()
    {
        // Setup nCurses.
        setlocale(LC_ALL, "");
        mousemask(ALL_MOUSE_EVENTS, 0);
        initscr();
        keypad(stdscr, true);
        noecho();

        // Setup nCurses colors.
        if (has_colors())
        {
            use_default_colors();
            start_color();
            
            init_pair(0, -1, -1);	// DEFAULT
            init_pair(1, 0, -1);	// BLACK
            init_pair(2, 1, -1);	// RED
            init_pair(3, 2, -1); 	// BLUE
            init_pair(4, 3, -1);	// GREEN
            init_pair(5, 4, -1);	// YELLOW
            init_pair(6, 5, -1);	// PURPLE
            init_pair(7, 6, -1);	// CYAN
            init_pair(8, 7, -1);	// WHITE
            init_pair(9, COLOR_BLACK, COLOR_WHITE); // CURSOR
        }
    }

    int application::start()
    {
        try {
            // int x, y;
            // getmaxyx(stdscr, x, y);
            this->running = true;
            // this->mainWidget->resize(0,0,x,y);
            // this->mainWidget->draw();
            while (this->running)
            {
                // Get raw ncurses input.
                int rawInput = getch();

                // 
                // this->run();

                std::stringstream ss;
                ss << "Recieved: 0x" << std::hex << rawInput << " " << std::dec << rawInput << " " << char(rawInput) << std::endl;

                // switch (rawInput)
                // {
                // case KEY_RESIZE:
                //     getmaxyx(stdscr, x, y);
                //     this->mainWidget->resize(0,0,x,y);
                //     break;
                
                // default:
                //     break;
                // }

                // Do all the drawing stuff.
                clear();
                // this->mainWidget->draw();
                mvaddstr(0,0,ss.str().c_str());
                refresh();
            }
        }
        catch (char* err) {
            std::cout << err << std::endl;
            this->quit(1);
        }

        return this->exitcode;
    }

    void application::quit(int code /* = 0 */)
    {
        endwin();
        this->exitcode = code;
        this->running = false;
    }

    void application::setMainWidget(std::shared_ptr<Widget> widget)
    {
        this->mainWidget = widget;
    }

    std::shared_ptr<Widget> application::getMainWidget()
    {
        return this->mainWidget;
    }
}
