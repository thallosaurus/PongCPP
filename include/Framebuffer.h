#include <iostream>

namespace Pong
{
    class Framebuffer
    {
    private:
        int width, height;
        char *fb;

    public:
        Framebuffer(const int w, const int h);

        // std::list<FramebufferConsumer> consumers[10];
        // char currentConsumerCount = 0;

        ~Framebuffer();

        // void addConsumer(FramebufferConsumer cons) {
        // consumers[currentConsumerCount] = cons;
        // currentConsumerCount++;
        // }

        void resetBuffer();

        char *getBuffer();

        std::string getBufferAsString();

        char getchar(int x, int y);

        void putchar(char data, int x, int y);

        void putElement(struct MapElement e);

        int getWidth();

        int getHeight();

        friend Framebuffer &operator<<(Framebuffer &fb, const MapElement me);
        friend Framebuffer &operator<<(Framebuffer &fb, const MapElement me);
    };
}