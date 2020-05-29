
#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

using namespace std;

const char* APP_TITLE = "IntroDuction to Mordern OpenGL";
const int window_width = 600;
const int window_height =400;

void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode);

int main()
{
    if (!glfwInit()) 
    {
        cerr << "GLFW initialization failded " << endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* pWindow = glfwCreateWindow(window_width, window_height, APP_TITLE, NULL, NULL);
    if (pWindow == NULL)
    {
        cerr << "Failed to Create GLFW to Window" << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(pWindow);

    glfwSetKeyCallback(pWindow, glfw_onKey);
    
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        cerr << "Failed to Init GLEW to Window" << endl;
        glfwTerminate();
        return -1;
    }

    while (!glfwWindowShouldClose(pWindow))
    {
        glfwPollEvents();

        glClearColor(0.23f, 0.34f, 0.47f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(pWindow);
    }

    glfwTerminate();
    return 0;
}

void glfw_onKey(GLFWwindow* window, int key, int scancode, int action, int mode)
{

}
