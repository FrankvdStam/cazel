//
// Created by Frank on 28/07/2020.
//

#include "core.h"
#include "platform/windows/windows_input.h"

bool(*input_mouse_button_pressed)(window_t* window, int button);

void input_platform_init(platform_t platform)
{
#ifdef CAZEL_WINDOWS
    input_mouse_button_pressed = &windows_mouse_button_pressed;
#elif CAZEL_LINUX
    input_mouse_button_pressed = &windows_mouse_button_pressed;
#endif

}
