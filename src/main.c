#include <stdio.h>
#include "../lib/cazel/src/cazel.h"
#include "../lib/cazel/src/cazel/renderer/renderer.h"

vertex_array_t s_vertex_array;

void user_layer_on_attach()
{
    context_create_vertex_array(&s_vertex_array);
    context_bind_vertex_array(&s_vertex_array);

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

    s_vertex_array.shader_id = context_create_shader(vertex_shader_source, fragment_shader_source);
    context_bind_shader(s_vertex_array.shader_id);


    float vertices[] = {
            -0.5f, -0.5f, 0.0f, 0.5f, 1.0f, 1.1f, 1.1f,
            0.5f, -0.5f, 0.0f, 05.f, 0.0f, 1.1f, 1.1f,
            0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 0.1f, 1.1f,
    };

    context_create_vertex_buffer(&s_vertex_array, vertices, 3, 21);

    buffer_element_t elements[] =
            {
                    buffers_create_buffer_element(shader_data_type_float3),
                    buffers_create_buffer_element(shader_data_type_float4),
            };

    buffers_create_buffer_layout(&s_vertex_array.vertex_layout, elements, 2);
    buffers_print_layout(&s_vertex_array.vertex_layout);


    context_set_vertex_buffer_layout(&s_vertex_array);

    uint32_t indices[3] = {0, 1, 2};
    context_create_index_buffer(&s_vertex_array, indices, 3);
}


void user_layer_on_update()
{
    renderer_begin_scene();
    renderer_submit(&s_vertex_array);
    renderer_end_scene();
}



void user_layer_on_detach()
{
    context_free_shader(s_vertex_array.shader_id);
    context_free_index_buffer(&s_vertex_array);
    context_free_vertex_buffer(&s_vertex_array);
    context_free_vertex_array(&s_vertex_array);
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
