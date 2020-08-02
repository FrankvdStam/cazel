//
// Created by Frank on 28/07/2020.
//

#include "core.h"
#include "platform/windows/windows_input.h"

bool(*input_mouse_button_pressed)(window_t* window, int button);

void input_platform_init(platform_t platform)
{
#ifdef WINDOWS
    input_mouse_button_pressed = &windows_mouse_button_pressed;
#else
    EXIT_ERROR("Linux not supported.\n");
#endif

}