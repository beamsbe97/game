#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>

#include "RenderWindow.h"

RenderWindow::RenderWindow(const char * title, int width, int height)
    :window(NULL), renderer(NULL), width(width), height(height)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if(!window){
        std::cout <<"COULD NOT INIT WINDOW "<< SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window,  -1, SDL_RENDERER_ACCELERATED);
}


SDL_Texture* RenderWindow::loadTexture(const char* filePath){
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, filePath);
    if(texture==NULL){
        std::cout << "Failed to load texture. Error:" << SDL_GetError() << std::endl;
    }

    return texture; 
}

void RenderWindow::cleanUp(){
    SDL_DestroyWindow(window);
}

void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* tex){
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = 48;
    src.h = 48;

    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;
    dest.w = src.w *4;
    dest.h = src.h *4;


    SDL_RenderCopy(renderer, tex, &src, &dest);
}

void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}