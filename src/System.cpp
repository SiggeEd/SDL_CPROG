#include "System.h"
#include <SDL2/SDL.h>


System::System() {
    SDL_Init(SDL_INIT_EVERYTHING);
    win = SDL_CreateWindow("GameDemo", 400, 100, 700, 500, 0);
    ren = SDL_CreateRenderer(win, -1, 0);

    // Path to your own 'sounds' folder!
    //musik = Mix_LoadWAV("/Users/kjellna/dev/cpp21/f13b/sounds/bgMusic.wav");

}

System::~System() {
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    SDL_Quit();
}

System sys;