#include "Window.h"

Window::Window(){
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Window::~Window(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
    SDL_Quit();
}

SDL_Window* Window::getWindow(){
    return this->window;
}

SDL_Renderer* Window::getRender(){
    return this->render;
}

