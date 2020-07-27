//
// Created by Frank on 27/07/2020.
//

#ifndef WINDOWS_WINDOW_H
#define WINDOWS_WINDOW_H

#include "../window.h"


//Initialize a windows specific window using glfw
void windows_window_init(window_t* window);

//Destroy windows specific window using glfw
void windows_window_close(window_t* window);




#endif //WINDOWS_WINDOW_H
