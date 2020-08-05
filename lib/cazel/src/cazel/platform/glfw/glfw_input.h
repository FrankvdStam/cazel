//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_GLFW_INPUT_H
#define SANDBOX_GLFW_INPUT_H

#include "../../core.h"
#include "../../input.h"

bool glfw_mouse_button_pressed(window_t* window, mouse_button_t button);
bool glfw_key_pressed(window_t* window, key_t key);

#endif //SANDBOX_GLFW_INPUT_H
