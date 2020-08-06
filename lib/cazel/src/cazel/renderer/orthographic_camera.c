//
// Created by Frank on 05/08/2020.
//

#include "orthographic_camera.h"


void orthographic_camera_init(orthographic_camera_t* camera, float left, float right, float bottom, float top)
{
    glm_vec3_zero(camera->position);

    //glm_mat4_zero(camera->projection_matrix);
    glm_ortho(left, right, bottom, top, -1.0f, 1.0f, camera->projection_matrix);
    glm_mat4_identity(camera->view_matrix);
    glm_mat4_mul(camera->projection_matrix, camera->view_matrix, camera->view_projection_matrix);
    camera->rotation = 0.0f;
}

void orthographic_camera_recalculate_view_projection_matrix(orthographic_camera_t* camera)
{
    //translate
    mat4 translate = GLM_MAT4_IDENTITY_INIT;
    glm_translate(translate, camera->position);

    //rotate
    mat4 rotate = GLM_MAT4_IDENTITY_INIT;
    vec3 axis = {0.0f, 0.0f, 1.0f};
    glm_rotate(rotate, glm_rad(camera->rotation), axis);


    //transform
    mat4 transform = GLM_MAT4_ZERO_INIT;
    glm_mat4_mul(translate, rotate, transform);

    glm_mat4_inv(transform, camera->view_matrix);
    glm_mat4_mul(camera->projection_matrix, camera->view_matrix, camera->view_projection_matrix);

    ////==
    //
//
    //glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position)
    //
    //
    //        * glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0, 0, 1));
    //m_ViewMatrix = glm::inverse(translate);
    //m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
}
