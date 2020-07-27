//
// Created by Frank on 27/07/2020.
//

#include "core.h"
#include "platform/windows_window.h"

#ifdef WINDOWS
    //fun_window_init
#endif

void(*window_init)(window_t* window);
void(*window_close)(window_t* window);

void window_platform_init(platform_t platform)
{
#ifdef WINDOWS
    window_init = &windows_window_init;
    window_close = &windows_window_close;
#else
    EXIT_ERROR("Linux not supported.\n");
#endif

}
