//
// Created by Frank on 28/07/2020.
//

#include "context.h"
#include "core.h"
#include "platform/opengl/opengl_context.h"

void(*context_init)(window_t* window);
void(*context_swap_buffers)(window_t* window);

//Vertex buffers
vertex_buffer_t(*context_create_vertex_buffer)(float* vertices, size_t count);
void(*context_bind_vertex_buffer)(vertex_buffer_t vertex_buffer);
void(*context_free_vertex_buffer)(vertex_buffer_t vertex_buffer);
void(*context_set_vertex_buffer_layout)(vertex_buffer_t vertex_buffer, buffer_layout_t* buffer_layout);

//Index buffers
index_buffer_t(*context_create_index_buffer)(uint32_t* indices, size_t count);
void(*context_bind_index_buffer)(index_buffer_t index_buffer);
void(*context_free_index_buffer)(index_buffer_t index_buffer);

//shaders
shader_t(*context_create_shader)(const char* vertex_shader_source, const char* fragment_shader_source);
void(*context_bind_shader)(shader_t shader);
void(*context_free_shader)(shader_t shader);

//Vertex array
vertex_array_t(*context_create_vertex_array)();
void(*context_bind_vertex_array)(vertex_array_t vertex_array);
void(*context_free_vertex_array)(vertex_array_t vertex_array);

//========================================================================================================================================================================================================================
//Clear color
void(*context_set_clear_color)(float r, float g, float b, float a);
void(*context_clear)();


void context_platform_init(platform_t platform)
{
    context_init                        = &opengl_context_init;
    context_swap_buffers                = &opengl_context_swap_buffers;

    //Vertex buffers
    context_create_vertex_buffer        = &opengl_context_create_vertex_buffer;
    context_bind_vertex_buffer          = &opengl_context_bind_vertex_buffer;
    context_free_vertex_buffer          = &opengl_context_free_vertex_buffer;
    context_set_vertex_buffer_layout    = &opengl_context_set_vertex_buffer_layout;

    //index buffers
    context_create_index_buffer         = &opengl_context_create_index_buffer;
    context_bind_index_buffer           = &opengl_context_bind_index_buffer;
    context_free_index_buffer           = &opengl_context_free_index_buffer;

    //shaders
    context_create_shader               = &opengl_context_create_shader;
    context_bind_shader                 = &opengl_context_bind_shader;
    context_free_shader                 = &opengl_context_free_shader;

    //vertex array
    context_create_vertex_array         = &opengl_context_create_vertex_array;
    context_bind_vertex_array           = &opengl_context_bind_vertex_array;
    context_free_vertex_array           = &opengl_context_free_vertex_array;

    //Clear color
    context_set_clear_color             = &opengl_context_set_clear_color;
    context_clear                       = &opengl_context_clear;
}




