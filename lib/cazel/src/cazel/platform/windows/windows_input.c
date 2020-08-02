//
// Created by Frank on 28/07/2020.
//

#include "windows_input.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

bool windows_mouse_button_pressed(window_t* window, int button)
{
    switch (button)
    {
        default:
            EXIT_ERROR("Unknown mousebutton: %i\n", button);
            break;
        case MOUSE_BUTTON_LEFT:
            return glfwGetMouseButton(window->handle, GLFW_MOUSE_BUTTON_LEFT);
        case MOUSE_BUTTON_RIGHT:
            return glfwGetMouseButton(window->handle, GLFW_MOUSE_BUTTON_RIGHT);
        case MOUSE_BUTTON_MIDDLE:
            return glfwGetMouseButton(window->handle, GLFW_MOUSE_BUTTON_MIDDLE);
    }
}