// #include "include/Framebuffer.h"
#include "include/Display.h"
#include "include/structs.h"
#include "include/config.h"
#include "include/Utils.h"
#include <chrono>

namespace Pong
{

    struct DisplayStruct
    {
        Framebuffer *framebuffer;
        unsigned int width, height;
        bool *exitCondition;
    };

    class Display
    {
    public:
        Display()
        {
            // signal(SIGINT, interruptHandler);
        }
        ~Display()
        {
            pthread_join(displayThread, NULL);
        }

        struct DisplayStruct start(Framebuffer *fb)
        {
            struct DisplayStruct dss;
            dss.framebuffer = fb;
            dss.width = fb->getWidth();
            dss.height = fb->getHeight();
            bool *r_ptr = &running;
            dss.exitCondition = r_ptr;
            pthread_create(&displayThread, NULL, display, (void *)&dss);
            // std::thread t = std::thread(&display, this);

            return dss;
        }

        static void *display(void *arg)
        {
            using namespace std::chrono;
            const struct DisplayStruct *data;
            data = (const struct DisplayStruct *)arg;

            high_resolution_clock::time_point now = high_resolution_clock::now();
            system_clock::rep nextFrame = 1000;
            time_t delta;

            int frameCounter = 0;
            while (*data->exitCondition)
            {
                high_resolution_clock::time_point yeet = high_resolution_clock::now();
                delta = duration_cast<nanoseconds>(yeet - now).count();
                if (delta > nextFrame)
                {
                    clearConsole();
                    nextFrame = delta + (1000 * 1000 * 100);
                    std::string s = data->framebuffer->getBufferAsString();
                    std::cout << s;
                    frameCounter++;
                }
            }
            DEBUG &&std::cout << "Thread Exit, Framecount: " << frameCounter << std::endl;
            pthread_exit(NULL);
        }

        friend void stopDisplay();
        void stopDisplay()
        {
            running = false;
            pthread_join(displayThread, NULL);
        }

    private:
        pthread_t displayThread;
        bool running = true;
    };
}