#include "GameLogic.h"
#include "RNG.h"


void GameLogic::goLeft()
{
    if (!rightDirection)
    {
        leftDirection = 1;
        upDirection = 0;
        downDirection = 0;
    }
}
void GameLogic::goRight()
{
    if (!leftDirection)
    {
        rightDirection = 1;
        upDirection = 0;
        downDirection = 0;
    }
}
void GameLogic::goUp()
{
    if (!downDirection)
    {
        leftDirection = 0;
        upDirection = 1;
        rightDirection = 0;
    }
}
void GameLogic::goDown()
{
    if (!upDirection)
    {
        leftDirection = 0;
        downDirection = 1;
        rightDirection = 0;
    }
}


void GameLogic::move()
{

    for (int i = dots; i > 0; i--)
    {
        x[i] = x[(i - 1)];
        y[i] = y[(i - 1)];
    }

    if (leftDirection)
    {
        x[0] -= 1;
    }

    if (rightDirection)
    {
        x[0] += 1;
    }

    if (upDirection)
    {
        y[0] += 1;
    }

    if (downDirection)
    {
        y[0] -= 1;
    }
    checkCollision();
    checkApple();
}
void GameLogic::checkApple()
{
    if (x[0]== apple_x && y[0] == apple_y)
    {
        dots++;
        if (dots == ALL_DOTS)
        {
            hasWon = 1;
        }
        locateApple();
    }
}
void GameLogic::checkCollision()
{
    
    for (int i = dots; i > 0; i--)
    {
        if (i > 4 && x[0] == x[i] && y[0] == y[i]  )
        {
            InGame = false;
        }
        if (x[0] > F_WIDTH-1)
        {
            InGame = false;
        }
        if (x[0] < 0)
        {
            InGame = false;
        }
        if (y[0] > F_HEIGHT-1)
        {
            InGame = false;
        }
        if (y[0] < 0)
        {
            InGame = false;
        }
    }
}
void GameLogic::locateApple()
{
    apple_x = getRandomNumber(0, F_WIDTH-1);
    apple_y = getRandomNumber(0, F_HEIGHT-1);
    for (int i = 0; i < dots; i++)
    {
        if (apple_x == x[i] && apple_y == y[i])
            locateApple();
    }
}



void GameLogic::restart()
{
    InGame = 1;
    hasWon = 0;
    downDirection = 0;
    goUp();
    dots = 3;
    for (int i = 0; i < dots; i++)
    {
        x[i] = (F_WIDTH/2);
        y[i] = 0;
    }
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
    rand(); // сбрасываем первый результат
    locateApple();
}
bool GameLogic::lost()
{
    return !InGame;
}
bool GameLogic::win()
{
    return hasWon;
}




int* GameLogic::getx()
{
    return x;
}
int* GameLogic::gety()
{
    return y;
}
int GameLogic::getapplex()
{
    return apple_x;
}
int GameLogic::getappley()
{
    return apple_y;
}
int GameLogic::getdots()
{
    return dots;
}
int GameLogic::getheight()
{
    return F_HEIGHT;
}
int GameLogic::getwidth()
{
    return F_WIDTH;
}