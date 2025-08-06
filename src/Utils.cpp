#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <chrono>
#include <SDL2/SDL.h>


double getDeltaTime(){
    static double begin = static_cast<float>(SDL_GetTicks()) / 1000.0f;
    double end = static_cast<float>(SDL_GetTicks()) / 1000.0f;

    //double deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    double deltaTime = end - begin;
    begin = end;

    return deltaTime;
}

bool noKeyPressed(const Uint8* kbState){
    int numKeys = 0;
    SDL_GetKeyboardState(&numKeys);
    bool nothingPressed = true;

    for (int i = 0; i < numKeys; ++i) {
        if (kbState[i] != 0) {
            nothingPressed = false;
            break;
        }
    }

    return nothingPressed;

}