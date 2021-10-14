#include <iostream>
#include "include/Utils.h"
// #include "include/config.h"
// #include "include/MapElement.h"
// #include "include/DisplayStruct.h"
#include "include/Player.h"
// #include "include/Framebuffer.h"

// #include "include/structs.h"
// #include 
#include "include/Display.h"
#include <unistd.h>

using namespace Pong;

int main()
{
    Display d;
    struct winsize terminalsize = getTerminalSize();
    std::cout << "Row: " << terminalsize.ws_row << ", Col: " << terminalsize.ws_col << std::endl;
    Framebuffer framebuffer = Framebuffer(terminalsize.ws_col, terminalsize.ws_row);
    Framebuffer *fb_ptr = &framebuffer;
    // sleep(5);
    // char data = 'B';
    // framebuffer.putchar(data, 2, 3);

    //You have to save this return struct, because otherwise it will get optimized away
    struct DisplayStruct l;
    // l.width = 40;
    // l.height = 80;
    // std::cout << l.width << "\t" << l.height << std::endl;
    l = d.start(fb_ptr);

    // Player p = Player(&framebuffer);

    // struct MapElement me;
    // me.data = 'A';
    // me.x = 1;
    // me.y = 1;
    // me.width = 1;
    // me.height = 1;
    // framebuffer.putElement(me);
    // framebuffer << me;

    // Player p = Player(fb_ptr);

    // int i = 0;
    /*     while (true)
    {
        // me.data = i % 2000000 == 0 ? '_' :'*';
        // i++;
    } */

    sleep(10);
    // KeyboardHandler kbd;
    // kbd.start();
    // p.stopKeyboardHandler();

    // d.stopDisplay();

    // sleep(1000);
}