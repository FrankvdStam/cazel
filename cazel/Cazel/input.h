//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_INPUT_H
#define SANDBOX_INPUT_H

#include "core.h"
#include "window.h"

void input_platform_init(platform_t platform);


//=====================================================================================================================
//Mouse

#define MOUSE_BUTTON_LEFT   0
#define MOUSE_BUTTON_RIGHT  1
#define MOUSE_BUTTON_MIDDLE 2

bool(*input_mouse_button_pressed)(window_t* window, int button);

#endif //SANDBOX_INPUT_H
