#define CGLM_DEFINE_PRINTS

#define __USE_MINGW_ANSI_STDIO
#include <stdio.h>




#include "../lib/cazel/src/cazel.h"
#include "../lib/cazel/src/cazel/renderer/renderer.h"
#include "../lib/cazel/src/cazel/renderer/orthographic_camera.h"

#include "../lib/cazel/src/cazel/platform/opengl/opengl_context.h"
#include "../lib/cazel/src/cazel/renderer/shaders.h"
#include <time.h>
#include <inttypes.h>

struct timespec diff(struct timespec start, struct timespec end);

int sta()
{
    struct timespec time1, time2;
    int temp = 0;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
    for (int i = 0; i< 242000000; i++)
        temp+=temp;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
    printf("s: %lld, n: %ld \n", diff(time1,time2).tv_sec, diff(time1,time2).tv_nsec);
    return 0;
}

struct timespec diff(struct timespec start, struct timespec end)
{
    struct timespec temp;
    if ((end.tv_nsec-start.tv_nsec)<0) {
        temp.tv_sec = end.tv_sec-start.tv_sec-1;
        temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
    } else {
        temp.tv_sec = end.tv_sec-start.tv_sec;
        temp.tv_nsec = end.tv_nsec-start.tv_nsec;
    }
    return temp;
}



vertex_array_t s_triangle;
vertex_array_t s_square;
vertex_array_t s_textured_square;
vertex_array_t s_transparent_textured_square;
orthographic_camera_t s_camera;

float s_camera_speed = 1.0f;






//========================================================================================================================================================================================================================
//triangle

void setup_triangle()
{
    context_create_vertex_array(&s_triangle);
    context_bind_vertex_array(&s_triangle);

    s_triangle.shader_id = context_create_shader_from_file("assets/shaders/vertex_color.glsl");
    context_bind_shader(s_triangle.shader_id);




    float triangle_vertices[] = {
            -0.5f, -0.5f, 0.0f, 0.5f, 1.0f, 1.1f, 1.1f,
             0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 1.1f, 1.1f,
             0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 0.1f, 1.1f,
    };

    context_create_vertex_buffer(&s_triangle, triangle_vertices, 3, 21);
    context_bind_vertex_buffer(&s_triangle);
    buffer_element_t elements[] =
    {
            buffers_create_buffer_element(shader_data_type_float3),
            buffers_create_buffer_element(shader_data_type_float4),
    };

    buffers_create_buffer_layout(&s_triangle.vertex_layout, elements, 2);
    context_set_vertex_buffer_layout(&s_triangle);

    uint32_t triangle_indices[3] = {0, 1, 2};
    context_create_index_buffer(&s_triangle, triangle_indices, 3);
}

//========================================================================================================================================================================================================================
//squares
void setup_squares()
{
    context_create_vertex_array(&s_square);
    context_bind_vertex_array(&s_square);

    s_square.shader_id = context_create_shader_from_file("assets/shaders/flat_color.glsl");
    context_bind_shader(s_square.shader_id);

    float square_vertices[] = {
            -0.75f, -0.75f, 0.0f,//       0.8f, 0.2f, 0.5f, 1.1f,
             0.75f, -0.75f, 0.0f,//       0.5f, 0.3f, 0.1f, 1.1f,
             0.75f,  0.75f, 0.0f,//       0.1f, 0.4f, 0.8f, 1.1f,
            -0.75f,  0.75f, 0.0f,//       0.7f, 0.8f, 0.9f, 1.1f,
    };

    context_create_vertex_buffer(&s_square, square_vertices, 4, 12);
    context_bind_vertex_buffer(&s_square);

    buffer_element_t flat_color_buffer_layout_elements[] =
    {
            buffers_create_buffer_element(shader_data_type_float3),
    };
    buffers_create_buffer_layout(&s_square.vertex_layout, flat_color_buffer_layout_elements, 1);
    context_set_vertex_buffer_layout(&s_square);

    uint32_t square_indices[6] = {0, 1, 2, 2, 3, 0};
    context_create_index_buffer(&s_square, square_indices, 6);
}

//========================================================================================================================================================================================================================
//textured square
unsigned int texture_id;
void setup_textured_square()
{
    texture_id = context_load_texture("assets/textures/test_texture.png");
    opengl_context_bind_texture(0, texture_id);
    printf("tex: %u\n", texture_id);

    context_create_vertex_array(&s_textured_square);
    context_bind_vertex_array(&s_textured_square);

    s_textured_square.shader_id = context_create_shader_from_file("assets/shaders/texture.glsl");
    context_bind_shader(s_textured_square.shader_id);

    opengl_context_upload_uniform_int(s_textured_square.shader_id, "u_Texture", 0);

    float square_vertices[] = {
            -0.5f, -0.5f, 0.0f,     0.0f, 0.0f,
             0.5f, -0.5f, 0.0f,     1.0f, 0.0f,
             0.5f,  0.5f, 0.0f,     1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f,     0.0f, 1.0f,
    };

    context_create_vertex_buffer(&s_textured_square, square_vertices, 4, 20);
    context_bind_vertex_buffer(&s_textured_square);

    buffer_element_t buffer_elements[] =
    {
            buffers_create_buffer_element(shader_data_type_float3),
            buffers_create_buffer_element(shader_data_type_float2),
    };
    buffers_create_buffer_layout(&s_textured_square.vertex_layout, buffer_elements, 2);
    context_set_vertex_buffer_layout(&s_textured_square);

    uint32_t square_indices[6] = {0, 1, 2, 2, 3, 0};
    context_create_index_buffer(&s_textured_square, square_indices, 6);
}



//========================================================================================================================================================================================================================
//textured square
unsigned int transparent_texture_id;
void setup_transparent_textured_square()
{
    transparent_texture_id = context_load_texture("assets/textures/test_transparent_texture.png");
    opengl_context_bind_texture(0, transparent_texture_id);

    context_create_vertex_array(&s_transparent_textured_square);
    context_bind_vertex_array(&s_transparent_textured_square);

    s_transparent_textured_square.shader_id = context_create_shader_from_file("assets/shaders/texture.glsl");
    context_bind_shader(s_transparent_textured_square.shader_id);

    opengl_context_upload_uniform_int(s_transparent_textured_square.shader_id, "u_Texture", 0);

    float square_vertices[] = {
            -0.5f, -0.5f, 0.0f,     0.0f, 0.0f,
             0.5f, -0.5f, 0.0f,     1.0f, 0.0f,
             0.5f,  0.5f, 0.0f,     1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f,     0.0f, 1.0f,
    };

    context_create_vertex_buffer(&s_transparent_textured_square, square_vertices, 4, 20);
    context_bind_vertex_buffer(&s_transparent_textured_square);

    buffer_element_t buffer_elements[] =
            {
                    buffers_create_buffer_element(shader_data_type_float3),
                    buffers_create_buffer_element(shader_data_type_float2),
            };
    buffers_create_buffer_layout(&s_transparent_textured_square.vertex_layout, buffer_elements, 2);
    context_set_vertex_buffer_layout(&s_transparent_textured_square);

    uint32_t square_indices[6] = {0, 1, 2, 2, 3, 0};
    context_create_index_buffer(&s_transparent_textured_square, square_indices, 6);
}



void user_layer_on_attach()
{


    setup_triangle();
    setup_squares();
    setup_textured_square();
    setup_transparent_textured_square();





    //========================================================================================================================================================================================================================
    orthographic_camera_init(&s_camera, -1.6f, 1.6f, -0.9f, 0.9f);
    orthographic_camera_recalculate_view_projection_matrix(&s_camera);
}


void user_layer_on_update(float delta_time)
{
    if(input_key_pressed(&s_application.window, key_a))
    {
        s_camera.position[0] -= s_camera_speed * delta_time;
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
    }
    else if(input_key_pressed(&s_application.window, key_d))
    {
        s_camera.position[0] += s_camera_speed * delta_time;
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
    }

    if(input_key_pressed(&s_application.window, key_s))
    {
        s_camera.position[1] -= s_camera_speed * delta_time;
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
    }
    else if(input_key_pressed(&s_application.window, key_w))
    {
        s_camera.position[1] += s_camera_speed * delta_time;
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
    }


    //========================================================================================================================================================================================================================
    //rendering

    //struct timespec vartime = timer_start();  // begin a timer called 'vartime'

    opengl_context_enable_blending();

    renderer_begin_scene(&s_camera.view_projection_matrix);

    vec3 v = {0.1f, 0.1f, 0.1f};
    mat4 scale = GLM_MAT4_IDENTITY_INIT;
    glm_scale(scale, v);

    vec4 blue = {0.2f, 0.2f, 0.9f, 1.0f};
    vec4 red  = {0.9f, 0.2f, 0.2f, 1.0f};


    for(int y = 0; y < 20; y++)
    {
        for(int x = 0; x < 20; x++)
        {
            vec3 position = {x * 0.18f, y* 0.18f, 0.0f};
            mat4 transform = GLM_MAT4_IDENTITY_INIT;

            glm_translate(transform, position);
            glm_mat4_mul(transform, scale, transform);

            context_bind_shader(s_square.shader_id);
            if(x % 2 == 0)
            {
                opengl_context_upload_uniform_vec4(s_square.shader_id, "u_Color", blue);
            }
            else
            {
                opengl_context_upload_uniform_vec4(s_square.shader_id, "u_Color", red);
            }

            renderer_submit_with_transform(&s_square, transform);
        }
    }


    vec3 position = {-0.75f, 0.75f, 0.0f};
    mat4 textured_square_transform = GLM_MAT4_IDENTITY_INIT;
    glm_translate(textured_square_transform, position);


    renderer_submit(&s_triangle);

    opengl_context_bind_texture(0, texture_id);
    renderer_submit_with_transform(&s_textured_square, textured_square_transform);




    vec3 position2 = {0.75f, 0.75f, 0.0f};
    mat4 transparent_textured_square_transform = GLM_MAT4_IDENTITY_INIT;
    glm_translate(transparent_textured_square_transform, position2);


    opengl_context_bind_texture(0, transparent_texture_id);
    renderer_submit_with_transform(&s_transparent_textured_square, transparent_textured_square_transform);
    renderer_end_scene();


    //long time_elapsed_nanos = timer_end(vartime);
    //printf("Render took (nanoseconds): %ld\n", time_elapsed_nanos);
}


void user_layer_on_detach()
{
    context_free_shader(s_triangle.shader_id);
    context_free_index_buffer(&s_triangle);
    context_free_vertex_buffer(&s_triangle);
    context_free_vertex_array(&s_triangle);
}

void user_layer_on_event(event_t event)
{

}

void init_user_layer(layer_t* layer)
{
    layer->event = user_layer_on_event;
    layer->update = user_layer_on_update;
    layer->attach = user_layer_on_attach;
    layer->detach = user_layer_on_detach;
}
