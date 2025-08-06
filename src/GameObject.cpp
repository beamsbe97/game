#include <iostream>
#include <vector>
#include <string>
#include "GameObject.h"
#include "SpriteComponent.h"
#include <SDL2/SDL.h>
#include <algorithm>
#include "Utils.h"

using namespace std;

GameObject::GameObject(float xPos, float yPos):xPos(xPos), yPos(yPos), direction("down"){

}

void GameObject::setDirection(char newDirection){
    direction = newDirection;
}

void GameObject::initCollider(vector<vector<float>> vertices){
    collider = new Polygon(vertices);
}

void GameObject::initSprite(RenderWindow* window, const char* filePath){
    sprite = new SpriteComponent(window, filePath);
    this->window = window;
}

float ActiveObject::dealDamage(float damage){
    return damage;
}

void ActiveObject::receiveDamage(float damage){
    hp -= damage;
}

vector<string> Player::getInventory(){
    return inventory;
}

void Player::handleTransformInput(const Uint8* kbState, double deltaTime){
    velocity = 40;
    float dtScale = 0.01;

    deltaTime = std::max(deltaTime, 150000.0);
    deltaTime = dtScale*std::min(deltaTime, 300000.0)/1000000;
    
    // deltaTime*=100;
    // double smoothedDt = 0.01*deltaTime + 0.99*prevDt;
    // prevDt = smoothedDt;
    int notifierFrame;

    // int numKeys = 0;
    // SDL_GetKeyboardState(&numKeys);
    // bool nothingPressed = true;


    if(sprite->getActionAnimationOngoing()){
        return;
    }

    if(noKeyPressed(kbState)){
        action = "IDLE";
        return;
    }


    if(kbState[SDL_SCANCODE_LSHIFT]||kbState[SDL_SCANCODE_SPACE]){
        if((kbState[SDL_SCANCODE_SPACE])) action = "ATTACK 1";
        else action = "ATTACK 2";
        return;
    }
  

    else if (kbState[SDL_SCANCODE_W]||kbState[SDL_SCANCODE_UP]){     
        direction = "up";
    }
                            
    else if (kbState[SDL_SCANCODE_S]||kbState[SDL_SCANCODE_DOWN]){
        direction = "down";
    }
            
    else if (kbState[SDL_SCANCODE_D]||kbState[SDL_SCANCODE_RIGHT]){
        direction = "right";
    }
            
    else if (kbState[SDL_SCANCODE_A]||kbState[SDL_SCANCODE_LEFT]){
        direction = "left";
    }
    _move(deltaTime);
    action = "RUN";

}


void ActiveObject::_move(double& deltaTime){

    velocity = 40;
    float dtScale = 0.01;

    deltaTime = std::max(deltaTime, 150000.0);
    deltaTime = dtScale*std::min(deltaTime, 300000.0)/500000;

    if(direction=="up"){
        if ((yPos-velocity*deltaTime) < 0){
            yPos = 0;
        }else{
            yPos-=velocity*deltaTime;
        }
    }

    else if(direction=="down"){
        if (((yPos-velocity*deltaTime)+sprite->getDestRect()->h) > window->getHeight()){
            yPos = window->getHeight() - sprite->getDestRect()->h;
        }else{
            yPos+= velocity*deltaTime;
        }
        
    }

    else if (direction=="left"){
        if ((xPos-velocity*deltaTime) < 0){
            xPos = 0;
        }else{
            xPos-=velocity*deltaTime;
        }
    }

    else if (direction=="right"){
        if (((xPos-velocity*deltaTime)+sprite->getDestRect()->w) > window->getWidth()){
            xPos = window->getWidth() - sprite->getDestRect()->w;
        }
        xPos+= velocity*deltaTime;
    }
    
}