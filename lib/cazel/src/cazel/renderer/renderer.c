//
// Created by Frank on 05/08/2020.
//

#include "renderer.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "../../../lib/glad/include/glad/glad.h"

void renderer_begin_scene()
{

}

void renderer_submit(vertex_array_t* vertex_array)
{
    context_bind_vertex_array(vertex_array);
    context_bind_vertex_buffer(vertex_array);
    context_bind_index_buffer(vertex_array);
    context_bind_shader(vertex_array->shader_id);
    glDrawElements(GL_TRIANGLES, vertex_array->index_count, GL_UNSIGNED_INT, NULL);

}

void renderer_end_scene()
{

}
