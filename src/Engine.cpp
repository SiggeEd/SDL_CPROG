#include "Engine.h"
#include <iostream>
#include <SDL2/SDL.h>

Engine::Engine()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("mainWindow", 500, 200, 700, 500, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

}

Engine::~Engine()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
Engine engine;
