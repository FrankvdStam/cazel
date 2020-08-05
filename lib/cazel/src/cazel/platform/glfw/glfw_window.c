//
// Created by Frank on 27/07/2020.
//

#include "glfw_window.h"
#include "../../context.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"



void glfw_window_init(window_t* window)
{
    if(!glfwInit())
    {
        EXIT_ERROR("Failed to initialize glfw\n");
    }
    window->handle = glfwCreateWindow(window->width, window->height, window->title, NULL, NULL);

    //Questionable to init the context in the window. Not sure what a better way might be.
    context_init(window);
}

void glfw_window_close(window_t* window)
{
    glfwDestroyWindow(window->handle);
}
