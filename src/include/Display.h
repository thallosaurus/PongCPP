#ifndef PONG_DISPLAY_H
#define PONG_DISPLAY_H

#include "Framebuffer.h"
#include "structs.h"
#include <pthread.h>

namespace Pong
{
    struct DisplayStruct;

    class Display
    {
    public:
        Display();
        ~Display();

        struct DisplayStruct start(Framebuffer *fb);

        static void *display(void *arg);

        friend void stopDisplay();
        void stopDisplay();

    private:
        pthread_t displayThread;
        bool running = true;
    };

}

#endif