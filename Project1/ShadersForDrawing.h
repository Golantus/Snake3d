#ifndef DRAWSHADERS
#define DRAWSHADERS
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec2 aTexCoord;\n"
"out vec2 TexCoord;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"
"void main()\n"
"{\n"
"   gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
"   TexCoord = aTexCoord;\n"
"}\0";


const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec2 TexCoord;\n"
"uniform sampler2D texture1;\n" //field
"uniform sampler2D texture2;\n" //snake
"uniform sampler2D texture3;\n" //apple
"uniform sampler2D texture4;\n" //lost
"uniform sampler2D texture5;\n" //won
"uniform sampler2D texture6;\n" //settings
"uniform int text;\n"
"void main()\n"
"{\n"
"   FragColor = texture(texture1, TexCoord);\n"
"   if (text==2)\n"
"	{FragColor = texture(texture2, TexCoord);}\n"
"   if (text==3)\n"
"   {FragColor = texture(texture3, TexCoord);}\n"
"   if (text==4)\n"
"   {FragColor = texture(texture4, TexCoord);}\n"
"   if (text==5)\n"
"   {FragColor = texture(texture5, TexCoord);}\n"
"   if (text==6)\n"
"   {FragColor = texture(texture6, TexCoord);}\n"
"}\n\0";
#endif