//
// Created by Frank on 27/07/2020.
//

#ifndef SANDBOX_APPLICATION_H
#define SANDBOX_APPLICATION_H

#include "core.h"
#include "layers/layer.h"
#include "window.h"



typedef struct
{
    platform_t platform;
    layer_stack_t layer_stack;
    window_t window;
} application_t;


application_t application_init();
void application_run(application_t* application);
void application_add_layer(application_t* application, layer_t layer);

#endif //SANDBOX_APPLICATION_H
