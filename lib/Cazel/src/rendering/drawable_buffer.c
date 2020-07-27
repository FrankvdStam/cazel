//
// Created by Frank on 06/07/2020.
//

#include "drawable_buffer.h"


drawable_buffer_t* drawable_buffer_create(size_t size)
{
    drawable_buffer_t* drawable_buffer = (drawable_buffer_t*)malloc(sizeof(drawable_buffer_t));
    drawable_buffer->drawables = (drawable_t**)malloc(size * sizeof(drawable_t*));
    drawable_buffer->size = size;
    drawable_buffer->index = 0;
    return drawable_buffer;
}

void drawable_buffer_free(drawable_buffer_t* drawable_buffer)
{
    for(size_t i = 0; i < drawable_buffer->index; i++)
    {
        shape_free(drawable_buffer->drawables[i]);
    }

    free(drawable_buffer->drawables);
    free(drawable_buffer);
}

void drawable_buffer_add(drawable_buffer_t* drawable_buffer, drawable_t* drawable)
{
    drawable_buffer->drawables[drawable_buffer->index] = drawable;
    drawable_buffer->index++;
}
