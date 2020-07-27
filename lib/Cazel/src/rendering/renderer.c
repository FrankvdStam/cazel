//
// Created by Frank on 03/05/2020.
//
#include "../common.h"
#include "renderer.h"
#include "shapes.h"
#include "drawable_buffer.h"

GLFWwindow* window_ptr;

GLFWwindow* renderer_get_window()
{
    return window_ptr;
}


void glDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    printf("%s\n", message);
};



void renderer_init()
{
    if(!glfwInit())
    {
        fprintf(stderr, "Failed to initialize glfw\n");
    }

    window_ptr = glfwCreateWindow(800, 600, "Driehoek", NULL, NULL);
    glfwMakeContextCurrent(window_ptr);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr, "Failed to initialize glad\n");
    }
    glEnable(GL_DEBUG_OUTPUT);
    GLDEBUGPROC proc = glDebugCallback;
    glDebugMessageCallback(proc, NULL);

    init_shaders();
}







//========================================================================================
//Rendering functions

void draw_triangle(drawable_t* triangle)
{
    glBindVertexArray(triangle->vertex_buffer_object);
    glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
};

void draw_rectangle(drawable_t* rectangle)
{
    glBindVertexArray(rectangle->vertex_buffer_object);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void renderer_render_drawable_buffer(drawable_buffer_t* buffer)
{
    int vertex_color_location = glGetUniformLocation(get_shader(SHADER_COLOR), "fill_color");
    for(size_t i = 0; i < buffer->index; i++)
    {
        drawable_t* drawable = buffer->drawables[i];
        //glUniform4f(vertex_color_location, drawable->color.r, drawable->color.g, drawable->color.b, drawable->color.a);
        //glUseProgram(drawable->shader);
        //printf("Drawing object with shader: %i\n", drawable->shader);
        switch(buffer->drawables[i]->shape_type)
        {
            case shape_type_triangle:
                draw_triangle(buffer->drawables[i]);
                break;
            case shape_type_rectangle:
                draw_rectangle(buffer->drawables[i]);
            default:
                break;
        }
    }
}














void renderer_poll_events()
{
    if(!glfwWindowShouldClose(window_ptr))
    {
        glfwPollEvents();
    } else{
        glfwDestroyWindow(window_ptr);
        exit(0);
    }
}



void renderer_draw_triangle()
{
    //Create some shapes
    drawable_t* triangle1 = shape_create_triangle(0.0f,0.0f,-0.5f,1.0f,-1.0f,0.0f);
    drawable_t* triangle2 = shape_create_triangle(1.0f,0.0f, 0.5f,1.0f, 0.0f,0.0f);

    drawable_t* rectangle1 = shape_create_rectangle(-0.5f, 0.5f,
                                                     0.5f, 0.5f,
                                                     0.5f, -0.5f,
                                                     -0.5f, -0.5f);

    triangle1->color.r = 0.0f;
    triangle1->color.g = 1.0f;
    triangle1->color.b = 0.0f;

    triangle2->color.r = 0.0f;
    triangle2->color.g = 0.0f;
    triangle2->color.b = 1.0f;

    rectangle1->color.b = 0.0f;
    rectangle1->color.g = 0.0f;

    //Add them to a buffer
    drawable_buffer_t* drawables = drawable_buffer_create(10);

    drawable_buffer_add(drawables, triangle1);
    drawable_buffer_add(drawables, triangle2);
    drawable_buffer_add(drawables, rectangle1);

    //Draw them
    renderer_render_drawable_buffer(drawables);

    //Free everything up
    drawable_buffer_free(drawables);

    glfwSwapBuffers(window_ptr);

    printf("%i", glGetError());
}




