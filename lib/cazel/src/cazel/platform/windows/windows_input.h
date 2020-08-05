//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_WINDOWS_INPUT_H
#define SANDBOX_WINDOWS_INPUT_H

#include "../../core.h"
#include "../../input.h"

bool windows_mouse_button_pressed(window_t* window, mouse_button_t button);
bool windows_key_pressed(window_t* window, key_t key);

#endif //SANDBOX_WINDOWS_INPUT_H
