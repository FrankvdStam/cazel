//
// Created by Frank on 27/07/2020.
//

#include "application.h"
#include "window.h"






void application_run(application_t* application) {
    window_t window;
    window.title = "cavel";
    window.width = 800;
    window.height = 600;
    window.platform = windows;
    window.vsync_enabled = true;
    window.handle = NULL;

    window_init(window);

    while (!window_should_close(window))
    {

    }

}