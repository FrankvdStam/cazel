//
// Created by Frank on 28/07/2020.
//

#include "opengl_context.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "../../../../lib/glad/include/glad/glad.h"
#include "../../application.h"

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

void glfwCloseWindowEventCallback(GLFWwindow* window)
{
    event_t event = event_create_empty();
    event.type = event_window_close;
    application_on_event(event);
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
    glfwSetWindowCloseCallback(window->handle, glfwCloseWindowEventCallback);
}

void opengl_context_swap_buffers(window_t* window)
{
    glfwSwapBuffers(window->handle);
}

//========================================================================================================================================================================================================================
//Vertex array
void opengl_context_create_vertex_array(vertex_array_t* vertex_array)
{
    vertex_array->vertex_buffer_id = 0;
    vertex_array->vertex_count = 0;
    vertex_array->index_buffer_id = 0;
    vertex_array->index_count = 0;
    vertex_array->shader_id = 0;
    glGenVertexArrays(1, &vertex_array->vertex_array_id);
}

void opengl_context_bind_vertex_array(vertex_array_t* vertex_array)
{
    glBindVertexArray(vertex_array->vertex_array_id);
}

void opengl_context_free_vertex_array(vertex_array_t* vertex_array)
{
    glDeleteVertexArrays(1, &vertex_array->vertex_array_id);
}

//========================================================================================================================================================================================================================
//Vertex buffers

void opengl_context_create_vertex_buffer(vertex_array_t* vertex_array, float* vertices, size_t count, size_t total_floats)
{
    vertex_array->vertex_total_floats = total_floats;
    vertex_array->vertex_count = count;
    glGenBuffers(1, &vertex_array->vertex_buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_array->vertex_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * total_floats, vertices, GL_STATIC_DRAW);
}

void opengl_context_bind_vertex_buffer(vertex_array_t* vertex_array)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertex_array->vertex_buffer_id);
}

void opengl_context_free_vertex_buffer(vertex_array_t* vertex_array)
{
    glDeleteBuffers(GL_ARRAY_BUFFER, &vertex_array->vertex_buffer_id);
}

void opengl_context_set_vertex_buffer_layout(vertex_array_t* vertex_array)
{
    for(unsigned int i = 0; i < vertex_array->vertex_layout.size; i++)
    {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(
                i,
                shader_data_type_component_count(vertex_array->vertex_layout.elements[i].data_type),
                shader_data_type_to_gl_enum(vertex_array->vertex_layout.elements[i].data_type),
                vertex_array->vertex_layout.elements[i].normalized ? GL_TRUE : GL_FALSE,
                vertex_array->vertex_layout.stride,
                (const void*)vertex_array->vertex_layout.elements[i].offset);
    }
}


//========================================================================================================================================================================================================================
//index buffers
void opengl_context_create_index_buffer(vertex_array_t* vertex_array, uint32_t* indices, size_t count)
{
    vertex_array->index_count = count;
    glGenBuffers(1, &vertex_array->index_buffer_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertex_array->index_buffer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * count, indices, GL_STATIC_DRAW);
}

void opengl_context_bind_index_buffer(vertex_array_t* vertex_array)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertex_array->index_buffer_id);
}

void opengl_context_free_index_buffer(vertex_array_t* vertex_array)
{
    glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &vertex_array->index_buffer_id);
}


//========================================================================================================================================================================================================================
//Shaders

unsigned int opengl_context_create_shader(const char* vertex_shader_source, const char* fragment_shader_source)
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

    unsigned int shader = glCreateProgram();
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


void opengl_context_bind_shader(unsigned int shader)
{
    glUseProgram(shader);
}

void opengl_context_free_shader(unsigned int shader)
{
    glDeleteProgram(shader);
}



//========================================================================================================================================================================================================================
//Clear color

//Set the color the screen should clear to
void opengl_context_set_clear_color(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

//Clear the screen to the clear color set by context_set_clear_color
void opengl_context_clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


//========================================================================================================================================================================================================================
//Uniforms

void opengl_context_upload_uniform_mat4(unsigned int shader, const char* name, mat4 matrix)
{
    int uniform_location = glGetUniformLocation(shader, name);
    if(uniform_location == -1)
    {
        EXIT_ERROR("Invalid uniform: %s\n", name);
    }
    glUniformMatrix4fv(uniform_location, 1, GL_FALSE, matrix[0]);
}
