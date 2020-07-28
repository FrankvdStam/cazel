//
// Created by Frank on 28/07/2020.
//

#include "context.h"
#include "core.h"
#include "platform/opengl/opengl_context.h"

void(*context_init)(window_t* window);
void(*context_swap_buffers)(window_t* window);

vertex_buffer_t(*context_create_vertex_buffer)(float* vertices, size_t count);
index_buffer_t(*context_create_index_buffer)(uint32_t* indices, size_t count);

void(*context_bind_vertex_buffer)(vertex_buffer_t vertex_buffer);
void(*context_bind_index_buffer)(index_buffer_t index_buffer);

void(*context_free_vertex_buffer)(vertex_buffer_t vertex_buffer);
void(*context_free_index_buffer)(index_buffer_t index_buffer);

void context_platform_init(platform_t platform)
{
#ifdef WINDOWS
    context_init = &opengl_context_init;
    context_swap_buffers = &opengl_context_swap_buffers;

    context_create_vertex_buffer = opengl_context_create_vertex_buffer;
    context_create_index_buffer = opengl_context_create_index_buffer;

    context_bind_vertex_buffer = opengl_context_bind_vertex_buffer;
    context_bind_index_buffer = opengl_context_bind_index_buffer;

    context_free_vertex_buffer = opengl_context_free_vertex_buffer;
    context_free_index_buffer = opengl_context_free_index_buffer;
#else
    EXIT_ERROR("Linux not supported");
#endif
}




