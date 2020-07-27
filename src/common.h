//
// Created by Frank on 03/05/2020.
//

#ifndef CNES_COMMON_H
#define CNES_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <cglm/cglm.h>

//window/opengl
#define GLFW_INCLUDE_NONE
#include "../lib/glfw/include/GLFW/glfw3.h"
#include "../lib/glad/include/glad/glad.h"

//void checkGLError()
//{
//    GLenum err;
//    while((err = glGetError()) != GL_NO_ERROR){
//        fprintf(stderr, err);
//    }
//}


#endif //CNES_COMMON_H
