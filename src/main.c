#include <stdio.h>
#include "../lib/cazel/src/cazel.h"


void user_layer_on_attach()
{

}


void user_layer_on_update()
{

}



void user_layer_on_detach()
{

}

void user_layer_on_event(event_t event)
{

}





void init_user_layer(layer_t* layer)
{
    layer->event = user_layer_on_event;
    layer->update = user_layer_on_update;
    layer->attach = user_layer_on_attach;
    layer->detach = user_layer_on_detach;
}
