//
// Created by Frank on 27/07/2020.
//

#ifndef WINDOW_H
#define WINDOW_H


#include <stdint.h>
#include <stdbool.h>

typedef enum
{
    windows
} platform_t;


typedef struct
{
    platform_t platform;
    char* title;
    uint32_t width;
    uint32_t height;
    bool vsync_enabled;

    void* handle;
} window_t;

//Initializes a platform specific window using the parameters of the window struct
void window_init(window_t window);

//Checks if a initialized window should be closed
bool window_should_close(window_t window);

#endif //WINDOW_H