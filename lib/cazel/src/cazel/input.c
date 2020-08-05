//
// Created by Frank on 28/07/2020.
//

#include "core.h"
#include "platform/windows/windows_input.h"

bool(*input_mouse_button_pressed)(window_t* window, mouse_button_t button);
bool(*input_key_pressed)(window_t* window, key_t key);

void input_platform_init(platform_t platform)
{
#ifdef CAZEL_WINDOWS
    input_mouse_button_pressed = &windows_mouse_button_pressed;
    input_key_pressed =&windows_key_pressed;
#elif CAZEL_LINUX
    input_mouse_button_pressed = &windows_mouse_button_pressed;
    input_key_pressed =&windows_key_pressed;
#endif

}
