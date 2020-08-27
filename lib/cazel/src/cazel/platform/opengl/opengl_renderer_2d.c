//
// Created by Frank on 27/08/2020.
//

#include "opengl_renderer_2d.h"
#include "../../context.h"
#include <glad/glad.h>

//helper
GLuint create_white_texture()
{
    GLuint texture_id = 0;
    glCreateTextures(GL_TEXTURE_2D, 1, &texture_id);
    glTextureStorage2D(texture_id, 1, GL_RGBA8, 1, 1);

    glTextureParameteri(texture_id, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(texture_id, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTextureSubImage2D(texture_id, 0, 0, 0, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, (void*)0xFFFFFFFF);
}




static quad_vertex_t* quad_vertices;
static vertex_array_t vertex_array;
static GLuint texture_shader;
static GLuint white_texture;

void opengl_renderer_2d_init()
{
    //Create vertex array for the quads
    context_create_vertex_array(&vertex_array);

    //Setup the vertices - using calloc to zero initialize
    quad_vertices = calloc(max_vertices, sizeof(quad_vertex_t));

    //Create vertex buffer for the quads
    context_create_vertex_buffer(&vertex_array, quad_vertices, max_vertices, 11 * max_vertices);

    //Buffer layout for the vertices
    buffer_element_t elements[] =
    {
        buffers_create_buffer_element(shader_data_type_float3), //position
        buffers_create_buffer_element(shader_data_type_float4), //color
        buffers_create_buffer_element(shader_data_type_float2), //texture coordinate
        buffers_create_buffer_element(shader_data_type_float),  //texture index
        buffers_create_buffer_element(shader_data_type_float),  //tiling factor
    };
    buffers_create_buffer_layout(&vertex_array.vertex_layout, elements, sizeof(elements));
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
    context_create_index_buffer(&vertex_array, quad_indices, max_indices * sizeof(uint32_t));
    free(quad_indices);

    //Setup the white texture
    white_texture = create_white_texture();

    //setup shader and samplers
    int32_t* samplers = malloc(max_texture_slots * sizeof(int32_t));
    for (uint32_t i = 0; i < max_texture_slots; i++)
        samplers[i] = i;

    vertex_array.shader_id = context_create_shader_from_file("assets/shaders/texture.glsl");
    context_bind_shader(vertex_array.shader_id);

    s_Data.TextureShader = Shader::Create("assets/shaders/Texture.glsl");
    s_Data.TextureShader->Bind();
    s_Data.TextureShader->SetIntArray("u_Textures", samplers, s_Data.MaxTextureSlots);
    free(samplers);

    // Set all texture slots to 0
    s_Data.TextureSlots[0] = s_Data.WhiteTexture;

    s_Data.QuadVertexPositions[0] = { -0.5f, -0.5f, 0.0f, 1.0f };
    s_Data.QuadVertexPositions[1] = {  0.5f, -0.5f, 0.0f, 1.0f };
    s_Data.QuadVertexPositions[2] = {  0.5f,  0.5f, 0.0f, 1.0f };
    s_Data.QuadVertexPositions[3] = { -0.5f,  0.5f, 0.0f, 1.0f };
}



