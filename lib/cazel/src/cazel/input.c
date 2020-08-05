//
// Created by Frank on 28/07/2020.
//

#include "core.h"
#include "platform/glfw/glfw_input.h"

bool(*input_mouse_button_pressed)(window_t* window, mouse_button_t button);
bool(*input_key_pressed)(window_t* window, key_t key);

void input_platform_init(platform_t platform)
{
    input_mouse_button_pressed = &glfw_mouse_button_pressed;
    input_key_pressed =&glfw_key_pressed;
}
