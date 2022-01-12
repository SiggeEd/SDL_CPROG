#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL2/SDL.h>

class Component
{
public:
    //virtual void mouseMotion(int x, int y) {};
    virtual void addBricks(){};
    virtual  void addBall(){};
    virtual void addPlayer(){};
    virtual void draw() const = 0;
    SDL_Rect getRect() const { return rect; }
    virtual void tick() = 0;
protected:
    Component(int x, int y, int w, int h) : rect{ x,y,w,h } {}
    SDL_Rect rect;
};

#endif



