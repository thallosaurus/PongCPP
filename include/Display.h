#include "Framebuffer.h"

namespace Pong
{
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