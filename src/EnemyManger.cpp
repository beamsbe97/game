#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <memory>
#include <random>
#include "Geometry.h"
#include "RenderWindow.h"
#include "GameObject.h"
#include <chrono>
#include "Utils.h"
#include "TileMap.h"
#include "Game.h"
#include "EnemyManager.h"

void EnemyManager::spawnEnemies(){
    std::random_device rd;
    std::mt19937 gen(rd());  // Mersenne Twister RNG

    // Define normal distribution with mean = 0.0 and stddev = 1.0
    std::uniform_int_distribution<> dist(0.0, 1.0);
    int randNum = dist(gen);


}