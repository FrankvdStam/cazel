//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_CONTEXT_H
#define SANDBOX_CONTEXT_H

#include "core.h"
#include "window.h"
#include "renderer/buffers/buffers.h"

void context_platform_init(platform_t platform);

void(*context_init)(window_t*window);
void(*context_swap_buffers)(window_t* window);

//buffers
typedef unsigned int vertex_buffer_t;
typedef unsigned int index_buffer_t;

vertex_buffer_t(*context_create_vertex_buffer)(float* vertices, size_t count);
index_buffer_t(*context_create_index_buffer)(uint32_t* indices, size_t count);

void(*context_bind_vertex_buffer)(vertex_buffer_t vertex_buffer);
void(*context_bind_index_buffer)(index_buffer_t index_buffer);

void(*context_free_vertex_buffer)(vertex_buffer_t vertex_buffer);
void(*context_free_index_buffer)(index_buffer_t index_buffer);

void(*context_set_vertex_buffer_layout)(vertex_buffer_t vertex_buffer, buffer_layout_t* buffer_layout);

#endif //SANDBOX_CONTEXT_H
