#include "include/Framebuffer.h"
#include "include/FramebufferConsumer.h"
#include "include/structs.h"

namespace Pong
{
    // class FramebufferConsumer
    // {
    // protected:
    // int x, y;

    // public:
    // Framebuffer *fb;

    FramebufferConsumer::FramebufferConsumer(Framebuffer *framebuffer)
    {
        fb = framebuffer;
        x = 0;
        y = 0;
        // fb->addConsumer(this);
    }
    // virtual FramebufferConsumer::~FramebufferConsumer() = 0;

    void FramebufferConsumer::overlay()
    {
    }

    //This method gives its character back
    // virtual struct MapElement *getCharacter() = 0;
}