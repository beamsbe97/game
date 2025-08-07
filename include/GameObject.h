#pragma once
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Geometry.h"
#include "SpriteComponent.h"
#include "RenderWindow.h"

class RenderWindow;
class GameObject{
    public:
        GameObject(float xPos, float yPos);
        std::string name;
        void setDirection(char newDirection);
        void initCollider(vector<vector<float>> vertices);
        void initSprite(RenderWindow* window, const char* filePath);
        SpriteComponent* getSprite(){return sprite;}
        float get_xPos(){return xPos;}
        float get_yPos(){return yPos;}
        string getDirection(){return direction;}
        RenderWindow* window;
        
    protected:
        float xPos;
        float yPos;
        string direction;     
        const char* filePath;
        Geometry* collider;
        SpriteComponent* sprite;
        double prevDt=0.0;
           
};

class ActiveObject : public GameObject{
    public:
        ActiveObject(float xPos, float yPos):GameObject(xPos, yPos){
            action = "IDLE";
        };
        float dealDamage(float damage);
        void receiveDamage(float damage);
        string getAction(){return action;}
        bool inAction=false;

    protected:
        float hp;
        float velocity;
        float velocityModifier;
        string action;
        int framesForAction;
        int currentFrameNO = 0; 
        void _move(double& deltaTime);
    
};

class Player: public ActiveObject{
    public:
        using ActiveObject::ActiveObject;
        vector<string> getInventory();
        void handleTransformInput(const Uint8* kbState, double deltaTime);
        
    private:
        vector<string> inventory;
        string weapon;
        string shield;    

};

class Enemy: public ActiveObject{
    public:
        using ActiveObject::ActiveObject;        

};

