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
}orthographic_camera_t;

void orthographic_camera_init(orthographic_camera_t* camera, float left, float right, float bottom, float top)
{
    glm_vec3_zero(camera->position);

    //glm_mat4_zero(camera->projection_matrix);
    glm_ortho(left, right, bottom, top, -1.0f, 1.0f, camera->projection_matrix);
    glm_mat4_identity(camera->view_matrix);
    glm_mat4_mul(camera->projection_matrix, camera->view_matrix, camera->view_projection_matrix);
}

void orthographic_camera_recalculate_view_projection_matrix(orthographic_camera_t* camera)
{
    mat4 transform = GLM_MAT4_IDENTITY_INIT;
    glm_translate(transform, camera->position);
    glm_mat4_inv(transform, camera->view_matrix);
    glm_mat4_mul(camera->projection_matrix, camera->view_matrix, camera->view_projection_matrix);
}


#endif //SANDBOX_ORTHOGRAPHIC_CAMERA_H
