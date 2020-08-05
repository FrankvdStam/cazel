//
// Created by Frank on 05/08/2020.
//

#include "renderer.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "../../../lib/glad/include/glad/glad.h"

static mat4* s_projection_matrix;

void renderer_begin_scene(mat4* projection_matrix)
{
    s_projection_matrix = projection_matrix;
}

void renderer_submit(vertex_array_t* vertex_array)
{
    context_bind_vertex_array(vertex_array);
    context_bind_shader(vertex_array->shader_id);
    context_upload_uniform_mat4(vertex_array->shader_id, "u_ViewProjectionMatrix", *s_projection_matrix);
    glDrawElements(GL_TRIANGLES, vertex_array->index_count, GL_UNSIGNED_INT, NULL);

}

void renderer_end_scene()
{

}
