//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_OPENGL_CONTEXT_H
#define SANDBOX_OPENGL_CONTEXT_H

#include "../../window.h"
#include "../../context.h"
#include <cglm/cglm.h>


void opengl_context_init(window_t* window);
void opengl_context_swap_buffers(window_t* window);


//========================================================================================================================================================================================================================
//Vertex array
void opengl_context_create_vertex_array(vertex_array_t* vertex_array);
void opengl_context_bind_vertex_array(vertex_array_t* vertex_array);
void opengl_context_free_vertex_array(vertex_array_t* vertex_array);

//========================================================================================================================================================================================================================
//Vertex buffers
void opengl_context_create_vertex_buffer(vertex_array_t* vertex_array, float* vertices, size_t count, size_t total_floats);
void opengl_context_bind_vertex_buffer(vertex_array_t* vertex_array);
void opengl_context_free_vertex_buffer(vertex_array_t* vertex_array);
void opengl_context_set_vertex_buffer_layout(vertex_array_t* vertex_array);

//========================================================================================================================================================================================================================
//index buffers
void opengl_context_create_index_buffer(vertex_array_t* vertex_array, uint32_t* indices, size_t count);
void opengl_context_bind_index_buffer(vertex_array_t* vertex_array);
void opengl_context_free_index_buffer(vertex_array_t* vertex_array);

//========================================================================================================================================================================================================================
//Shaders
unsigned int opengl_context_create_shader(const char* vertex_shader_source, const char* fragment_shader_source);
void opengl_context_bind_shader(unsigned int shader);
void opengl_context_free_shader(unsigned int shader);

//========================================================================================================================================================================================================================
//Clear color
void opengl_context_set_clear_color(float r, float g, float b, float a);
void opengl_context_clear();

//========================================================================================================================================================================================================================
//Uniforms
void opengl_context_upload_uniform_mat4(unsigned int shader, const char* name, mat4 matrix);

//========================================================================================================================================================================================================================
//Time
float opengl_context_get_time();

#endif //SANDBOX_OPENGL_CONTEXT_H
