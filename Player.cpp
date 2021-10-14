#include "include/Player.h"
#include "include/FramebufferConsumer.h"
#include "include/KeyboardHandler.h"
#include "include/MapElement.h"

namespace Pong
{

    class Player : public FramebufferConsumer, public KeyboardHandler
    {
    private:
        const char character = 'O';
        // KeyboardHandler kbd;

    public:
        Player(Framebuffer *f) : FramebufferConsumer(f), KeyboardHandler()
        {
            // kbd = KeyboardHandler();
            struct DisplayStruct *s = start();
            // struct Display::DisplayStruct f = start();
            // s = &f;
        }

        struct MapElement *getCharacter()
        {
            struct MapElement *element = new struct MapElement;
            element->data = character;
            element->x = this->x;
            element->y = this->y;
            element->width = 1;
            element->height = 1;

            return element;
        }

        virtual void onKeyPress(char keyCode)
        {
            switch (keyCode)
            {
            case 's':
                this->y++;
                break;
            }
        }
    };
}