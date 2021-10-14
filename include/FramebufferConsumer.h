#include "Framebuffer.h"

namespace Pong
{
    struct MapElement {
        int x, y, width, height;
        char data;
    };
    class FramebufferConsumer
    {
    protected:
        int x, y;

    public:
        //This method gives its character back
        virtual struct MapElement *getCharacter()=0;
        Framebuffer *fb;
        FramebufferConsumer(Framebuffer *framebuffer);
        virtual ~FramebufferConsumer();
        void overlay();
    };

}