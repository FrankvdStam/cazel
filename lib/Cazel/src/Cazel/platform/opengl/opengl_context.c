//
// Created by Frank on 28/07/2020.
//

#include "opengl_context.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "../../../lib/glad/include/glad/glad.h"

GLuint s_vertex_array;
GLuint s_vertex_buffer;
GLuint s_index_buffer;
GLuint s_shader_program;

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


    glUseProgram(s_shader_program);

    float vertices[3*3] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f,
    };

    glGenVertexArrays(1, &s_vertex_array);
    glBindVertexArray(s_vertex_array);

    s_vertex_array = context_create_vertex_buffer(vertices, 3*3);



    //glGenBuffers(1, &s_vertex_buffer);
    //glBindBuffer(GL_ARRAY_BUFFER, s_vertex_buffer);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);


    uint32_t indices[3] = {0, 1, 2};
    s_index_buffer = context_create_index_buffer(indices, 3);

    //glGenBuffers(1, &s_index_buffer);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_index_buffer);
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);



    const char* vertex_shader_source = "#version 330 core\n"
                                       "layout (location = 0) in vec3 aPos;\n"
                                       "\n"
                                       "void main()\n"
                                       "{\n"
                                       "    gl_Position = vec4(aPos, 1.0);\n"
                                       "}\0";


    const char* fragment_shader_source = "#version 330 core\n"
                                         "layout (location = 0) out vec4 color;\n"
                                         "void main()\n"
                                         "{\n"
                                         "    color = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
                                         "}\0";

    s_shader_program = opengl_create_shader(vertex_shader_source, fragment_shader_source);

}

void opengl_context_swap_buffers(window_t* window)
{
    glBindVertexArray(s_vertex_array);
    glUseProgram(s_shader_program);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);

    glfwSwapBuffers(window->handle);
}




GLuint opengl_create_shader(const char* vertex_shader_source, const char* fragment_shader_source)
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

    GLuint shader = glCreateProgram();
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

vertex_buffer_t opengl_context_create_vertex_buffer(float* vertices, size_t count)
{
    vertex_buffer_t vertex_buffer;
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count, vertices, GL_STATIC_DRAW);
    return vertex_buffer;
}


index_buffer_t opengl_context_create_index_buffer(uint32_t* indices, size_t count)
{
    index_buffer_t index_buffer;
    glGenBuffers(1, &index_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * count, indices, GL_STATIC_DRAW);
    return index_buffer;
}

void opengl_context_bind_vertex_buffer(vertex_buffer_t vertex_buffer)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
}

void opengl_context_bind_index_buffer(index_buffer_t index_buffer)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);
}

void opengl_context_free_vertex_buffer(vertex_buffer_t vertex_buffer)
{
    glDeleteBuffers(GL_ARRAY_BUFFER, &vertex_buffer);
}
void opengl_context_free_index_buffer(index_buffer_t index_buffer)
{
    glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &index_buffer);
}

