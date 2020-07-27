//
// Created by Frank on 03/05/2020.
//

#ifndef CNES_RENDERER_H
#define CNES_RENDERER_H

void renderer_init();
void renderer_draw_triangle();
void renderer_poll_events();

GLFWwindow* renderer_get_window();

#endif //CNES_RENDERER_H
