//
// Created by Frank on 27/07/2020.
//
#include <stdio.h>
#include "application.h"
#include "window.h"
#include "input.h"
#include "context.h"

extern application_t application_create();


//Resolves platform specific api's
void initialize_platform(platform_t platform)
{
    window_platform_init(platform);
    input_platform_init(platform);
    context_platform_init(platform);
}


int main()
{
    initialize_platform(platform_windows);
    application_t application = application_create();
    application_run(&application);
    return 0;
}
