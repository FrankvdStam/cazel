//
// Created by Frank on 06/08/2020.
//

#include "orthographic_camera_controller.h"
#include "../input.h"
#include "../application.h"

orthographic_camera_t s_camera;

float s_camera_move_speed = 1.0f;
float s_camera_rotation_speed = 180.0f;

float resolve_rotation(float rotation)
{
    if(rotation > 360.0f)
    {
        rotation = 0.0f;
    }

    if(rotation < 0.0f)
    {
        rotation = 360.0f;
    }

    return rotation;
}

void orthographic_camera_controller_update(float delta_time)
{
    if(input_key_pressed(&s_application.window, key_a))
    {
        s_camera.position[0] -= cosf(glm_rad(s_camera.rotation)) * s_camera_move_speed * delta_time;
        s_camera.position[1] -= sinf(glm_rad(s_camera.rotation)) * s_camera_move_speed * delta_time;
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
    }
    else if(input_key_pressed(&s_application.window, key_d))
    {
        s_camera.position[0] += cosf(glm_rad(s_camera.rotation)) * s_camera_move_speed * delta_time;
        s_camera.position[1] += sinf(glm_rad(s_camera.rotation)) * s_camera_move_speed * delta_time;
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
    }

    if(input_key_pressed(&s_application.window, key_s))
    {
        s_camera.position[0] -= -sinf(glm_rad(s_camera.rotation)) * s_camera_move_speed * delta_time;
        s_camera.position[1] -= cosf(glm_rad(s_camera.rotation)) * s_camera_move_speed * delta_time;
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
    }
    else if(input_key_pressed(&s_application.window, key_w))
    {
        s_camera.position[0] += -sinf(glm_rad(s_camera.rotation)) * s_camera_move_speed * delta_time;
        s_camera.position[1] += cosf(glm_rad(s_camera.rotation)) * s_camera_move_speed * delta_time;
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
    }

    if(input_key_pressed(&s_application.window, key_q))
    {
        s_camera.rotation -= s_camera_rotation_speed * delta_time;
        s_camera.rotation = resolve_rotation(s_camera.rotation);
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
        printf("Rotation: %f\n", s_camera.rotation);
    }
    else if(input_key_pressed(&s_application.window, key_e))
    {
        s_camera.rotation += s_camera_rotation_speed * delta_time;
        s_camera.rotation = resolve_rotation(s_camera.rotation);
        orthographic_camera_recalculate_view_projection_matrix(&s_camera);
        printf("Rotation: %f\n", s_camera.rotation);
    }
}
