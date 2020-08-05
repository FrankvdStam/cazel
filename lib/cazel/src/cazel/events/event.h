//
// Created by Frank on 27/07/2020.
//

#ifndef SANDBOX_EVENT_H
#define SANDBOX_EVENT_H

#include "../core.h"

//Enum containing all types of events
//TODO: add controller events
typedef enum
{
    event_none,
    event_window_close,
    event_window_resize,
    event_window_focus,
    event_window_lost_focus,
    event_window_moved,

    //event_app_tick,
    //event_app_update,
    //event_app_render,

    //event_key_pressed,
    //event_key_released,
    //event_key_typed,

    //event_mouse_button_pressed,
    //event_mouse_button_released,
    //event_mouse_moved,
    //event_mouse_scolled
} event_type_t;

typedef struct
{
    event_type_t type;
    uint32_t x;
    uint32_t y;
    bool handled;
} event_t;

event_t event_create_empty();

#endif //SANDBOX_EVENT_H
