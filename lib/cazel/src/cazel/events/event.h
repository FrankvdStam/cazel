//
// Created by Frank on 27/07/2020.
//

#ifndef SANDBOX_EVENT_H
#define SANDBOX_EVENT_H

#include "../core.h"
#include "../input.h"

//Enum containing all types of events
//TODO: add controller events
typedef enum
{
    event_none,
    event_window_close,
    event_window_resize,
    event_window_minimize,
    event_window_maximize,
    //event_window_focus,
    //event_window_lost_focus,
    //event_window_moved,

    //event_app_tick,
    //event_app_update,
    //event_app_render,

    event_key_pressed,
    event_key_released,
    event_key_repeated,
    //event_key_typed,

    //event_mouse_button_pressed,
    //event_mouse_button_released,
    //event_mouse_moved,
    event_mouse_scrolled
} event_type_t;

typedef struct
{
    event_type_t type;
    bool handled;

    //for resizing
    uint32_t x;
    uint32_t y;

    //for mouse scrolling or movements
    double mouse_x;
    double mouse_y;

    //for key events
    key_t key;
} event_t;

event_t event_create_empty();

#endif //SANDBOX_EVENT_H
