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


using namespace std;

int main(int argc, char* argv[]){
    
     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
        return 1;
    }
    cout << "Hello World!";

    map<string,map<char, float>> initValues {{"Player",{{'x', 0.0},{'y', 0.0}}},
                                                {"Window",{{'w', 1280},{'h', 720}}}};

    RenderWindow* window = new RenderWindow("Zelda", initValues["Window"]['w'], initValues["Window"]['h']);

    Player* player = new Player(initValues["Player"]['x'], 
                                        initValues["Player"]['y']);
    
    Enemy* e1 = new Enemy(50,50);
    e1->initSprite(window, "res/Enemies");


    TileMap* world = new TileMap(window, "res/Tiles", 16, 9);

    player->initSprite(window,"res/Player/knight");
    

    bool gameRunning = true;
    const Uint8* kbState = SDL_GetKeyboardState(NULL);

    int frameCount = 0;
    double running_total_dt=0;
    double dt;

    while(gameRunning){
        frameCount++;
        getDeltaTime();
        SDL_Event event;
        
        while(SDL_PollEvent(&event)){
            if (event.type== SDL_QUIT) gameRunning = false;
        }
        dt = getDeltaTime();
        player->handleTransformInput(kbState, dt);  
        running_total_dt+=dt;
        if(frameCount%1000 == 0){
            //std::cout<<running_total_dt/1000<<endl;
            running_total_dt=0;
        }
        window->clear(); 
        world->renderMap();
        player->getSprite()->update(player);
        window->display();

  
    }

    Polygon* objA = new Polygon({{1,1},{4,3},{1,3}});
    Polygon* objB = new Polygon({{3,2},{5,2},{5,4},{3,4}});
    Polygon* objC = new Polygon({{1,4},{2,4},{2,5},{1,5}});

    objA->what();
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
    window->cleanUp();
    SDL_Quit();
    return 0;
}

///NEED TO CHECK NON-COLLISION FOR ALL AXES