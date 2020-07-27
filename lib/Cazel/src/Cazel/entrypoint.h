//
// Created by Frank on 27/07/2020.
//
#include <stdio.h>
#include "application.h"

extern application_t* create_application();


int main()
{
    printf("Init from lib.\n");

    application_t* application = create_application();
    application_run(application);

    return 0;
}