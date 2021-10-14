#ifndef PONG_UTILS_H
#define PONG_UTILS_H

#include <sys/ioctl.h>
#include <unistd.h>
// #include "structs.h"
#include <iostream>

// namespace Utils
// {
    // using namespace Pong;
    inline int IntToXY(int width, int x, int y);

    inline struct winsize getTerminalSize();

    void clearConsole();

    void interruptHandler(int sigcode);
// }

#endif