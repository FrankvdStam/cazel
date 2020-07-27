#include <stdio.h>
#include "../lib/cazel/src/cazel.h"

application_t create_application()
{
    application_t application;
    application.platform = windows;
    return application;

}