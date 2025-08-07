#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <memory>
#include "Geometry.h"
#include "RenderWindow.h"
#include "GameObject.h"
#include <chrono>
#include "Utils.h"
#include "TileMap.h"
#include "Game.h"

Game::Game(string windowName, map<string,map<char, float>> initValues){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
    }
    
    window = std::make_shared<RenderWindow>(windowName.c_str(), 
                            static_cast<int>(initValues["Window"]['w']), 
                            static_cast<int>(initValues["Window"]['h']));
    
    player = new Player(initValues["Player"]['x'], 
                        initValues["Player"]['y']);
    player->initSprite(window.get(),"res/Player/knight");
    player->initCollider();

    world = new TileMap(window.get(), "res/Tiles", 16, 9);
}

void Game::handleEvents(){
    getDeltaTime();
    SDL_Event event;
    
    while(SDL_PollEvent(&event)){
        if (event.type== SDL_QUIT) gameRunning = false;
    }
    player->handleTransformInput(kbState, getDeltaTime());  

}

void Game::render(){
    world->renderMap();
    player->getSprite()->update(player);
}

void Game::end(){
    window->cleanUp();
    SDL_Quit(); 
}


