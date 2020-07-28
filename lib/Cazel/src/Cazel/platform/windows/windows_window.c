//
// Created by Frank on 27/07/2020.
//

#include "windows_window.h"
#include <stdio.h>
#include "../../context.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "../../../../lib/glad/include/glad/glad.h"



void windows_window_init(window_t* window)
{
    if(!glfwInit())
    {
        EXIT_ERROR("Failed to initialize glfw\n");
    }
    window->handle = glfwCreateWindow(window->width, window->height, window->title, NULL, NULL);
    context_init(window);
}

void windows_window_close(window_t* window)
{
    glfwDestroyWindow(window->handle);
}
