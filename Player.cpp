#include "include/Player.h"
// #include "include/FramebufferConsumer.h"
// #include "include/KeyboardHandler.h"
#include "include/structs.h"
// #include "include/MapElement.h"

namespace Pong
{

    // class Player : public FramebufferConsumer, public KeyboardHandler
    // {
    // public:
    Player::Player(Framebuffer *f) : FramebufferConsumer(f) {
        // kbd = KeyboardHandler();
        // struct DisplayStruct *s = start();
        // struct DisplayStruct f = start();
        // s = &f;
    }

    struct MapElement *Player::getCharacter()
    {
        struct MapElement *element = new struct MapElement;
        element->data = character;
        element->x = this->x;
        element->y = this->y;
        element->width = 1;
        element->height = 1;

        return element;
    }

    void Player::onKeyPress(char keyCode)
    {
        switch (keyCode)
        {
        case 's':
            this->y++;
            break;
        }
    }
}