#include "include/config.h"
#include "include/Framebuffer.h"
#include "include/Utils.h"
#include "include/structs.h"
#include <iostream>


namespace Pong
{
    class Framebuffer
    {
    private:
        int width, height;
        char *fb;

    public:
        Framebuffer(const int w, const int h) : width(w), height(h)
        {
            this->fb = new char[w * h + 1];

            if (this->fb)
            {
                DEBUG &&std::cout << "Array creation did work" << std::endl;
                resetBuffer();
            }
        }

        // std::list<FramebufferConsumer> consumers[10];
        // char currentConsumerCount = 0;

        ~Framebuffer()
        {
            DEBUG &&std::cout << "[DEBUG]Framebuffer destroyed" << std::endl;
            delete this->fb;
        }

        // void addConsumer(FramebufferConsumer cons) {
        // consumers[currentConsumerCount] = cons;
        // currentConsumerCount++;
        // }

        void resetBuffer()
        {
            for (int i = 0; i < this->width * this->height; i++)
            {
                this->fb[i] = ' ';
            }
            this->fb[this->width * this->height] = '\0';
        }

        char *getBuffer()
        {
            return this->fb;
        }

        std::string getBufferAsString()
        {
            std::string ret = (std::string)this->fb;

            for (int i = 1; i <= height; i++)
            {
                ret.insert(i * width, ((height - 1) == i ? "\n" : ""));
                // ret.insert(i * width, "\n");
            }

            return ret;
        }

        char getchar(int x, int y)
        {
            if (x * y > this->width * this->height)
            {
                throw "Index out of bounds";
            }

            return this->fb[IntToXY(this->width, x, y)];
        }

        void putchar(char data, int x, int y)
        {
            if (x < this->width && y < this->height)
            {
                int index = IntToXY(this->width, x, y);
                this->fb[index] = data;
            }
        }

        void putElement(struct MapElement e)
        {
            for (int y = 0; y < e.height; y++)
            {
                for (int x = 0; x < e.width; x++)
                {
                    this->putchar(
                        e.data,
                        e.x + x,
                        e.y + y);
                }
            }
        }

        int getWidth()
        {
            return width;
        }

        int getHeight()
        {
            return height;
        }

        friend Framebuffer &operator<<(Framebuffer &fb, const MapElement me);
        friend Framebuffer &operator<<(Framebuffer &fb, const MapElement me);
    };

    Framebuffer &operator<<(Framebuffer &fb, const struct MapElement me)
    {
        fb.putElement(me);
        return fb;
    }
}