//
// Created by Frank on 05/08/2020.
//

#ifndef SANDBOX_RENDERER_H
#define SANDBOX_RENDERER_H

#include "../context.h"

void renderer_begin_scene();

void renderer_submit(vertex_array_t* vertex_array);

void renderer_end_scene();

#endif //SANDBOX_RENDERER_H
