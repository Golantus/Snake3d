#ifndef DRAW
#define DRAW
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

class Draw
{
private:
    GLFWwindow* window = nullptr;
    const int SCR_WIDTH = 1320;
    const int SCR_HEIGHT = 768;


    int shaderProgram;  
    unsigned int texture1;
    unsigned int texture2;
    unsigned int texture3;
    unsigned int texture4;
    unsigned int texture5;

    unsigned int VBO;
    unsigned int VAO;

    int initWin();
    void generateShader();
    void generateBuffers();
    void loadTexture(unsigned int& texture, const char* data);
    void uniformTexrues();

    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    glm::mat4 projection;

public:
    bool close();
    void render(int* x, int* y, int dots, int appplex, int appley, int width, int height);
    void events();
    void drawEndScreen(bool haswon, int width, int height);
    void moveCam();

    Draw();
};


#endif // !DRAW