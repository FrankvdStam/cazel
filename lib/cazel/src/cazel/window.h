//
// Created by Frank on 27/07/2020.
//

#ifndef WINDOW_H
#define WINDOW_H

#include "core.h"


typedef struct
{
    char* title;
    uint32_t width;
    uint32_t height;
    bool vsync_enabled;

    void* handle;
} window_t;

#ifdef WINDOWS
    #include "platform/windows/windows_window.h"
#endif

//Resolve platform api's, called automatically during initialization
void window_platform_init(platform_t platform);


//Initializes a platform specific window using the parameters of the window struct
extern void(*window_init)(window_t* window);

//Closes a initialized window
extern void(*window_close)(window_t* window);


#endif //WINDOW_H