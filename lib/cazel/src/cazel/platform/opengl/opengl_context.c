//
// Created by Frank on 28/07/2020.
//

#include "opengl_context.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "../../../../lib/glad/include/glad/glad.h"

vertex_array_t  s_vertex_array;
vertex_buffer_t s_vertex_buffer;
index_buffer_t  s_index_buffer;
shader_t        s_shader_program;


GLenum shader_data_type_to_gl_enum(shader_data_type_t type)
{
    switch(type)
    {
        default: EXIT_ERROR("Unknown shader data type.\n");

        case shader_data_type_float  :
        case shader_data_type_float2 :
        case shader_data_type_float3 :
        case shader_data_type_float4 :
        case shader_data_type_mat3   :
        case shader_data_type_mat4   : return GL_FLOAT;

        case shader_data_type_int    :
        case shader_data_type_int2   :
        case shader_data_type_int3   :
        case shader_data_type_int4   : return GL_INT;

        case shader_data_type_bool   : return GL_BOOL;
    }
}

void glDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    if(severity == GL_DEBUG_SEVERITY_NOTIFICATION)
    {
        return;
    }
    printf("%s\n", message);
}

void opengl_context_init(window_t* window)
{
    glfwMakeContextCurrent(window->handle);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        EXIT_ERROR("Failed to initialize glad\n");
    }
    glEnable(GL_DEBUG_OUTPUT);
    GLDEBUGPROC proc = glDebugCallback;
    glDebugMessageCallback(proc, NULL);

    s_vertex_array = context_create_vertex_array();
    context_bind_vertex_array(s_vertex_array);
    //glGenVertexArrays(1, &s_vertex_array);
    //glBindVertexArray(s_vertex_array);

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

    s_shader_program = context_create_shader(vertex_shader_source, fragment_shader_source);

    context_bind_shader(s_shader_program);
    //glUseProgram(s_shader_program);


    float vertices[] = {
            -0.5f, -0.5f, 0.0f, 0.5f, 1.0f, 1.1f, 1.1f,
             0.5f, -0.5f, 0.0f, 05.f, 0.0f, 1.1f, 1.1f,
             0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 0.1f, 1.1f,
    };
    s_vertex_array = context_create_vertex_buffer(vertices, 21);


    buffer_element_t elements[] =
    {
            buffers_create_buffer_element(shader_data_type_float3),
            buffers_create_buffer_element(shader_data_type_float4),
    };

    buffer_layout_t layout;
    buffers_create_buffer_layout(&layout, elements, 2);
    buffers_print_layout(&layout);

    context_set_vertex_buffer_layout(s_vertex_buffer, &layout);

    uint32_t indices[3] = {0, 1, 2};
    s_index_buffer = context_create_index_buffer(indices, 3);
}

void opengl_context_swap_buffers(window_t* window)
{
    glBindVertexArray(s_vertex_array);
    glUseProgram(s_shader_program);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);

    glfwSwapBuffers(window->handle);
}

//========================================================================================================================================================================================================================
//Vertex buffers

vertex_buffer_t opengl_context_create_vertex_buffer(float* vertices, size_t count)
{
    vertex_buffer_t vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, vertices, GL_STATIC_DRAW);
    return vertex_buffer;
}

void opengl_context_bind_vertex_buffer(vertex_buffer_t vertex_buffer)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
}

void opengl_context_free_vertex_buffer(vertex_buffer_t vertex_buffer)
{
    glDeleteBuffers(GL_ARRAY_BUFFER, &vertex_buffer);
}

void opengl_context_set_vertex_buffer_layout(vertex_buffer_t vertex_buffer, buffer_layout_t* buffer_layout)
{
    for(unsigned int i = 0; i < buffer_layout->size; i++)
    {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(
                i,
                shader_data_type_component_count(buffer_layout->elements[i].data_type),
                shader_data_type_to_gl_enum(buffer_layout->elements[i].data_type),
                buffer_layout->elements[i].normalized ? GL_TRUE : GL_FALSE,
                buffer_layout->stride,
                (const void*)buffer_layout->elements[i].offset);
    }
}


//========================================================================================================================================================================================================================
//index buffers
index_buffer_t opengl_context_create_index_buffer(uint32_t* indices, size_t count)
{
    index_buffer_t index_buffer;
    glGenBuffers(1, &index_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * count, indices, GL_STATIC_DRAW);
    return index_buffer;
}

void opengl_context_bind_index_buffer(index_buffer_t index_buffer)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
}

void opengl_context_free_index_buffer(index_buffer_t index_buffer)
{
    glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &index_buffer);
}

//========================================================================================================================================================================================================================
//Vertex array
vertex_array_t opengl_context_create_vertex_array()
{
    vertex_array_t vertex_array;
    glGenVertexArrays(1, &vertex_array);
    return vertex_array;
}

void opengl_context_bind_vertex_array(vertex_array_t vertex_array)
{
    glBindVertexArray(vertex_array);
}

void opengl_context_free_vertex_array(vertex_array_t vertex_array)
{
    glDeleteVertexArrays(1, &vertex_array);
}


//========================================================================================================================================================================================================================
//Shaders

shader_t opengl_context_create_shader(const char* vertex_shader_source, const char* fragment_shader_source)
{
    int  success;
    char buffer[512];

    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, buffer);
        printf("Vertex shader failed to compile: %s\n", buffer);
    }

    unsigned int fragment_shader;
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, buffer);
        printf("Fragment shader failed to compile: %s\n", buffer);
    }

    shader_t shader = glCreateProgram();
    glAttachShader(shader, vertex_shader);
    glAttachShader(shader, fragment_shader);
    glLinkProgram(shader);

    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shader, 512, NULL, buffer);
        printf("Shader linking failed: %s", buffer);
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return shader;
}


void opengl_context_bind_shader(shader_t shader)
{
    glUseProgram(shader);
}

void opengl_context_free_shader(shader_t shader)
{
    glDeleteProgram(shader);
}
