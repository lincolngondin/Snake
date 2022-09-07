#include "Window.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <stdint.h>
#include "Snake.h"

void drawSnake(Snake& cobra, uint32_t* buffer){
    *(buffer + cobra.pos.x + cobra.pos.y*20) = 0xff000000;
    for(int i = 0; i < cobra.size; i++){
        *(buffer + cobra.body[i].x + cobra.body[i].y*20) = 0xff111111;
    }
}

int main(int argN, char** args){
    Window app;
    SDL_Event eventos;
    bool running = true;

    uint32_t* buffer;
    buffer = new uint32_t[20*20];
    
    SDL_Texture* textura = SDL_CreateTexture(app.getRender(), SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, 20, 20);

    Snake cobra;
    Point2d food = {rand()%20, rand()%20};;

    while(running){
        while(SDL_PollEvent(&eventos)){
            if(eventos.type == SDL_QUIT){
                running = false;
            }
            if(eventos.type == SDL_KEYDOWN){
                switch (eventos.key.keysym.scancode){
                    case SDL_SCANCODE_W:
                        cobra.dir.y = -1;
                        cobra.dir.x = 0;
                        break;
                    case SDL_SCANCODE_S:
                        cobra.dir.y = 1;
                        cobra.dir.x = 0;
                        break;
                    case SDL_SCANCODE_D:
                        cobra.dir.y = 0;
                        cobra.dir.x = 1;
                        break;
                    case SDL_SCANCODE_A:
                        cobra.dir.y = 0;
                        cobra.dir.x = -1;
                        break;
                    case SDL_SCANCODE_G:
                        cobra.grow();
                        break;
                    default:
                        break;
                }
            }
        }
        SDL_RenderClear(app.getRender());

        for(int y = 0; y < 20; y++){
            for(int x = 0; x < 20; x++){
                *(buffer + x + y*20) = 0xffffffff;
            }
        }

        if(cobra.pos.x == food.x && cobra.pos.y == food.y){
            food = {rand()%20, rand()%20};
            cobra.grow();
        }
        
        *(buffer + food.x + food.y*20) = 0xff0000ff;

        cobra.updateSnake();
        drawSnake(cobra, buffer);

        SDL_UpdateTexture(textura, NULL, buffer, sizeof(uint32_t)*20);
        SDL_RenderCopy(app.getRender(), textura, NULL, NULL);
        SDL_RenderPresent(app.getRender());
        SDL_Delay(1000/10);
    }

    SDL_DestroyTexture(textura);
    delete[] buffer;
    return 0;
}