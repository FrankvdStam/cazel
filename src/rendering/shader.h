//
// Created by Frank on 06/07/2020.
//

#ifndef COPENGL_SHADER_H
#define COPENGL_SHADER_H

#include "../common.h"


#define SHADER_COLOR 0
#define SHADER_TEXTURE 1

//GLuint shader_create(const char* vertex_shader_source, const char* fragment_shader_source);
//void shader_use(GLuint shader);
//void shader_free(GLuint shader);


void init_shaders();
GLuint get_shader(size_t shader);
void free_shaders();


#endif //COPENGL_SHADER_H
