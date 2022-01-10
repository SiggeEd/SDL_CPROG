#include <SDL2/SDL.h>
#include "Session.h"
#include "Component.h"

#include <SDL_image.h>
#include "Engine.h"
#include <string>


// Paths to resource folders. Change to your own path!
//std::string resPath = "/Users/kjellna/dev/cpp21/f13b_v2/resources/";
std::string resPath = "../resources/";

Session ses;



class Player : public Component {
public:
    static Player* getInstance(int x) {
        return new Player(x);
    }
    Player(int x) : Component(x, 300, 100,20){
        // Path to your own 'images' folder.
        texture = IMG_LoadTexture(sys.ren, (resPath + "images/PlayerSprite.png").c_str() );
    }
    ~Player() {
        SDL_DestroyTexture(texture);
    }
    void draw() const {
        // Code adjustment to handle the address to temporary object.
        const SDL_Rect &rect = getRect();
        //SDL_RenderCopy(sys.ren, texture, NULL, &getRect());
        SDL_RenderCopy(sys.ren, texture, NULL, &rect);
    }
    void tick() {
        SDL_Point mouse;
        counter++;
        rect.x = mouse.x;
    }
private:
    SDL_Texture* texture;
    int counter = 0;
};

class Pistol : public Component {

public:
    Pistol() :Component(0, 0, 0, 0) {}
    void draw() const {}
    void tick() {}
    void mouseDown(int x, int y) {
        Player* b = Player::getInstance(x);
        ses.add(b);
    }
};
int main(int argc, char** argv) {
    Pistol* pistol = new Pistol();
    ses.add(pistol);
    ses.run();

    return 0;
}
