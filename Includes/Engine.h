//
// Created by edsim on 2022-01-08.
//

#ifndef SDL_PROJECT_ENGINE_H
#define SDL_PROJECT_ENGINE_H
#include <SDL2/SDL.h>
#include <string>
struct Engine
{
    Engine();
    ~Engine();
    SDL_Window* window;
    SDL_Renderer* renderer;
};

extern std::string resPath;
extern Engine engine;
#endif //SDL_PROJECT_ENGINE_H

