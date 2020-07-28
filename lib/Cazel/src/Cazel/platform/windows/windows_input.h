//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_WINDOWS_INPUT_H
#define SANDBOX_WINDOWS_INPUT_H

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "../../core.h"
#include "../../input.h"

bool windows_mouse_button_pressed(window_t* window, int button);

#endif //SANDBOX_WINDOWS_INPUT_H
