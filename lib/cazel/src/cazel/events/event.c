//
// Created by Frank on 27/07/2020.
//

#include "event.h"

event_t event_create_empty()
{
    event_t event;
    event.type = event_none;
    event.handled = false;

    event.x = 0;
    event.y = 0;

    event.key = key_none;

    return event;
}
