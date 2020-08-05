//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_INPUT_H
#define SANDBOX_INPUT_H

#include "core.h"
#include "window.h"

void input_platform_init(platform_t platform);


//=====================================================================================================================
//Mouse

typedef enum
{
    mouse_button_left,
    mouse_button_right,
    mouse_button_middle,
} mouse_button_t;

typedef enum
{
    key_none,

    key_a,
    key_b,
    key_c,
    key_d,
    key_e,
    key_f,
    key_g,
    key_h,
    key_i,
    key_j,
    key_k,
    key_l,
    key_m,
    key_n,
    key_o,
    key_p,
    key_q,
    key_r,
    key_s,
    key_t_,
    key_u,
    key_v,
    key_w,
    key_x,
    key_y,
    key_z,

    key_0,
    key_1,
    key_2,
    key_3,
    key_4,
    key_5,
    key_6,
    key_7,
    key_8,
    key_9,

    key_f1,
    key_f2,
    key_f3,
    key_f4,
    key_f5,
    key_f6,
    key_f7,
    key_f8,
    key_f9,
    key_f10,
    key_f11,
    key_f12,

    key_left_control,
    key_right_control,
    key_left_shift,
    key_right_shift,
    key_left_alt,
    key_right_alt,
    key_caps,
    key_tab,
    key_tilde,
    key_escape,
    key_enter,

    key_insert,
    key_home,
    key_end,
    key_delete,
    key_pageup,
    key_pagedown,

    key_left,
    key_right,
    key_up,
    key_down,
} key_t;

extern bool(*input_mouse_button_pressed)(window_t* window, mouse_button_t button);
extern bool(*input_key_pressed)(window_t* window, key_t key);


#endif //SANDBOX_INPUT_H
