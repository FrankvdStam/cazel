//
// Created by Frank on 27/07/2020.
//

#include "application.h"
#include "window.h"
#include <stdio.h>

void application_run(application_t* application) {
    window_t window;
    window.title = "cavel";
    window.width = 800;
    window.height = 600;
    window.vsync_enabled = true;
    window.handle = NULL;


    if(window_init == NULL)
    {
        printf("wininitnull");
    }

    window_init(window);

    while (true)
    {

    }
}
