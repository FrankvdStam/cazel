//
// Created by Frank on 27/08/2020.
//

#ifndef SANDBOX_OPENGL_RENDERER_2D_H
#define SANDBOX_OPENGL_RENDERER_2D_H

#include <cglm/cglm.h>
#include <glad/glad.h>

typedef void (quad_func)(int x, int y);

typedef struct
{
    void* (init);
    void* (shutdown);


    quad_func* quad;

} renderer_2d_t;




//Represents a single vertex for a quad
typedef struct
{
    vec3 position;
    vec4 color;
    vec2 texture_coordinate;
    float texture_index;
    float tiling_factor;
} quad_vertex_t;

static const uint32_t max_quads = 20000;
static const uint32_t max_vertices = max_quads * 4;
static const uint32_t max_indices = max_quads * 6;
static const uint32_t max_texture_slots = 32; // TODO: RenderCaps







#endif //SANDBOX_OPENGL_RENDERER_2D_H
