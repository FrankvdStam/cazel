//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_CONTEXT_H
#define SANDBOX_CONTEXT_H

#include "core.h"
#include "window.h"
#include "renderer/buffers/buffers.h"
#include <cglm/cglm.h>

//typedef unsigned int vertex_buffer_t;
//typedef unsigned int shader_t;
//typedef unsigned int index_buffer_t;

typedef struct
{
    unsigned int vertex_buffer_id;
    unsigned int vertex_count;
    unsigned int vertex_total_floats;

    buffer_layout_t vertex_layout;

    unsigned int index_buffer_id;
    unsigned int index_count;

    unsigned int shader_id;

    unsigned int vertex_array_id;
} vertex_array_t;

//Resolve platform specific functions
void context_platform_init(platform_t platform);

//Initialize the context
extern void(*context_init)(window_t*window);

//Swap buffers
extern void(*context_swap_buffers)(window_t* window);


//========================================================================================================================================================================================================================
//Vertex array

//Generate a vertex array
extern void(*context_create_vertex_array)(vertex_array_t* vertex_array);

//Bind a given vertex array
extern void(*context_bind_vertex_array)(vertex_array_t* vertex_array);

//Free a given vertex array - if the vertex array was malloc'ed, it must be free'd by the user as well - this function only takes care of the data on the graphics card
extern void(*context_free_vertex_array)(vertex_array_t* vertex_array);



//========================================================================================================================================================================================================================
//Vertex buffers

//Creates a vertex buffer on the graphics card, fills it with data and returns a handle to it
extern void(*context_create_vertex_buffer)(vertex_array_t* vertex_array, float* vertices, size_t count, size_t total_floats);

//Binds a vertex buffer
extern void(*context_bind_vertex_buffer)(vertex_array_t* vertex_array);

//Frees a given vertex buffer from the graphics card
extern void(*context_free_vertex_buffer)(vertex_array_t* vertex_array);

//Sets the layout for the a given vertex buffer to the provided buffer layout
extern void(*context_set_vertex_buffer_layout)(vertex_array_t* vertex_array);


//========================================================================================================================================================================================================================
//index buffers

//Creates an index buffer on the graphics card, fills it with data and returns a handle to it
extern void(*context_create_index_buffer)(vertex_array_t* vertex_array, uint32_t* indices, size_t count);

//Binds an index buffer
extern void(*context_bind_index_buffer)(vertex_array_t* vertex_array);

//Frees a given index buffer from the graphics card
extern void(*context_free_index_buffer)(vertex_array_t* vertex_array);

//========================================================================================================================================================================================================================
//Shaders

//Creates a shader from the given source
extern unsigned int(*context_create_shader)(const char* vertex_shader_source, const char* fragment_shader_source);

//Bind the given shader
extern void(*context_bind_shader)(unsigned int shader);

//Free the given shader
extern void(*context_free_shader)(unsigned int shader);

//========================================================================================================================================================================================================================
//Clear color

//Set the color the screen should clear to
extern void(*context_set_clear_color)(float r, float g, float b, float a);

//Clear the screen to the clear color set by context_set_clear_color
extern void(*context_clear)();


//========================================================================================================================================================================================================================
//Uniforms

//Upload a mat4 uniform to the given shader and the given uniform name
//extern void (*context_upload_uniform_mat4)(unsigned int shader, const char* name, mat4 matrix);
//extern void (*context_upload_uniform_vec4)(unsigned int shader, const char* name, vec4 vec);

//========================================================================================================================================================================================================================
//Time
extern float (*context_get_time)();


//========================================================================================================================================================================================================================
//Textures

//Loads a given texture into graphics memory
extern unsigned int (*context_load_texture)(const char* filepath);








#endif //SANDBOX_CONTEXT_H
