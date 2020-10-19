
#include "./../lib/application.hpp"

#include <ncurses.h>
#include <locale.h>
#include <iostream>

namespace cw
{
    int application::start()
    {
        // Setup nCurses.
        setlocale(LC_ALL, "");
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

        try {
            running = true;
            while (this->running)
            {
                this->run();
            }
            
        }
        catch (char* err) {
            std::cout << err << std::endl;
            this->quit();
        }
    }
}