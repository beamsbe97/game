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
#include "Game.h"


using namespace std;

int main(int argc, char* argv[]){
    
    Game* game = new Game("Zelda", {{"Player",{{'x', 0.0},{'y', 0.0}}},
                                    {"Window",{{'w', 1280},{'h', 720}}}});

    while(game->gameRunning){
        game->handleEvents();
        game->window->clear(); 
        game->render();
        game->window->display();

    }

    Polygon* objA = new Polygon({{1,1},{4,3},{1,3}});
    Polygon* objB = new Polygon({{3,2},{5,2},{5,4},{3,4}});
    Polygon* objC = new Polygon({{1,4},{2,4},{2,5},{1,5}});

    if(objA->collisionCheck(*objB)){
        cout<<"A collided with B\n";
    }else{
        cout<<"A DID NOT collide with B\n";
    }
    if(objA->collisionCheck(*objC)){
        cout<<"A collided with C\n";
    }else{
        cout<<"A DID NOT collide with C\n";
    }
    game->end();
    
    return 0;
}

///NEED TO CHECK NON-COLLISION FOR ALL AXES