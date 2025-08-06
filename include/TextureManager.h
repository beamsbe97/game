#pragma once
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Geometry.h"
#include "RenderWindow.h"

class TextureManager{
    public:
        TextureManager(){}
        TextureManager(RenderWindow* window, string filePath);
        SDL_Rect* getDestRect(){return &destRect;}
    protected: 
        void draw();
        SDL_Texture* texture;
        SDL_Rect srcRect, destRect;
        RenderWindow* window;

};