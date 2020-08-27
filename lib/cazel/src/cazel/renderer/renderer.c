//
// Created by Frank on 05/08/2020.
//

#include "renderer.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "../../../lib/glad/include/glad/glad.h"
#include "../platform/opengl/opengl_context.h"

static mat4* s_projection_matrix;

void renderer_begin_scene(mat4* projection_matrix)
{
    s_projection_matrix = projection_matrix;
}

void renderer_submit_with_transform(vertex_array_t* vertex_array, mat4 transform)
{
    context_bind_vertex_array(vertex_array);
    context_bind_shader(vertex_array);

    opengl_context_upload_uniform_mat4(vertex_array->shader_id, "u_ViewProjectionMatrix", *s_projection_matrix);
    opengl_context_upload_uniform_mat4(vertex_array->shader_id, "u_Transform", transform);

    glDrawElements(GL_TRIANGLES, vertex_array->index_count, GL_UNSIGNED_INT, NULL);
}

void renderer_submit(vertex_array_t* vertex_array)
{
    mat4 transform = GLM_MAT4_IDENTITY_INIT;
    renderer_submit_with_transform(vertex_array, transform);
}

void renderer_end_scene()
{

}
