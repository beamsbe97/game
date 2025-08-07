#include "SpriteComponent.h"
#include <iostream>
#include "RenderWindow.h"
#include <map>
#include "GameObject.h"

using namespace std;

class Player;
SpriteComponent::SpriteComponent(RenderWindow* window, string filePath)
:TextureManager(window, filePath){
    this->window = window;
    srcRect.w = 96;
    srcRect.h = 80;
    actionTextures = {
    {"IDLE", {
        {"up", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/IDLE/idle_up.png").c_str()))},
        {"down", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/IDLE/idle_down.png").c_str()))},
        {"right", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/IDLE/idle_right.png").c_str()))},
        {"left", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/IDLE/idle_left.png").c_str()))}
    }},
    {"ATTACK 1", {
        {"up", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/ATTACK 1/attack1_up.png").c_str()))},
        {"down", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/ATTACK 1/attack1_down.png").c_str()))},
        {"right", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/ATTACK 1/attack1_right.png").c_str()))},
        {"left", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/ATTACK 1/attack1_left.png").c_str()))}
    }},
    {"ATTACK 2", {
        {"up", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/ATTACK 2/attack2_up.png").c_str()))},
        {"down", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/ATTACK 2/attack2_down.png").c_str()))},
        {"right", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/ATTACK 2/attack2_right.png").c_str()))},
        {"left", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/ATTACK 2/attack2_left.png").c_str()))}
    }},
    {"RUN", {
        {"up", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/RUN/run_up.png").c_str()))},
        {"down", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/RUN/run_down.png").c_str()))},
        {"right", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/RUN/run_right.png").c_str()))},
        {"left", SDL_CreateTextureFromSurface(window->getRenderer(), IMG_Load((filePath + "/RUN/run_left.png").c_str()))}
    }}
};

    if(texture == NULL){
        std::cout<<"Failed to load texture. Error: " << SDL_GetError()<<std::endl;
    }
}

void SpriteComponent::update(Player* player){   
    float spriteSizeScaling = 1.5;
    currentFrameIdx = int(SDL_GetTicks()/delayBetweenFrames)%this->animationFrames;

    if(actionAnimationOngoing){    
        if((startingFrameIdx==0 && currentFrameIdx==animationFrames-1)
        ||(currentFrameIdx== startingFrameIdx-1)){
            actionAnimationOngoing = false; //signal end of attack animation
        }
        currentFrameIdx = int((SDL_GetTicks()-animationStartTime)/delayBetweenFrames)%this->animationFrames;

    }else{ //start animation
        if(player->getAction()=="ATTACK 1" || player->getAction()=="ATTACK 2"){
            currentFrameIdx=0;
            animationStartTime = SDL_GetTicks();
            actionAnimationOngoing = true;
            startingFrameIdx = currentFrameIdx;
        }

    }

    srcRect.x = srcRect.w * currentFrameIdx;
    srcRect.y = 0;
   
    destRect.x = player->get_xPos();
    destRect.y = player->get_yPos();

    destRect.w = srcRect.w*spriteSizeScaling;
    destRect.h = srcRect.h*spriteSizeScaling;

    SDL_RenderCopy(window->getRenderer(), 
                    actionTextures[player->getAction()][player->getDirection()],
                    &srcRect, &destRect);

}

