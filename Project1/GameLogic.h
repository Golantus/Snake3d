#ifndef LOGIC
#define LOGIC
class GameLogic
{
private:
    static const int F_WIDTH = 20;
    static const int F_HEIGHT = 20;
    static const int ALL_DOTS = F_WIDTH * F_HEIGHT;

    int apple_x;
    int apple_y;

    int dots;
    int x[ALL_DOTS];
    int y[ALL_DOTS];


    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;

    bool InGame;
    bool hasWon;

    void locateApple();
    void checkApple();
    void checkCollision();

public:


    void move();
    bool lost();
    bool win();
    float gettime();
    void restart();

    void goLeft();
    void goRight();
    void goUp();
    void goDown();


    int* getx();
    int* gety();
    int getapplex();
    int getappley();
    int getdots();
    int getheight();
    int getwidth();

};
#endif // !LOGIC
