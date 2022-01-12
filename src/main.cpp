#include <SDL2/SDL.h>
#include "GameEngine.h"
#include "Component.h"

#include <SDL_image.h>
#include "System.h"
#include <string>
#include <math.h>
#include <iostream>

// Paths to resource folders. Change to your own path!
//std::string resPath = "/Users/kjellna/dev/cpp21/f13b_v2/resources/";
std::string resPath = "../resources/";

GameEngine ses;


class Player : public Component {
public:
    static Player* getInstance(int x) {
        return new Player(x);
    }
    Player(int x) : Component(x, 450, 100,20){
        // Path to your own 'images' folder.
        texture = IMG_LoadTexture(sys.ren, (resPath + "images/PlayerSprite.png").c_str() );
    }
    ~Player() {
        SDL_DestroyTexture(texture);
    }
    void draw() const {
        int x;
        int y;
        SDL_GetMouseState(&x, &y);
        // Code adjustment to handle the address to temporary object.
        //const SDL_Rect &rect = setRect(600);
        const SDL_Rect &rect = getRect();
        const SDL_Rect &fixedXRect = {600, rect.y, rect.w, rect.h};
        //SDL_RenderCopy(sys.ren, texture, NULL, &getRect());

        if(x <= 600) {
            SDL_RenderCopy(sys.ren, texture, NULL, &rect);
        }
        else
        {

            SDL_RenderCopy(sys.ren, texture, NULL, &fixedXRect);
        }
    }
    void tick() {
        int x;
        int y;
        SDL_GetMouseState(&x, &y);
        rect.x = x;
    }
private:
    SDL_Texture* texture;
    int counter = 0;
};

class Ball : public Component
{
public:

    static Ball* getInstance(int x, int y) {
        return new Ball(x, y);
    }
    Ball(int x, int y) : Component(x, y, 20, 20){
      ballTexture = IMG_LoadTexture(sys.ren, (resPath + "images/Bakk.png").c_str() );

    }
    ~Ball(){
        SDL_DestroyTexture(ballTexture);
    }

    void draw() const{
        const SDL_Rect &ballRect = getRect();
        SDL_RenderCopy(sys.ren, ballTexture, NULL, &ballRect);

    }
    void tick() {
        int velocity = 3 + 1/4;

        int x = sqrt(powf(velocity, 2) / 2);
        rect.x = x;
        rect.y = x;


    }

private:
    SDL_Texture* ballTexture;

};

class Brick : public Component
{
public:
    static Brick* getInstance(int x, int y) {
        return new Brick(x, y);
    }

    Brick(int x, int y) : Component(x, y, 75,25){
        brickTexture = IMG_LoadTexture(sys.ren, (resPath + "images/Brick.png").c_str() );
    }

    ~Brick(){
        SDL_DestroyTexture(brickTexture);
    }

    void draw() const{
        const SDL_Rect &brickRect = getRect();
        SDL_RenderCopy(sys.ren, brickTexture, NULL, &brickRect);
    }

    void tick() {
    }




private:
    SDL_Texture* brickTexture;
};

class GameBoard : public Component {

public:


    GameBoard() :Component(0, 0, 0, 0) {}
    void draw() const {}
    void tick() {}
    void addPlayer(){
        Player* player = Player::getInstance(20);
        ses.add(player);
    }
   /* void mouseMotion(int x, int y) {
        Player* b = Player::getInstance(x);
        ses.add(b);

    }*/

    void addBricks(){
        int spaceBetween = 78;
        int brickPosX = 0;
        int brickPosy = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 9; j++){
                Brick* b1 = Brick::getInstance(brickPosX, brickPosy);
                ses.add(b1);
                brickPosX += spaceBetween;
            }
            brickPosX = 0;
            brickPosy = 27;

        }
    }
    void addBall(){
        Ball* ball = Ball::getInstance(50, 50 );
        ses.add(ball);
    }


};
int main(int argc, char** argv) {
    GameBoard* gameBoard = new GameBoard();
    ses.add(gameBoard);
    ses.run();

    return 0;
}
