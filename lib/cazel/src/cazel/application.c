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
    s_application.last_frame_time = 0.0f;
    s_application.minimized = false;

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
    //calculate the delta time and update the last frame time
    float time = context_get_time();
    float delta_time = time - s_application.last_frame_time;
    s_application.last_frame_time = time;
    //printf("delta time: %f, last frame time: %f\n", delta_time, time);

    for(size_t i = 0; i < s_application.layer_stack.add_index; i++)
    {
        s_application.layer_stack.layers[i].update(delta_time);
    }
}

void application_on_event(event_t event)
{
    switch (event.type)
    {
        default:
            break;

        case event_window_close:
            s_application.exiting = true;
            event.handled = true;
            break;

        case event_window_minimize:
            s_application.minimized = true;
            break;

        case event_window_maximize:
            s_application.minimized = false;
            break;

        case event_window_resize:
            //printf("Window resize: (%u, %u)\n", event.x, event.y);
            context_set_viewport(event.x, event.y);
            break;

    }

    if(event.type == event_window_close)
    {
        s_application.exiting = true;
        event.handled = true;
    }

    if(event.type)

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
        application_update();
        context_swap_buffers(&s_application.window);
    }
}


void application_add_layer(layer_t layer)
{
    layer_stack_add(&s_application.layer_stack, layer);
    layer.attach();
}
