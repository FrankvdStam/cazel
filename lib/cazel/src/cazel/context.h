//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_CONTEXT_H
#define SANDBOX_CONTEXT_H

#include "core.h"
#include "window.h"
#include "renderer/buffers/buffers.h"

typedef unsigned int vertex_buffer_t;
typedef unsigned int index_buffer_t;

//Resolve platform specific functions
void context_platform_init(platform_t platform);

//Initialize the context
extern void(*context_init)(window_t*window);

//Swap buffers
extern void(*context_swap_buffers)(window_t* window);

//Creates a vertex buffer on the graphics card, fills it with data and returns a handle to it
extern vertex_buffer_t(*context_create_vertex_buffer)(float* vertices, size_t count);

//Creates an index buffer on the graphics card, fills it with data and returns a handle to it
extern index_buffer_t(*context_create_index_buffer)(uint32_t* indices, size_t count);

//Binds a vertex buffer
extern void(*context_bind_vertex_buffer)(vertex_buffer_t vertex_buffer);

//Binds an index buffer
extern void(*context_bind_index_buffer)(index_buffer_t index_buffer);

//Frees a given vertex buffer from the graphics card
extern void(*context_free_vertex_buffer)(vertex_buffer_t vertex_buffer);

//Frees a given index buffer from the graphics card
extern void(*context_free_index_buffer)(index_buffer_t index_buffer);

//Sets the layout for the a given vertex buffer to the provided buffer layout
extern void(*context_set_vertex_buffer_layout)(vertex_buffer_t vertex_buffer, buffer_layout_t* buffer_layout);

#endif //SANDBOX_CONTEXT_H
