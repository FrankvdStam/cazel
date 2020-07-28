//
// Created by Frank on 28/07/2020.
//

#include "opengl_context.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "../../../lib/glad/include/glad/glad.h"

GLuint vertex_array;
GLuint vertex_buffer;
GLuint index_buffer;

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

    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);

    float vertices[3*3] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f,
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);

    glGenBuffers(1, &index_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer);

    uint32_t indices[3] = {0, 1, 2};

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void opengl_context_swap_buffers(window_t* window)
{
    glBindVertexArray(vertex_array);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, NULL);
    glfwSwapBuffers(window->handle);
}
