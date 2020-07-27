//
// Created by Frank on 05/07/2020.
//

#include "shapes.h"

unsigned int static_rectangle_indices[] = {
        0, 1, 3,
        1, 2, 3
};


drawable_t* shape_create_basic(shape_type_t type)
{
    drawable_t* triangle = (drawable_t*)malloc(sizeof(drawable_t));
    triangle->enabled = true;
    triangle->shape_type = type;
    triangle->color.r = 1.0f;
    triangle->color.g = 1.0f;
    triangle->color.b = 1.0f;
    triangle->color.a = 1.0f;

    glGenVertexArrays(1, &triangle->vertex_buffer_object);
    glBindVertexArray(triangle->vertex_buffer_object);

    glGenBuffers(1, &triangle->vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, triangle->vertex_buffer);

    return triangle;
}


drawable_t* shape_create_triangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3)
{
    drawable_t* triangle = shape_create_basic(shape_type_triangle);

    triangle->vertices = (GLfloat*)malloc(sizeof(GLfloat) * 18);
    triangle->vertices[0 ] = x1;
    triangle->vertices[1 ] = y1;
    triangle->vertices[2 ] = 0.0f;
    triangle->vertices[3 ] = x2;
    triangle->vertices[4 ] = y2;
    triangle->vertices[5 ] = 0.0f;
    triangle->vertices[6 ] = x3;
    triangle->vertices[7 ] = y3;
    triangle->vertices[8 ] = 0.0f;

    triangle->vertices[9 ] = 1.0f;
    triangle->vertices[10] = 1.0f;
    triangle->vertices[11] = 1.0f;
    triangle->vertices[12] = 1.0f;
    triangle->vertices[13] = 1.0f;
    triangle->vertices[14] = 1.0f;
    triangle->vertices[15] = 1.0f;
    triangle->vertices[16] = 1.0f;
    triangle->vertices[17] = 1.0f;



    triangle->shader = get_shader(SHADER_COLOR);
    glUseProgram(triangle->shader);


    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 9, triangle->vertices, GL_STATIC_DRAW);

    //Tell the graphics card how to interpret the vertices
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
    );
    return triangle;
}

drawable_t* shape_create_rectangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4)
{

    drawable_t* rectangle = shape_create_basic(shape_type_rectangle);

    rectangle->vertices = (GLfloat*)malloc(sizeof(GLfloat) * 12);
    rectangle->vertices[0] = x1;
    rectangle->vertices[1] = y1;
    rectangle->vertices[2] = 0.0f;
    rectangle->vertices[3] = x2;
    rectangle->vertices[4] = y2;
    rectangle->vertices[5] = 0.0f;
    rectangle->vertices[6] = x3;
    rectangle->vertices[7] = y3;
    rectangle->vertices[8] = 0.0f;
    rectangle->vertices[9] = x4;
    rectangle->vertices[10] = y4;
    rectangle->vertices[11] = 0.0f;

    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 12, rectangle->vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &rectangle->element_buffer_object);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rectangle->element_buffer_object);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, static_rectangle_indices, GL_STATIC_DRAW);

    //Tell the graphics card how to interpret the vertices
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            sizeof(GLfloat) * 3,// stride
            (void*)0            // array buffer offset
    );

    return rectangle;
}



void shape_free(drawable_t* drawable)
{
    //opengl memory for every drawable:
    glDeleteVertexArrays(1, &drawable->vertex_buffer_object);
    glDeleteBuffers(1, &drawable->vertex_buffer);

    //opengl memory for specific shapes
    switch(drawable->shape_type)
    {
        case shape_type_rectangle:
            glDeleteBuffers(1, &drawable->element_buffer_object);
            break;
        default:
            break;
    }

    //C memory
    free(drawable->vertices);
    free(drawable);
}
