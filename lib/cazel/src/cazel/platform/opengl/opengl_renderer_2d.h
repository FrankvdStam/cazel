//
// Created by Frank on 27/08/2020.
//

#ifndef SANDBOX_OPENGL_RENDERER_2D_H
#define SANDBOX_OPENGL_RENDERER_2D_H

#define CGLM_DEFINE_PRINTS
#include <cglm/cglm.h>
#include "../../../../lib/glad/include/glad/glad.h"
#include "../../renderer/orthographic_camera.h"



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

static const uint32_t quad_vertex_float_count = 11;


static const uint32_t max_quads = 20000;
static const uint32_t max_vertices = max_quads * 4;
static const uint32_t max_indices = max_quads * 6;
static const uint32_t max_texture_slots = 32; // TODO: RenderCaps



void opengl_renderer_2d_init();
void opengl_renderer_2d_begin_scene(orthographic_camera_t* camera);
void opengl_renderer_2d_draw_colored_quad(const vec2* position, const vec2* size, vec4* color);
void opengl_renderer_2d_draw_simple_quad();
void opengl_renderer_2d_EndScene();
void opengl_renderer_2d_Flush();


#endif //SANDBOX_OPENGL_RENDERER_2D_H
