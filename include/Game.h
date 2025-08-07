#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <SDL2/SDL.h>
#include "Geometry.h"
#include "RenderWindow.h"
#include "GameObject.h"
#include <chrono>
#include "Utils.h"
#include "TileMap.h"
#include <memory>

class Game{
    public:
        Game(std::string windowName, map<string,map<char, float>> initValues);
        void handleEvents();
        void updateGame();
        void render();
        void end();

        bool gameRunning = true;
        Player* player;
        std::shared_ptr<RenderWindow> window;
        vector<Enemy*>* enemies;
        TileMap* world;
        const Uint8* kbState = SDL_GetKeyboardState(NULL);


};