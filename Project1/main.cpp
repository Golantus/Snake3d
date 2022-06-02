#include "GameLogic.h"
#include "Draw.h"

Draw draw;
GameLogic snake;

void gameStart();

float movetime = 0;
bool moved = 1;
float speed = 0.1;


int main()
{
    gameStart();
    
    return 0;	
}

void gameStart()
{
    float deltaTime = 0;
    float lastFrame = 0;
    glfwSetTime(0.0001);
    while (!draw.close())
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        movetime += deltaTime;
        draw.events();
        if (snake.lost())
        {
            draw.drawEndScreen(0, snake.getwidth(), snake.getheight());
            continue;
        }
        if (snake.win())
        {
            draw.drawEndScreen(1, snake.getwidth(), snake.getheight());
            continue;
        }

        draw.render(snake.getx(), snake.gety(), snake.getdots(), snake.getapplex(), snake.getappley(), snake.getwidth(), snake.getheight());
        if (movetime >= speed)
        {
            snake.move();
            movetime = 0;
            moved = 1;
        }
    }
    glfwTerminate();
}


void processInput(GLFWwindow* window)
{

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_F5) == GLFW_PRESS)
    {
        speed = 0.1;
        snake.restart();
    }

    if (movetime >= speed)
    {
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        {

            draw.moveCam();

        }
        if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        {

            speed = 0.1;

        }
        if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        {

            speed = 0.05;

        }
        if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
        {

            speed = 0.02;

        }
    }
    if (moved && !snake.win() && !snake.lost())
    {
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        {
            snake.goUp();
            draw.render(snake.getx(), snake.gety(), snake.getdots(), snake.getapplex(), snake.getappley(), snake.getwidth(), snake.getheight());
            moved = 0;
        }
        else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        {
            snake.goDown();
            draw.render(snake.getx(), snake.gety(), snake.getdots(), snake.getapplex(), snake.getappley(), snake.getwidth(), snake.getheight());
            moved = 0;
        }
        else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        {
            snake.goLeft();
            draw.render(snake.getx(), snake.gety(), snake.getdots(), snake.getapplex(), snake.getappley(), snake.getwidth(), snake.getheight());
            moved = 0;
        }
        else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        {
            snake.goRight();
            draw.render(snake.getx(), snake.gety(), snake.getdots(), snake.getapplex(), snake.getappley(), snake.getwidth(), snake.getheight());
            moved = 0;
        }
    }
}