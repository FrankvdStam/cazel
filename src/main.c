#include <stdio.h>
#include "../lib/cazel/src/cazel.h"

application_t* create_application()
{
    application_t* application = (application_t*)(sizeof(application_t));
    return application;

}