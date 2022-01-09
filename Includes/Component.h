//
// Created by edsim on 2022-01-09.
//

#ifndef SDL_PROJECT_COMPONENT_H
#define SDL_PROJECT_COMPONENT_H
#include <SDL2/SDL.h>
class Component
{
public:
    virtual void mouseMove(int x);
    virtual draw() const = 0;
    SLD_Rect getRect() const {return rect;}
    virtual void tick() = 0;

protected:
    Component(int x, int y, int w, int h) : rect(x,y,w,h){}
    SDL_Rect rect;
};



#endif //SDL_PROJECT_COMPONENT_H
