//
// Created by Frank on 27/07/2020.
//

#ifndef SANDBOX_APPLICATION_H
#define SANDBOX_APPLICATION_H

#include "core.h"
#include "layers/layer.h"
#include "window.h"

typedef void(*event_callback)(event_t event);

typedef struct
{
    platform_t platform;
    layer_stack_t layer_stack;
    window_t window;

    bool exiting;

    float last_frame_time;
} application_t;

extern application_t s_application;

extern void init_user_layer(layer_t* layer);

void application_create(platform_t platform);
void application_run();
void application_add_layer(layer_t layer);
void application_on_event();

#endif //SANDBOX_APPLICATION_H
