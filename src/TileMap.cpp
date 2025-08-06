#include "TileMap.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

TileMap::TileMap(RenderWindow* window, string folderPath, int mapWidth, int mapHeight)
:TextureManager(window, folderPath), mapHeight(mapHeight),mapWidth(mapWidth){

    // for(const auto& entry: fs::directory_iterator(folderPath)){
    //     tiles.push_back(SDL_CreateTextureFromSurface(window->getRenderer(),IMG_Load(entry.path().string().c_str()))); 
    // }

    tiles[0] = SDL_CreateTextureFromSurface(window->getRenderer(),IMG_Load((folderPath+"/Cliff_Tile.png").c_str()));
    tiles[1] = SDL_CreateTextureFromSurface(window->getRenderer(),IMG_Load((folderPath+"/Beach_Tile.png").c_str()));

    symbolicMap.resize(mapWidth, std::vector<int>(mapHeight, 0));
}


void TileMap::renderMap(){
    srcRect.x = srcRect.y = 0;
    srcRect.w = srcRect.h = 48;
    destRect.w = destRect.h = 96;
    

    for(int w=0; w<mapWidth; w++){
        for(int h=0; h<mapHeight; h++){
            destRect.x = w*destRect.w;
            destRect.y = h*destRect.w;
            SDL_RenderCopy(window->getRenderer(), tiles[0], &srcRect, &destRect);
        }
    }

}