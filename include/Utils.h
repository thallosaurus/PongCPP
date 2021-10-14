#include <sys/ioctl.h>
#include <unistd.h>

namespace Pong
{

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
}