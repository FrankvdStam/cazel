//
// Created by Frank on 27/07/2020.
//

#ifndef SANDBOX_APPLICATION_H
#define SANDBOX_APPLICATION_H

typedef enum
{
    windows,
    linux,
} platform_t;

typedef struct
{
    platform_t platform;
} application_t;

void application_run(application_t* application);


#endif //SANDBOX_APPLICATION_H
