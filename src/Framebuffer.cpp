#include "include/config.h"
#include "include/Framebuffer.h"
#include "include/Utils.h"
#include "include/structs.h"
#include <iostream>


namespace Pong
{

    Framebuffer &operator<<(Framebuffer &fb, const struct MapElement me)
    {
        fb.putElement(me);
        return fb;
    }

    Framebuffer::Framebuffer(const int w, const int h) : width(w), height(h)
        {
            this->fb = new char[w * h + 1];

            if (this->fb)
            {
                DEBUG &&std::cout << "Array creation did work" << std::endl;
                resetBuffer();
            }
        }

        Framebuffer::~Framebuffer()
        {
            delete this->fb;
            DEBUG &&std::cout << "[DEBUG]Framebuffer destroyed" << std::endl;
        }

        void Framebuffer::resetBuffer()
        {
            for (int i = 0; i < this->width * this->height; i++)
            {
                this->fb[i] = ' ';
            }
            this->fb[this->width * this->height] = '\0';
        }

        char *Framebuffer::getBuffer()
        {
            return this->fb;
        }

        std::string Framebuffer::getBufferAsString()
        {
            std::string ret = (std::string)this->fb;

            for (int i = 1; i <= height; i++)
            {
                ret.insert(i * width, ((height - 1) == i ? "\n" : ""));
                // ret.insert(i * width, "\n");
            }

            return ret;
        }

        char Framebuffer::getchar(int x, int y)
        {
            if (x * y > this->width * this->height)
            {
                throw "Index out of bounds";
            }

            return this->fb[IntToXY(this->width, x, y)];
        }

        void Framebuffer::putchar(char data, int x, int y)
        {
            if (x < this->width && y < this->height)
            {
                int index = IntToXY(this->width, x, y);
                this->fb[index] = data;
            }
        }

        void Framebuffer::putElement(struct MapElement e)
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

        int Framebuffer::getWidth()
        {
            return width;
        }

        int Framebuffer::getHeight()
        {
            return height;
        }

}