//
// Created by Frank on 27/07/2020.
//

#include "core.h"
#include "platform/glfw/glfw_window.h"

void(*window_init)(window_t* window);
void(*window_close)(window_t* window);

void window_platform_init(platform_t platform)
{
#ifdef CAZEL_WINDOWS
    window_init = &glfw_window_init;
    window_close = &glfw_window_close;
#elif CAZEL_LINUX
    window_init = &linux_window_init;
    window_close = &linux_window_close;
#endif
}
