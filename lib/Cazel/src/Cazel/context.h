//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_CONTEXT_H
#define SANDBOX_CONTEXT_H

#include "core.h"
#include "window.h"

void context_platform_init(platform_t platform);

void(*context_init)(window_t*window);
void(*context_swap_buffers)(window_t* window);


#endif //SANDBOX_CONTEXT_H
