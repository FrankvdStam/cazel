//
// Created by Frank on 28/07/2020.
//

#include "context.h"
#include "core.h"
#include "platform/opengl/opengl_context.h"


//Initialize the context
void(*context_init)(window_t*window);

//Swap buffers
void(*context_swap_buffers)(window_t* window);


//========================================================================================================================================================================================================================
//Vertex array

//Generate a vertex array
void(*context_create_vertex_array)(vertex_array_t* vertex_array);

//Bind a given vertex array
void(*context_bind_vertex_array)(vertex_array_t* vertex_array);

//Free a given vertex array - if the vertex array was malloc'ed, it must be free'd by the user as well - this function only takes care of the data on the graphics card
void(*context_free_vertex_array)(vertex_array_t* vertex_array);



//========================================================================================================================================================================================================================
//Vertex buffers

//Creates a vertex buffer on the graphics card, fills it with data and returns a handle to it
void(*context_create_vertex_buffer)(vertex_array_t* vertex_array, float* vertices, size_t count, size_t total_floats);

//Binds a vertex buffer
void(*context_bind_vertex_buffer)(vertex_array_t* vertex_array);

//Frees a given vertex buffer from the graphics card
void(*context_free_vertex_buffer)(vertex_array_t* vertex_array);

//Sets the layout for the a given vertex buffer to the provided buffer layout
void(*context_set_vertex_buffer_layout)(vertex_array_t* vertex_array);


//========================================================================================================================================================================================================================
//index buffers

//Creates an index buffer on the graphics card, fills it with data and returns a handle to it
void(*context_create_index_buffer)(vertex_array_t* vertex_array, uint32_t* indices, size_t count);

//Binds an index buffer
void(*context_bind_index_buffer)(vertex_array_t* vertex_array);

//Frees a given index buffer from the graphics card
void(*context_free_index_buffer)(vertex_array_t* vertex_array);

//========================================================================================================================================================================================================================
//Shaders

//Creates a shader from the given source
unsigned int(*context_create_shader)(const char* vertex_shader_source, const char* fragment_shader_source);

//Bind the given shader
void(*context_bind_shader)(unsigned int shader);

//Free the given shader
void(*context_free_shader)(unsigned int shader);

//========================================================================================================================================================================================================================
//Clear color

//Set the color the screen should clear to
void(*context_set_clear_color)(float r, float g, float b, float a);

//Clear the screen to the clear color set by context_set_clear_color
void(*context_clear)();

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




