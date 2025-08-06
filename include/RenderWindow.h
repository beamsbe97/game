#pragma once
#include <SDL2/SDL.h>
#include <iostream>

class RenderWindow{
    public:
        RenderWindow(const char * title, int width, int height);
        SDL_Texture* loadTexture(const char* file);
        void cleanUp();
        void clear();
        void render(SDL_Texture* tex);
        void display();
        SDL_Renderer* getRenderer(){return renderer;}
        int getHeight(){return height;}
        int getWidth(){return width;}
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        int height, width;
};