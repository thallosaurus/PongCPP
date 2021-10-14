#include <sys/ioctl.h>
#include <unistd.h>
// #include "structs.h"
#include <iostream>

// namespace Utils
// {
    // using namespace Pong;




    void clearConsole()
    {
        std::cout << "\033c";
    }

    void interruptHandler(int sigcode)
    {
        // clearConsole();
        std::cout << "BYE!";
        exit(0);
    }
// }