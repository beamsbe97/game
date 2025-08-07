#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>
#include <SDL2/SDL.h>
#include "Geometry.h"
#include "RenderWindow.h"
#include "GameObject.h"
#include <chrono>
#include "Utils.h"
#include "TileMap.h"
#include "Game.h"

class EnemyManager{
    public:
        EnemyManager(){};
        void spawnEnemies(int numEnemies);

    private:
        vector<std::shared_ptr<Enemy>> enemies;
};