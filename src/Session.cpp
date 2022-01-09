#include "Session.h"
#include "Engine.h"
#include <iostream>
#include <SDL2/SDL.h>
/*
 * Run ska kalla på allt som har med spelet att göra(sprites etc etc)
 * är en "spelomgång"
 * */
using namespace std;
#define FPS 80

void Session::run() {
    bool end = false;
    Uint32 tickInterval = 1000 / FPS;

    SDL_Texture *texture = NULL;

    while(!end)
    {
        Uint32 nextTick = SDL_GetTicks() + tickInterval;
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type) {
                case SDL_QUIT:
                    end = true;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    cout<<"MOUSEBUTTONDOWN"<<endl;
                    break;

                case SDL_MOUSEBUTTONUP:
                    cout<<"MOUSEBUTTONUP"<<endl;
                    break;


            }
        }


        SDL_SetRenderDrawColor(engine.renderer, 255, 255, 255, 255);
        SDL_RenderClear(engine.renderer);
        /*
        for (Component* c : comps)
            c->draw();
        SDL_RenderPresent(sys.ren);
        */

        int delay = nextTick - SDL_GetTicks();
        if (delay > 0)
            SDL_Delay(delay);
    }
}


