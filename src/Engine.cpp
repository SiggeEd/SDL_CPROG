#include "Engine.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
Engine::Engine()
{
    std::string resourcesPath ="../Resources/";

    SDL_Surface *image = NULL;
    SDL_Surface *optmizedImage = NULL;
    SDL_Surface *sdlSurface = NULL;
    image = IMG_Load((resourcesPath+"Images/PlayerSprite.png").c_str());

    SDL_Texture *texture = NULL;
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("mainWindow", 500, 200, 500, 500, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    sdlSurface = SDL_GetWindowSurface(window);
    SDL_BlitSurface(image, NULL, sdlSurface, NULL);
    SDL_UpdateWindowSurface(window);


}

Engine::~Engine()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
Engine engine;
