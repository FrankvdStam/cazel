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

typedef enum
{
    mouse_button_left,
    mouse_button_right,
    mouse_button_middle,
} mouse_button_t;

extern bool(*input_mouse_button_pressed)(window_t* window, mouse_button_t button);

#endif //SANDBOX_INPUT_H
