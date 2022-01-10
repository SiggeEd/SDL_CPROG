#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL_misc.h>
#include <SDL2/SDL.h>
#include <string>

struct Engine
{
    Engine();
    ~Engine();

    SDL_Window* win;
    SDL_Renderer* ren;
};

extern std::string resPath;
extern Engine sys;

#endif
