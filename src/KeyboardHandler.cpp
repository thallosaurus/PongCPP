// #include "include/structs.h"
// #include "include/Display.h"
#include <pthread.h>
#include <csignal>
#include "include/KeyboardHandler.h"
#include <iostream>
#include "include/config.h"

namespace Pong
{
    // class KeyboardHandler
    // {
    // private:
    // static char *pressedKey;
    // pthread_t handlerThread;
    // bool running = true;

    // public:
    KeyboardHandler::KeyboardHandler()
    {
        std::cout << '\033[?12l';
    }
    KeyboardHandler::~KeyboardHandler()
    {
        system("stty cooked echo");
    }

    void *KeyboardHandler::keyboardThread(void *arg)
    {
        const struct DisplayStruct *data;
        data = (const struct DisplayStruct *)arg;
        DEBUG &&std::cout << "[DEBUG] Keyboard Handler started thread" << std::endl;
        system("stty raw -echo");
        while (data->exitCondition)
        {
            char key = std::getchar();
        }
        pthread_exit(NULL);
    }

    struct DisplayStruct KeyboardHandler::start()
    {
        struct DisplayStruct dss;
        bool *running_ptr;
        running_ptr = &this->running;
        dss.exitCondition = running_ptr;
        dss.framebuffer = NULL;
        dss.width = 0;
        dss.height = 0;

        int rc = pthread_create(&handlerThread, NULL, keyboardThread, (void *)&dss);

        return dss;
    }
    void KeyboardHandler::stopKeyboardHandler()
    {
        this->running = false;
        // pthread_join(handlerThread, NULL);
        pthread_kill(handlerThread, SIGINT);
    }
}