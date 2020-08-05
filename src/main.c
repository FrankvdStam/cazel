#define CGLM_DEFINE_PRINTS

#include <stdio.h>
#include "../lib/cazel/src/cazel.h"
#include "../lib/cazel/src/cazel/renderer/renderer.h"
#include "../lib/cazel/src/cazel/renderer/orthographic_camera.h"

vertex_array_t s_triangle;
vertex_array_t s_square;
orthographic_camera_t s_camera;

float s_camera_speed = 1.0f;


const char* flat_color_vertex_shader_source =   "#version 330 core\n"
                                                "\n"
                                                "layout (location = 0) in vec3 a_Position;\n"
                                                "\n"
                                                "uniform mat4 u_ViewProjectionMatrix;"
                                                "uniform mat4 u_Transform;"
                                                "\n"
                                                "out vec3 v_Position;\n"
                                                "\n"
                                                "void main()\n"
                                                "{\n"
                                                "    v_Position = a_Position;\n"
                                                "    gl_Position = u_ViewProjectionMatrix * u_Transform * vec4(a_Position, 1.0);\n"
                                                "}\0";

const char* flat_color_fragment_shader_source = "#version 330 core\n"
                                                "\n"
                                                "layout (location = 0) out vec4 color;\n"
                                                "\n"
                                                "in vec3 v_Position;\n"
                                                "uniform vec4 u_Color;"
                                                "\n"
                                                "void main()\n"
                                                "{\n"
                                                "    color = u_Color;\n"
                                                "}\0";

unsigned int init_shader()
{
    const char* vertex_shader_source = "#version 330 core\n"
                                       "\n"
                                       "layout (location = 0) in vec3 a_Position;\n"
                                       "layout (location = 1) in vec4 a_Color;\n"
                                       "\n"
                                       "uniform mat4 u_ViewProjectionMatrix;"
                                       "uniform mat4 u_Transform;"
                                       "\n"
                                       "out vec3 v_Position;\n"
                                       "out vec4 v_Color;\n"
                                       "\n"
                                       "void main()\n"
                                       "{\n"
                                       "    v_Position = a_Position;\n"
                                       "    v_Color = a_Color;\n"
                                       "    gl_Position = u_ViewProjectionMatrix * u_Transform * vec4(a_Position, 1.0);\n"
                                       "}\0";


    const char* fragment_shader_source = "#version 330 core\n"
                                         "\n"
                                         "layout (location = 0) out vec4 color;\n"
                                         "\n"
                                         "in vec3 v_Position;\n"
                                         "in vec4 v_Color;\n"
                                         "\n"
                                         "void main()\n"
                                         "{\n"
                                         "    color = v_Color;\n"
                                         "}\0";

    return context_create_shader(vertex_shader_source, fragment_shader_source);
}


void user_layer_on_attach()
{
    unsigned int flat_color_shader = context_create_shader(flat_color_vertex_shader_source, flat_color_fragment_shader_source);
    unsigned int shader = init_shader();

    //========================================================================================================================================================================================================================


    context_create_vertex_array(&s_triangle);
    context_bind_vertex_array(&s_triangle);

    s_triangle.shader_id = shader;
    context_bind_shader(s_triangle.shader_id);

    float triangle_vertices[] = {
            -0.5f, -0.5f, 0.0f, 0.5f, 1.0f, 1.1f, 1.1f,
            0.5f, -0.5f, 0.0f, 05.f, 0.0f, 1.1f, 1.1f,
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
    //buffers_print_layout(&s_triangle.vertex_layout);


    context_set_vertex_buffer_layout(&s_triangle);

    uint32_t triangle_indices[3] = {0, 1, 2};
    context_create_index_buffer(&s_triangle, triangle_indices, 3);



    //========================================================================================================================================================================================================================

    context_create_vertex_array(&s_square);
    context_bind_vertex_array(&s_square);

    s_square.shader_id = flat_color_shader;
    context_bind_shader(s_square.shader_id);

    float square_vertices[] = {
            -0.75f, -0.75f, 1.0f,//       0.8f, 0.2f, 0.5f, 1.1f,
             0.75f, -0.75f, 1.0f,//       0.5f, 0.3f, 0.1f, 1.1f,
             0.75f,  0.75f, 1.0f,//       0.1f, 0.4f, 0.8f, 1.1f,
            -0.75f,  0.75f, 1.0f,//       0.7f, 0.8f, 0.9f, 1.1f,
    };

    context_create_vertex_buffer(&s_square, square_vertices, 4, 12);
    context_bind_vertex_buffer(&s_square);

    buffer_element_t flat_color_buffer_layout_elements[] =
    {
            buffers_create_buffer_element(shader_data_type_float3),
    };
    buffers_create_buffer_layout(&s_square.vertex_layout, flat_color_buffer_layout_elements, 1);
    context_set_vertex_buffer_layout(&s_square);

    uint32_t square_indices[6] = {0, 1, 2, 2, 0, 3};
    context_create_index_buffer(&s_square, square_indices, 6);


    //========================================================================================================================================================================================================================
    orthographic_camera_init(&s_camera, -1.6f, 1.6f, -0.9f, 0.9f);
    orthographic_camera_recalculate_view_projection_matrix(&s_camera);
}


void user_layer_on_update(float delta_time)
{
    if(input_key_pressed(&s_application.window, key_a))
    {
        s_camera.position[0] += s_camera_speed * delta_time;
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
    }
    else if(input_key_pressed(&s_application.window, key_d))
    {
        s_camera.position[0] -= s_camera_speed * delta_time;
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
    }

    if(input_key_pressed(&s_application.window, key_s))
    {
        s_camera.position[1] += s_camera_speed * delta_time;
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
    }
    else if(input_key_pressed(&s_application.window, key_w))
    {
        s_camera.position[1] -= s_camera_speed * delta_time;
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
    }










    renderer_begin_scene(&s_camera.view_projection_matrix);


    //mat4 transform = GLM_MAT4_IDENTITY_INIT;
    //vec3 asd = {1.0f, 0.5f, 0.0f};
    //glm_translate(transform, asd);
    //renderer_submit(&s_square);

//    static bool first = true;

    vec3 v = {0.1f, 0.1f, 0.1f};
    mat4 scale = GLM_MAT4_IDENTITY_INIT;
    glm_scale(scale, v);

    //for(int i = 0; i < 2; i++)
    //{
    //    vec3 position = {i * 0.18f, 0.0f, 0.0f};
    //    mat4 transform = GLM_MAT4_IDENTITY_INIT;

    //    glm_translate(transform, position);
    //    glm_mat4_mul(transform, scale, transform);

    //    if(first)
    //    {
    //        glm_mat4_print(transform, stdout);
    //    }

    //    renderer_submit_with_transform(&s_square, transform);
    //}

    //first = false;

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
                context_upload_uniform_vec4(s_square.shader_id, "u_Color", blue);
            }
            else
            {
                context_upload_uniform_vec4(s_square.shader_id, "u_Color", red);
            }

            renderer_submit_with_transform(&s_square, transform);
        }
    }

    renderer_submit(&s_triangle);

    renderer_end_scene();
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
