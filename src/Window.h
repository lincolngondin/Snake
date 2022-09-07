#ifndef WINDOW_H_
#define WINDOW_H_
#include <SDL2/SDL.h>

class Window{
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* render = nullptr;

    public:
        Window();
        ~Window();
        SDL_Window* getWindow();
        SDL_Renderer* getRender();
};

#endif