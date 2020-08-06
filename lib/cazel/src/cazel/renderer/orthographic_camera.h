//
// Created by Frank on 05/08/2020.
//

#ifndef SANDBOX_ORTHOGRAPHIC_CAMERA_H
#define SANDBOX_ORTHOGRAPHIC_CAMERA_H

#include <cglm/cglm.h>


typedef struct
{
    mat4 projection_matrix;
    mat4 view_matrix;
    mat4 view_projection_matrix;

    vec3 position;
    float rotation;
}orthographic_camera_t;

void orthographic_camera_init(orthographic_camera_t* camera, float left, float right, float bottom, float top);
void orthographic_camera_recalculate_view_projection_matrix(orthographic_camera_t* camera);


#endif //SANDBOX_ORTHOGRAPHIC_CAMERA_H
