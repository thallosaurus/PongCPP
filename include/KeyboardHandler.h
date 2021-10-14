namespace Pong {
    class KeyboardHandler
    {
    private:
        static char *pressedKey;
        pthread_t handlerThread;
        bool running = true;

    public:
        KeyboardHandler();
        ~KeyboardHandler();

        static void *keyboardThread(void *arg);

        struct DisplayStruct start();

        void stopKeyboardHandler();
        virtual void onKeyPress(char keycode) = 0;
    };
}