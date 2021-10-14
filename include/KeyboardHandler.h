#ifndef PONG_KEYBOARD_HANDLER_H
#define PONG_KEYBOARD_HANDLER_H

#include "Player.h"
#include "pthread.h"

namespace Pong
{
    class KeyboardHandler
    {
    private:
        static char *pressedKey;
        pthread_t handlerThread;
        bool running;

    public:
        KeyboardHandler();
        ~KeyboardHandler();

        static void *keyboardThread(void *arg);

        struct DisplayStruct start();

        void stopKeyboardHandler();
        virtual void onKeyPress(char keycode) = 0;
    };
}

#endif