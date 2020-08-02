//
// Created by Frank on 02/08/2020.
//

#ifndef SANDBOX_LINUX_WINDOW_H
#define SANDBOX_LINUX_WINDOW_H


#include "../../window.h"

//Initialize a windows specific window using glfw
void linux_window_init(window_t* window);

//Destroy windows specific window using glfw
void linux_window_close(window_t* window);


#endif //SANDBOX_LINUX_WINDOW_H
