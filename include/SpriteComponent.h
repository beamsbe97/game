#pragma once
#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Geometry.h"
#include "RenderWindow.h"
#include <map>
#include "TextureManager.h"

class Player;
class SpriteComponent: public TextureManager{
    public:
        SpriteComponent(RenderWindow* window, string filePath);
        void update(Player* player);
        bool getActionAnimationOngoing(){return actionAnimationOngoing;}

    private: 
        float delayBetweenFrames = 150;
        int animationFrames = 8;
        std::map<std::string, std::map<std::string, SDL_Texture*>> actionTextures;
        bool actionAnimationOngoing = false;
        int currentFrameIdx;
        int startingFrameIdx;
        double animationStartTime;

};