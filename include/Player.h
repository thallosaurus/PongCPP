#ifndef PONG_PLAYER_H
#define PONG_PLAYER_H

// #include "Framebuffer.h"
// #include "FramebufferConsumer.h"
#include "KeyboardHandler.h"
#include "structs.h"
#include "Player.h"

namespace Pong
{

    class Player : public FramebufferConsumer {
    public:
        Player(Framebuffer *f);

        struct MapElement *getCharacter();

        virtual void onKeyPress(char keyCode) = 0;

    private:
        const char character = '*';
    };
}

#endif