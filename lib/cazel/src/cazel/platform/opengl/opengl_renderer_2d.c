//
// Created by Frank on 27/08/2020.
//

#include "opengl_renderer_2d.h"
#include "../../context.h"
#include "opengl_context.h"
#include <cglm/cglm.h>


//helper
GLuint create_white_texture()
{
    GLuint texture_id = 0;
    glCreateTextures(GL_TEXTURE_2D, 1, &texture_id);
    glTextureStorage2D(texture_id, 1, GL_RGBA8, 1, 1);

    glTextureParameteri(texture_id, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(texture_id, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char tex[4] = {0xFF, 0xFF, 0xFF, 0xFF};

    glTextureSubImage2D(texture_id, 0, 0, 0, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, tex);
    return texture_id;
}




static quad_vertex_t* quad_vertices;
static size_t quad_vertices_index;
static vertex_array_t vertex_array;
static GLuint white_texture;
static GLuint* texture_slots;
static size_t texture_slot_index;
static vec4 s_quad_vertex_positions[4];


void opengl_renderer_2d_init()
{
    //Create vertex array for the quads
    context_create_vertex_array(&vertex_array);


    //Setup the vertices - using calloc to zero initialize
    quad_vertices = calloc(max_vertices, sizeof(quad_vertex_t));
    quad_vertices_index = 0;

    //Create vertex buffer for the quads
    context_create_vertex_buffer(&vertex_array, quad_vertices, max_vertices, quad_vertex_float_count * max_vertices);


    //Buffer layout for the vertices
    buffer_element_t elements[] =
    {
        buffers_create_buffer_element(shader_data_type_float3), //position
        buffers_create_buffer_element(shader_data_type_float4), //color
        buffers_create_buffer_element(shader_data_type_float2), //texture coordinate
        buffers_create_buffer_element(shader_data_type_float),  //texture index
        buffers_create_buffer_element(shader_data_type_float),  //tiling factor
    };
    buffers_create_buffer_layout(&vertex_array.vertex_layout, elements, 5);
    context_set_vertex_buffer_layout(&vertex_array);


    //setup the indices
    uint32_t* quad_indices = calloc(max_indices, sizeof(uint32_t));
    uint32_t offset = 0;
    for (uint32_t i = 0; i < max_indices; i += 6)
    {
        quad_indices[i + 0] = offset + 0;
        quad_indices[i + 1] = offset + 1;
        quad_indices[i + 2] = offset + 2;

        quad_indices[i + 3] = offset + 2;
        quad_indices[i + 4] = offset + 3;
        quad_indices[i + 5] = offset + 0;

        offset += 4;
    }
    context_create_index_buffer(&vertex_array, quad_indices, max_indices);
    free(quad_indices);


    //Setup the white texture
    white_texture = create_white_texture();


    //setup shader and samplers
    int32_t* samplers = malloc(max_texture_slots * sizeof(int32_t));
    for (uint32_t i = 0; i < max_texture_slots; i++)
        samplers[i] = i;

    context_create_shader_from_file(&vertex_array, "assets/shaders/texture.glsl");
    context_bind_shader(&vertex_array);
    opengl_context_upload_uniform_int_array(vertex_array.shader_id, "u_Textures", samplers, max_texture_slots);
    free(samplers);


    //setup texture slots
    texture_slots = calloc(max_texture_slots, sizeof(GLuint));
    texture_slots[0] = white_texture;


    //setup vertex positions
    glm_quat_init(s_quad_vertex_positions[0], -0.5f, -0.5f, 0.0f, 1.0f);
    glm_quat_init(s_quad_vertex_positions[1],  0.5f, -0.5f, 0.0f, 1.0f);
    glm_quat_init(s_quad_vertex_positions[2],  0.5f,  0.5f, 0.0f, 1.0f);
    glm_quat_init(s_quad_vertex_positions[3], -0.5f,  0.5f, 0.0f, 1.0f);
}

void opengl_renderer_2d_flush_and_reset()
{
    opengl_renderer_2d_EndScene();
    quad_vertices_index = 0;
    texture_slot_index = 1;
}

void opengl_renderer_2d_draw_simple_quad()
{
    size_t quad_vertex_count = 4;
    const float textureIndex = 0.0f; // White Texture
    //vec2 textureCoords[] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };
    const float tilingFactor = 1.0f;

    for (size_t i = 0; i < quad_vertex_count; i++)
    {
        quad_vertices[quad_vertices_index].position[0] = 0.0f;
        quad_vertices[quad_vertices_index].position[1] = 0.0f;
        quad_vertices[quad_vertices_index].position[2] = 0.0f;

        quad_vertices[quad_vertices_index].color[0] = 1.0f;
        quad_vertices[quad_vertices_index].color[1] = 1.0f;
        quad_vertices[quad_vertices_index].color[2] = 1.0f;
        quad_vertices[quad_vertices_index].color[3] = 1.0f;

        quad_vertices[quad_vertices_index].texture_index = textureIndex;
        quad_vertices[quad_vertices_index].tiling_factor = tilingFactor;

        quad_vertices_index++;
    }
}


void opengl_renderer_2d_draw_colored_quad(const vec2* position, const vec2* size, vec4* color)
{
    mat4 translation = GLM_MAT4_IDENTITY_INIT;

    vec3 position_vec3 = { *position[0], *position[1], 0.0f };
    glm_translate(translation, position_vec3);

    mat4 scale = GLM_MAT4_IDENTITY_INIT;
    vec3 size_vec3 = { *size[0], *size[1], 1.0f };
    glm_scale(scale, size_vec3);

    mat4 transform = GLM_MAT4_ZERO_INIT;
    glm_mul(translation, scale, transform);


    //mat4 translate = GLM_MAT4_IDENTITY_INIT;
    //vec3 pos_vec3 = { *position[0], *position[1], 0.0f };
    //glm_translate(translate, pos_vec3);
//
    //mat4 scale = GLM_MAT4_IDENTITY_INIT;
    //vec3 size_vec3 = { *size[0], *size[1], 1.0f };
    //glm_scale(scale, size_vec3);
//
    //mat4 transform = GLM_MAT4_ZERO_INIT;
    //glm_mul(translate, scale, transform);




    size_t quad_vertex_count = 4;
    const float textureIndex = 0.0f; // White Texture
    vec2 textureCoords[] = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };
    const float tilingFactor = 1.0f;

    if (quad_vertices_index >= max_indices)
    {
        opengl_renderer_2d_flush_and_reset();
    }

    for (size_t i = 0; i < quad_vertex_count; i++)
    {
        vec4 final_position = GLM_VEC3_ZERO_INIT;
        glm_mul(transform, &s_quad_vertex_positions[i], &final_position);


        printf("final pos:\n");
        glm_vec4_print(final_position, stdout);

        glm_vec3_copy(final_position    , quad_vertices[quad_vertices_index].position           );
        printf("copy:\n");
        glm_vec3_print(quad_vertices[quad_vertices_index].position, stdout);

        glm_vec4_copy(*color            , quad_vertices[quad_vertices_index].color              );
        glm_vec2_copy(textureCoords[i]  , quad_vertices[quad_vertices_index].texture_coordinate );

        quad_vertices[quad_vertices_index].texture_index = textureIndex;
        quad_vertices[quad_vertices_index].tiling_factor = tilingFactor;

        quad_vertices_index++;
    }
}

void opengl_renderer_2d_begin_scene(orthographic_camera_t* camera)
{
    opengl_context_bind_shader(&vertex_array);
    opengl_context_upload_uniform_mat4(vertex_array.shader_id, "u_ViewProjection", camera->view_projection_matrix);

    quad_vertices_index = 0;
    texture_slot_index = 0;
}

void opengl_renderer_2d_EndScene()
{
    glBindBuffer(GL_ARRAY_BUFFER, vertex_array.vertex_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * quad_vertex_float_count * quad_vertices_index, quad_vertices, GL_STATIC_DRAW);
    opengl_renderer_2d_Flush();
}

void opengl_renderer_2d_Flush()
{
    if (quad_vertices_index == 0)
        return; // Nothing to draw

    // Bind textures
    for (uint32_t i = 0; i < texture_slot_index; i++)
    {
        opengl_context_bind_texture(i, texture_slots[i]);
    }

    uint32_t count = quad_vertices_index ? quad_vertices_index : vertex_array.index_count;
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);

    printf("Drew %i triangles\n", count);
}



