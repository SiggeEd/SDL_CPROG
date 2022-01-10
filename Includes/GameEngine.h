#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Component.h"
#include <vector>
#include "System.h"

    class GameEngine {
    public:
        GameEngine();
        void run();
        void add(Component*);
        void remove(Component *comp);
        void setFPS(int updatedFps){fps = updatedFps;};
        void setWindowSize(int w, int h){};

        SDL_Renderer* getRenderer(){return system.ren;};
        static std::string resPath;
        /*
        void addScene(Scene *scene){};
        void loadScene(int);
        */

    private:
        static System system;
        std::vector<Component *> comps;
        std::vector<Component *> added, removed;
        int fps;
    };

#endif