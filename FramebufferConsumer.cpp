#include "include/Framebuffer.h"
#include "include/FramebufferConsumer.h"

namespace Pong
{
    class FramebufferConsumer
    {
    protected:
        int x, y;

    public:
        Framebuffer *fb;
        FramebufferConsumer(Framebuffer *framebuffer)
        {
            fb = framebuffer;
            x = 0;
            y = 0;
            // fb->addConsumer(this);
        }
        virtual ~FramebufferConsumer()
        {
        }

        void overlay()
        {
        }

        //This method gives its character back
        virtual struct MapElement *getCharacter() = 0;
    };

}