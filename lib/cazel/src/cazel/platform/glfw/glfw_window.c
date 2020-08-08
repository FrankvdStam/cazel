//
// Created by Frank on 27/07/2020.
//

#include "glfw_window.h"
#include "../../context.h"
#include "../../events/event.h"
#include "../../application.h"
#include "../glfw/glfw_input.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"


void glfw_window_resize_callback(GLFWwindow* window, int width, int height)
{
    event_t event = event_create_empty();
    event.type = event_window_resize;
    event.x = width;
    event.y = height;
    application_on_event(event);
}

void glfw_window_maximize_callback(GLFWwindow* window, int maximized)
{
    event_t event = event_create_empty();
    if(maximized == GLFW_TRUE)
    {
        event.type = event_window_maximize;
    }
    else
    {
        event.type = event_window_minimize;
    }
    application_on_event(event);
}

void glfw_close_window_event_callback(GLFWwindow* window) {
    event_t event = event_create_empty();
    event.type = event_window_close;
    application_on_event(event);
}

void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    event_t event = event_create_empty();

    switch(action)
    {
        case GLFW_RELEASE:
            event.type = event_key_released;
            break;
        case GLFW_PRESS:
            event.type = event_key_pressed;
            break;
        case GLFW_REPEAT:
            event.type = event_key_repeated;
            break;
        default:
        EXIT_ERROR("GLFW unsupported event type: %i\n", action);
            break;
    }

    event.key = glfw_key_to_key_t(key);
    application_on_event(event);
    //printf("key: %i, scancode: %i, action: %i, mods: %i\n", key, scancode, action, mods);
}

void glfw_mouse_scrolled_callback(GLFWwindow* window, double x, double y)
{
    printf("scroll %f\n", y);

    event_t event = event_create_empty();
    event.type = event_mouse_scrolled;
    event.mouse_x = x;
    event.mouse_y = y;
    application_on_event(event);
}


void glfw_window_init(window_t* window)
{
    if(!glfwInit())
    {
        EXIT_ERROR("Failed to initialize glfw\n");
    }

#ifdef CAZEL_DEBUG
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif
    window->handle = glfwCreateWindow(window->width, window->height, window->title, NULL, NULL);

    glfwSetWindowCloseCallback(window->handle, glfw_close_window_event_callback);
    glfwSetWindowSizeCallback(window->handle, glfw_window_resize_callback);
    glfwSetWindowMaximizeCallback(window->handle, glfw_window_maximize_callback);
    glfwSetKeyCallback(window->handle, glfw_key_callback);
    glfwSetScrollCallback(window->handle, glfw_mouse_scrolled_callback);
    
    //Questionable to init the context in the window. Not sure what a better way might be.
    context_init(window);
}

void glfw_window_close(window_t* window)
{
    glfwDestroyWindow(window->handle);
}
