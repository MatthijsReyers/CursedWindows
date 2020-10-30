# Cursed windows

## Important: CW is still under development and may still radically change in design.

Orignially developed for the [HexMe](https://github.com/MatthijsReyers/HexMe) hex editor, Cursed Windows is a C++ UI library that is based on the popular C library `ncurses`. 
It aims to provide a lot of basic functionalities and abstractions that will help with seperating the UI drawing related code from the buiness logic and keep the codebase as a whole more organized.

## Design
The widgets and layout system used by Cursed Windows was inspired by the layout system used by Java Swing and some other GUI libraries.
The callbacks and event handeling system was inspired by general UI programming in Javascript/HTML. 
