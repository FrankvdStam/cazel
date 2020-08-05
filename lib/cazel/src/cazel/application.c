//
// Created by Frank on 27/07/2020.
//

#include "application.h"
#include "nuklear/nuklear_layer.h"
#include "input.h"
#include "context.h"

application_t s_application;

void application_create(platform_t platform)
{
    window_t window;
    window.title = "cavel";
    window.width = 1280;
    window.height = 720;
    window.vsync_enabled = true;
    window.handle = NULL;

    window_init(&window);

    s_application.window = window;
    s_application.platform = platform;
    layer_stack_init(&s_application.layer_stack, 4);
    s_application.exiting = false;

    layer_t user_layer;
    layer_init(&user_layer, "user layer");
    init_user_layer(&user_layer);
    application_add_layer(user_layer);

    layer_t nuklear_layer;
    nuklear_layer_init(&nuklear_layer, s_application.window);
    application_add_layer(nuklear_layer);


}

void application_update()
{
    for(size_t i = 0; i < s_application.layer_stack.add_index; i++)
    {
        s_application.layer_stack.layers[i].update();
    }
}

void application_on_event(event_t event)
{
    if(event.type == event_window_close)
    {
        s_application.exiting = true;
        event.handled = true;
    }

    for(size_t i = 0; i < s_application.layer_stack.add_index; i++)
    {
        s_application.layer_stack.layers[i].event(event);
    }
}


void application_run()
{
    while (!s_application.exiting)
    {
        context_clear();

        if(input_mouse_button_pressed(&s_application.window, mouse_button_left))
        {
            printf("left button pressed\n");
        }
        application_update();

        context_swap_buffers(&s_application.window);
    }
}


void application_add_layer(layer_t layer)
{
    layer_stack_add(&s_application.layer_stack, layer);
    layer.attach();
}
