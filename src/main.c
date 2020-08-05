#include <stdio.h>
#include "../lib/cazel/src/cazel.h"
#include "../lib/cazel/src/cazel/renderer/renderer.h"

vertex_array_t s_triangle;
vertex_array_t s_square;

unsigned int init_shader()
{
    const char* vertex_shader_source = "#version 330 core\n"
                                       "\n"
                                       "layout (location = 0) in vec3 a_Position;\n"
                                       "layout (location = 1) in vec4 a_Color;\n"
                                       "\n"
                                       "out vec3 v_Position;\n"
                                       "out vec4 v_Color;\n"
                                       "\n"
                                       "void main()\n"
                                       "{\n"
                                       "    v_Position = a_Position;\n"
                                       "    v_Color = a_Color;\n"
                                       "    gl_Position = vec4(a_Position, 1.0);\n"
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

    s_square.shader_id = shader;
    context_bind_shader(s_square.shader_id);

    float square_vertices[] = {
            -0.75f, -0.75f, 1.0f,       1.0f, 1.0f, 1.1f, 1.1f,
             0.75f, -0.75f, 1.0f,       1.0f, 1.0f, 1.1f, 1.1f,
             0.75f,  0.75f, 1.0f,       1.0f, 1.0f, 1.1f, 1.1f,
            -0.75f,  0.75f, 1.0f,       1.0f, 1.0f, 1.1f, 1.1f,
    };
    context_create_vertex_buffer(&s_square, square_vertices, 4, 28);
    context_bind_vertex_buffer(&s_square);
    buffers_create_buffer_layout(&s_square.vertex_layout, elements, 2);
    context_set_vertex_buffer_layout(&s_square);

    uint32_t square_indices[6] = {0, 1, 2, 2, 0, 3};
    context_create_index_buffer(&s_triangle, square_indices, 6);
}


void user_layer_on_update()
{
    renderer_begin_scene();
    renderer_submit(&s_triangle);
    renderer_submit(&s_square);
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
