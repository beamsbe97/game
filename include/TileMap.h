#pragma once
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Geometry.h"
#include "RenderWindow.h"
#include <vector>
#include "TextureManager.h"

class TileMap:TextureManager{
    public:
        TileMap(RenderWindow* window, string filePath, int mapWidth, int mapHeight);
        void renderMap();

    private:
        vector<vector<int>> symbolicMap;
        SDL_Texture* tiles[2] = {nullptr, nullptr};
        int mapWidth, mapHeight;
};