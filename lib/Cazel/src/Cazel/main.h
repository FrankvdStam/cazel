//
// Created by Frank on 27/07/2020.
//
#include <stdio.h>
#include "application.h"
#include "window.h"

extern application_t create_application();

//Resolves platform specific api's
void initialize_platform(platform_t platform)
{
    window_platform_init(platform);
}


int main()
{
    application_t application = create_application();
    initialize_platform(application.platform);
    application_run(&application);
    return 0;
}
