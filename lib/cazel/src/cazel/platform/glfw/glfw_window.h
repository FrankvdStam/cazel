//
// Created by Frank on 27/07/2020.
//

#ifndef WINDOWS_WINDOW_H
#define WINDOWS_WINDOW_H

#include "../../window.h"

//Initialize a glfw specific window using glfw
void glfw_window_init(window_t* window);

//Destroy glfw specific window using glfw
void glfw_window_close(window_t* window);




#endif //WINDOWS_WINDOW_H
