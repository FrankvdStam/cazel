//
// Created by Frank on 27/07/2020.
//

#ifndef SANDBOX_LAYER_H
#define SANDBOX_LAYER_H

#include "../core.h"
#include "../events/event.h"

//layer functions:
typedef void(*layer_dispatch_event)(event_t event);
typedef void(*on_attach)();
typedef void(*on_detach)();
typedef void(*on_update)();

typedef struct
{
    char* name;
    layer_dispatch_event dispatch_event;
    on_attach attach;
    on_detach detach;
    on_update update;
} layer_t;

layer_t layer_init(char* name);
void layer_free(layer_t layer);




typedef struct
{
    layer_t* layers;
    size_t size;
    size_t add_index;
} layer_stack_t;

layer_stack_t layer_stack_init(size_t size);
void layer_stack_free(layer_stack_t stack);
void layer_stack_add(layer_stack_t stack, layer_t layer);






#endif //SANDBOX_LAYER_H
