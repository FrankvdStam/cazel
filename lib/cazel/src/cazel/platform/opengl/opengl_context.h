//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_OPENGL_CONTEXT_H
#define SANDBOX_OPENGL_CONTEXT_H

//#define GLFW_INCLUDE_NONE
//#include "GLFW/glfw3.h"
//#include "../../../../lib/glad/include/glad/glad.h"

#include "../../window.h"
#include "../../context.h"



void opengl_context_init(window_t* window);
void opengl_context_swap_buffers(window_t* window);


//========================================================================================================================================================================================================================
//Vertex buffers
vertex_buffer_t opengl_context_create_vertex_buffer(float* vertices, size_t count);
void opengl_context_bind_vertex_buffer(vertex_buffer_t vertex_buffer);
void opengl_context_free_vertex_buffer(vertex_buffer_t vertex_buffer);
void opengl_context_set_vertex_buffer_layout(vertex_buffer_t vertex_buffer, buffer_layout_t* buffer_layout);

//========================================================================================================================================================================================================================
//index buffers
index_buffer_t opengl_context_create_index_buffer(uint32_t* indices, size_t count);
void opengl_context_bind_index_buffer(index_buffer_t index_buffer);
void opengl_context_free_index_buffer(index_buffer_t index_buffer);

//========================================================================================================================================================================================================================
//Shaders
shader_t opengl_context_create_shader(const char* vertex_shader_source, const char* fragment_shader_source);
void opengl_context_bind_shader(shader_t shader);
void opengl_context_free_shader(shader_t shader);

//========================================================================================================================================================================================================================
//Vertex array
vertex_array_t opengl_context_create_vertex_array();
void opengl_context_bind_vertex_array(vertex_array_t vertex_array);
void opengl_context_free_vertex_array(vertex_array_t vertex_array);

//========================================================================================================================================================================================================================
//Clear color
void opengl_context_set_clear_color(float r, float g, float b, float a);
void opengl_context_clear();

#endif //SANDBOX_OPENGL_CONTEXT_H
