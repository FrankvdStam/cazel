//
// Created by Frank on 02/08/2020.
//

#include "linux_window.h"
#include "../../context.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"



void linux_window_init(window_t* window)
{
    if(!glfwInit())
    {
        EXIT_ERROR("Failed to initialize glfw\n");
    }
    window->handle = glfwCreateWindow(window->width, window->height, window->title, NULL, NULL);
    context_init(window);
}

void linux_window_close(window_t* window)
{
    glfwDestroyWindow(window->handle);
}
