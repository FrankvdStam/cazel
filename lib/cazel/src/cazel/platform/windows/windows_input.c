//
// Created by Frank on 28/07/2020.
//

#include "windows_input.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

bool windows_mouse_button_pressed(window_t* window, mouse_button_t button)
{
    switch (button)
    {
        default:
            EXIT_ERROR("Unknown mousebutton: %i\n", button);
            break;
        case mouse_button_left:
            return glfwGetMouseButton(window->handle, GLFW_MOUSE_BUTTON_LEFT);
        case mouse_button_right:
            return glfwGetMouseButton(window->handle, GLFW_MOUSE_BUTTON_RIGHT);
        case mouse_button_middle:
            return glfwGetMouseButton(window->handle, GLFW_MOUSE_BUTTON_MIDDLE);
    }
}
