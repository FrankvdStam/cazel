//
// Created by Frank on 06/08/2020.
//

#ifndef SANDBOX_ORTHOGRAPHIC_CAMERA_CONTROLLER_H
#define SANDBOX_ORTHOGRAPHIC_CAMERA_CONTROLLER_H


#include "orthographic_camera.h"

extern orthographic_camera_t s_camera;

void orthographic_camera_controller_init();
void orthographic_camera_controller_update(float delta_time);

#endif //SANDBOX_ORTHOGRAPHIC_CAMERA_CONTROLLER_H
