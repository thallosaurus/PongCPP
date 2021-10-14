#ifndef STRUCTS_H
#define STRUCTS_H

#include "Display.h"
#include "FramebufferConsumer.h"

namespace Pong
{
    struct DisplayStruct
    {
        Framebuffer *framebuffer;
        unsigned int width, height;
        bool *exitCondition;
    };
    struct MapElement
    {
        int x, y, width, height;
        char data;
    };
}

#endif