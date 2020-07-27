//
// Created by Frank on 27/07/2020.
//

#include "windows_window.h"
#include <stdio.h>

#define GLFW_INCLUDE_NONE
#include "../../../lib/glfw/include/GLFW/glfw3.h"
#include "../../../lib/glad/include/glad/glad.h"

void glDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    printf("%s\n", message);
};

void windows_window_init(window_t window)
{
    if(!glfwInit())
    {
        fprintf(stderr, "Failed to initialize glfw\n");
    }

    window.handle = glfwCreateWindow(window.width, window.height, window.title, NULL, NULL);
    glfwMakeContextCurrent(window.handle);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr, "Failed to initialize glad\n");
    }
    glEnable(GL_DEBUG_OUTPUT);
    GLDEBUGPROC proc = glDebugCallback;
    glDebugMessageCallback(proc, NULL);
}

void windows_window_close(window_t window)
{
    glfwDestroyWindow(window.handle);
}