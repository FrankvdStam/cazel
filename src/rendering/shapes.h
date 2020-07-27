//
// Created by Frank on 05/07/2020.
//

#ifndef COPENGL_SHAPES_H
#define COPENGL_SHAPES_H

#include "../common.h"
#include "shader.h"

typedef enum
{
    shape_type_line,
    shape_type_rectangle,
    shape_type_triangle,
} shape_type_t;

typedef struct
{
    float r;
    float g;
    float b;
    float a;
} color_t;

//Contains information about a basic shape that can be rendered
typedef struct
{
    //Contains the vertexes
    GLfloat* vertices;
    //This tells the renderer how to draw this shape
    shape_type_t shape_type;
    //Buffer id to bind
    GLuint vertex_buffer;
    GLuint vertex_buffer_object;
    GLuint element_buffer_object;

    bool enabled;
    color_t color;

    GLuint shader;
} drawable_t;


drawable_t* shape_create_triangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3);
drawable_t* shape_create_rectangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4);
void shape_free(drawable_t* drawable);



#endif //COPENGL_SHAPES_H