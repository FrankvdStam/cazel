//
// Created by Frank on 27/07/2020.
//

#ifndef SANDBOX_LAYER_H
#define SANDBOX_LAYER_H

#include "../core.h"
#include "../events/event.h"

//layer functions:
typedef void(*on_event)(event_t event);
typedef void(*on_attach)();
typedef void(*on_detach)();
typedef void(*on_update)(float delta_time);

typedef struct
{
    char* name;
    on_event  event;
    on_attach attach;
    on_detach detach;
    on_update update;
} layer_t;

void layer_init(layer_t* layer, char* name);
void layer_free(layer_t* layer);




typedef struct
{
    layer_t* layers;
    size_t size;
    size_t add_index;
} layer_stack_t;

void layer_stack_init(layer_stack_t* stack, size_t size);
void layer_stack_free(layer_stack_t* stack);
void layer_stack_add(layer_stack_t* stack, const layer_t layer);
void layer_stack_print_names(layer_stack_t* stack);





#endif //SANDBOX_LAYER_H
