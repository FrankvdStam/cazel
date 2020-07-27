//
// Created by Frank on 27/07/2020.
//

#include "platform/windows_window.h"


void window_init(window_t window)
{
    switch (window.platform)
    {
        case windows:
            windows_window_init(window);
            break;
    }
}

bool window_should_close(window_t window)
{
    return false;
}