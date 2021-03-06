#ifndef PONG_UTILS_H
#define PONG_UTILS_H

#include <sys/ioctl.h>
#include <unistd.h>
// #include "structs.h"
#include <iostream>

// namespace Utils
// {
// using namespace Pong;
inline int IntToXY(int width, int x, int y)
{
    return (y * width) + x;
}

inline struct winsize getTerminalSize()
{
    int cols = 80;
    int lines = 24;
    struct winsize ts;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
    cols = ts.ws_col;
    lines = ts.ws_row;
    return ts;
}

// inline struct winsize getTerminalSize();

void clearConsole();

void interruptHandler(int sigcode);
// }

#endif