//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_OPENGL_CONTEXT_H
#define SANDBOX_OPENGL_CONTEXT_H

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "../../../lib/glad/include/glad/glad.h"

#include "../../window.h"
#include "../../context.h"


GLuint opengl_create_shader(const char* vertex_shader_source, const char* fragment_shader_source);

void opengl_context_init(window_t* window);
void opengl_context_swap_buffers(window_t* window);

vertex_buffer_t opengl_context_create_vertex_buffer(float* vertices, size_t count);
index_buffer_t opengl_context_create_index_buffer(uint32_t* indices, size_t count);

void opengl_context_bind_vertex_buffer(vertex_buffer_t vertex_buffer);
void opengl_context_bind_index_buffer(index_buffer_t index_buffer);

void opengl_context_free_vertex_buffer(vertex_buffer_t vertex_buffer);
void opengl_context_free_index_buffer(index_buffer_t index_buffer);

void opengl_context_set_vertex_buffer_layout(vertex_buffer_t vertex_buffer, buffer_layout_t* buffer_layout);



#endif //SANDBOX_OPENGL_CONTEXT_H
