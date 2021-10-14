#ifndef PONG_FRAMEBUFFER_CONSUMER_H
#define PONG_FRAMEBUFFER_CONSUMER_H

#include "Framebuffer.h"

namespace Pong
{
    struct MapElement;

    class FramebufferConsumer
    {
    protected:
        int x, y;

    public:
        //This method gives its character back
        virtual struct MapElement *getCharacter()=0;
        Framebuffer *fb;
        FramebufferConsumer(Framebuffer *framebuffer);
        virtual ~FramebufferConsumer()=0;
        void overlay();
    };

}

#endif