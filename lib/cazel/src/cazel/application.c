//
// Created by Frank on 27/07/2020.
//

#include "application.h"
#include "nuklear/nuklear_layer.h"
#include "input.h"

application_t application_create(platform_t platform)
{
    window_t window;
    window.title = "cavel";
    window.width = 800;
    window.height = 600;
    window.vsync_enabled = true;
    window.handle = NULL;

    window_init(&window);

    application_t app;
    app.window = window;
    app.platform = platform;
    app.layer_stack = layer_stack_init(4);
    app.exiting = false;

    layer_t nuklear_layer = nuklear_layer_init(app.window);
    application_add_layer(&app, nuklear_layer);

    layer_stack_print_names(&app.layer_stack);

    return app;
}

void application_update(application_t* application)
{
    for(size_t i = 0; i < application->layer_stack.add_index; i++)
    {
        application->layer_stack.layers[i].update();
    }
}


void application_run(application_t* application)
{
    while (!application->exiting)
    {
        if(input_mouse_button_pressed(&application->window, MOUSE_BUTTON_LEFT))
        {
            printf("left button pressed\n");
        }
        application_update(application);
    }
}


void application_add_layer(application_t* application, layer_t layer)
{
    printf("Add layer name: %s\n", layer.name);
    layer_stack_add(&application->layer_stack, layer);
    layer.attach();
}