#define CGLM_DEFINE_PRINTS

#include <stdio.h>




#include "../lib/cazel/src/cazel.h"
#include "../lib/cazel/src/cazel/renderer/renderer.h"
#include "../lib/cazel/src/cazel/renderer/orthographic_camera.h"

#include "../lib/cazel/src/cazel/platform/opengl/opengl_context.h"

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
void print_dir()
{
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    } else {
        perror("getcwd() error");
    }
}





vertex_array_t s_triangle;
vertex_array_t s_square;
vertex_array_t s_textured_square;
orthographic_camera_t s_camera;

float s_camera_speed = 1.0f;

const char* texture_vertex_shader_source =      "#version 330 core\n"
                                                "\n"
                                                "layout (location = 0) in vec3 a_Position;\n"
                                                "layout (location = 1) in vec2 a_TextureCoordinate;\n"
                                                "\n"
                                                "uniform mat4 u_ViewProjectionMatrix;"
                                                "uniform mat4 u_Transform;"
                                                "\n"
                                                "out vec2 v_TextureCoordinate;"
                                                "\n"
                                                "void main()\n"
                                                "{\n"
                                                "    v_TextureCoordinate = a_TextureCoordinate;\n"
                                                "    gl_Position = u_ViewProjectionMatrix * u_Transform * vec4(a_Position, 1.0);\n"
                                                "}\0";

const char* texture_fragment_shader_source =    "#version 330 core\n"
                                                "\n"
                                                "layout (location = 0) out vec4 color;\n"
                                                "\n"
                                                "in vec2 v_TextureCoordinate;\n"
                                                "uniform sampler2D u_Texture;\n"
                                                "\n"
                                                "void main()\n"
                                                "{\n"
                                                "    color = texture(u_Texture, v_TextureCoordinate);\n"
                                                "}\0";



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


const char* color_vertex_shader_source = "#version 330 core\n"
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


const char* color_fragment_shader_source = "#version 330 core\n"
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


//========================================================================================================================================================================================================================
//triangle

void setup_triangle()
{
    context_create_vertex_array(&s_triangle);
    context_bind_vertex_array(&s_triangle);

    s_triangle.shader_id = context_create_shader(color_vertex_shader_source, color_fragment_shader_source);
    context_bind_shader(s_triangle.shader_id);

    opengl_context_upload_uniform_int(s_triangle.shader_id, "u_Texture", 0);


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

    s_square.shader_id = context_create_shader(flat_color_vertex_shader_source, flat_color_fragment_shader_source);
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
    print_dir();

    texture_id = context_load_texture("assets/textures/wallpaper.jpg");
    opengl_context_bind_texture(0, texture_id);
    printf("tex: %u\n", texture_id);

    context_create_vertex_array(&s_textured_square);
    context_bind_vertex_array(&s_textured_square);

    s_textured_square.shader_id = context_create_shader(texture_vertex_shader_source, texture_fragment_shader_source);
    context_bind_shader(s_textured_square.shader_id);

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



void user_layer_on_attach()
{
    setup_triangle();
    setup_squares();
    setup_textured_square();






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


    //========================================================================================================================================================================================================================
    //rendering

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
