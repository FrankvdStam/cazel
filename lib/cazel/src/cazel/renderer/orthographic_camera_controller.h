//
// Created by Frank on 06/08/2020.
//

#ifndef SANDBOX_ORTHOGRAPHIC_CAMERA_CONTROLLER_H
#define SANDBOX_ORTHOGRAPHIC_CAMERA_CONTROLLER_H


#include "orthographic_camera.h"
#include "../events/event.h"

extern orthographic_camera_t s_camera;

void orthographic_camera_controller_init(float aspect_ratio, bool rotation);
void orthographic_camera_controller_update(float delta_time);
void orthographic_camera_controller_on_event(event_t event);
#endif //SANDBOX_ORTHOGRAPHIC_CAMERA_CONTROLLER_H
