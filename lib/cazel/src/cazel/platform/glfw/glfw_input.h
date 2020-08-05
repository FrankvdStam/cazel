//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_GLFW_INPUT_H
#define SANDBOX_GLFW_INPUT_H

#include "../../core.h"
#include "../../input.h"

key_t glfw_key_to_key_t(int key);
int key_t_to_glfw(key_t key);


bool glfw_mouse_button_pressed(window_t* window, mouse_button_t button);
bool glfw_key_pressed(window_t* window, key_t key);

#endif //SANDBOX_GLFW_INPUT_H
