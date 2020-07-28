//
// Created by Frank on 28/07/2020.
//

#include "context.h"
#include "core.h"
#include "platform/opengl/opengl_context.h"

void(*context_init)(window_t* window);
void(*context_swap_buffers)(window_t* window);


void context_platform_init(platform_t platform)
{
#ifdef WINDOWS
    context_init = &opengl_context_init;
    context_swap_buffers = &opengl_context_swap_buffers;
#else
    EXIT_ERROR("Linux not supported");
#endif
}




