//
// Created by Frank on 06/07/2020.
//

#ifndef COPENGL_DRAWABLE_BUFFER_H
#define COPENGL_DRAWABLE_BUFFER_H

#include "../common.h"
#include "shapes.h"


//Buffer containing a number of drawables that the renderer can render
typedef struct
{
    drawable_t** drawables;
    size_t size;
    size_t index;
} drawable_buffer_t;

drawable_buffer_t* drawable_buffer_create(size_t size);
void drawable_buffer_free(drawable_buffer_t* drawable_buffer);
void drawable_buffer_add(drawable_buffer_t* drawable_buffer, drawable_t* drawable);


#endif //COPENGL_DRAWABLE_BUFFER_H
