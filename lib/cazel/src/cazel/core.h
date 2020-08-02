//
// Created by Frank on 27/07/2020.
//

#ifndef SANDBOX_CORE_H
#define SANDBOX_CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef enum
{
    platform_windows,
    platform_linux,
} platform_t;


#define EXIT_ERROR(...) fprintf(stderr, __VA_ARGS__); exit(1)


#endif //SANDBOX_CORE_H
