//
// Created by Frank on 28/07/2020.
//

#include "glfw_input.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

key_t glfw_key_to_key_t(int key)
{
    switch(key)
    {
        case GLFW_KEY_A: return key_a;
        case GLFW_KEY_B: return key_b;
        case GLFW_KEY_C: return key_c;
        case GLFW_KEY_D: return key_d;
        case GLFW_KEY_E: return key_e;
        case GLFW_KEY_F: return key_f;
        case GLFW_KEY_G: return key_g;
        case GLFW_KEY_H: return key_h;
        case GLFW_KEY_I: return key_i;
        case GLFW_KEY_J: return key_j;
        case GLFW_KEY_K: return key_k;
        case GLFW_KEY_L: return key_l;
        case GLFW_KEY_M: return key_m;
        case GLFW_KEY_N: return key_n;
        case GLFW_KEY_O: return key_o;
        case GLFW_KEY_P: return key_p;
        case GLFW_KEY_Q: return key_q;
        case GLFW_KEY_R: return key_r;
        case GLFW_KEY_S: return key_s;
        case GLFW_KEY_T: return key_t_;
        case GLFW_KEY_U: return key_u;
        case GLFW_KEY_V: return key_v;
        case GLFW_KEY_W: return key_w;
        case GLFW_KEY_X: return key_x;
        case GLFW_KEY_Y: return key_y;
        case GLFW_KEY_Z: return key_z;

        case GLFW_KEY_0: return key_0;
        case GLFW_KEY_1: return key_1;
        case GLFW_KEY_2: return key_2;
        case GLFW_KEY_3: return key_3;
        case GLFW_KEY_4: return key_4;
        case GLFW_KEY_5: return key_5;
        case GLFW_KEY_6: return key_6;
        case GLFW_KEY_7: return key_7;
        case GLFW_KEY_8: return key_8;
        case GLFW_KEY_9: return key_9;

        case GLFW_KEY_F1 : return key_f1;
        case GLFW_KEY_F2 : return key_f2;
        case GLFW_KEY_F3 : return key_f3;
        case GLFW_KEY_F4 : return key_f4;
        case GLFW_KEY_F5 : return key_f5;
        case GLFW_KEY_F6 : return key_f6;
        case GLFW_KEY_F7 : return key_f7;
        case GLFW_KEY_F8 : return key_f8;
        case GLFW_KEY_F9 : return key_f9;
        case GLFW_KEY_F10: return key_f10;
        case GLFW_KEY_F11: return key_f11;
        case GLFW_KEY_F12: return key_f12;

        case GLFW_KEY_LEFT_CONTROL  : return key_left_control;
        case GLFW_KEY_RIGHT_CONTROL : return key_right_control;
        case GLFW_KEY_LEFT_SHIFT    : return key_left_shift;
        case GLFW_KEY_RIGHT_SHIFT   : return key_right_shift;
        case GLFW_KEY_LEFT_ALT      : return key_left_alt;
        case GLFW_KEY_RIGHT_ALT     : return key_right_alt;
        case GLFW_KEY_CAPS_LOCK     : return key_caps;
        case GLFW_KEY_TAB           : return key_tab;
        case GLFW_KEY_GRAVE_ACCENT  : return key_tilde;
        case GLFW_KEY_ESCAPE        : return key_escape;
        case GLFW_KEY_ENTER         : return key_enter;

        case GLFW_KEY_INSERT    : return key_insert;
        case GLFW_KEY_HOME      : return key_home;
        case GLFW_KEY_END       : return key_end;
        case GLFW_KEY_DELETE    : return key_delete;
        case GLFW_KEY_PAGE_UP   : return key_pageup;
        case GLFW_KEY_PAGE_DOWN : return key_pagedown;

        case GLFW_KEY_LEFT  : return key_left;
        case GLFW_KEY_RIGHT : return key_right;
        case GLFW_KEY_UP    : return key_up;
        case GLFW_KEY_DOWN  : return key_down;

        default:
            printf("Unsupported key: %i\n", key);
            return key_none;
    }
}

int key_t_to_glfw(key_t key)
{
    switch(key)
    {
        case key_a: return GLFW_KEY_A;
        case key_b: return GLFW_KEY_B;
        case key_c: return GLFW_KEY_C;
        case key_d: return GLFW_KEY_D;
        case key_e: return GLFW_KEY_E;
        case key_f: return GLFW_KEY_F;
        case key_g: return GLFW_KEY_G;
        case key_h: return GLFW_KEY_H;
        case key_i: return GLFW_KEY_I;
        case key_j: return GLFW_KEY_J;
        case key_k: return GLFW_KEY_K;
        case key_l: return GLFW_KEY_L;
        case key_m: return GLFW_KEY_M;
        case key_n: return GLFW_KEY_N;
        case key_o: return GLFW_KEY_O;
        case key_p: return GLFW_KEY_P;
        case key_q: return GLFW_KEY_Q;
        case key_r: return GLFW_KEY_R;
        case key_s: return GLFW_KEY_S;
        case key_t_:return GLFW_KEY_T;
        case key_u: return GLFW_KEY_U;
        case key_v: return GLFW_KEY_V;
        case key_w: return GLFW_KEY_W;
        case key_x: return GLFW_KEY_X;
        case key_y: return GLFW_KEY_Y;
        case key_z: return GLFW_KEY_Z;

        case key_0: return GLFW_KEY_0;
        case key_1: return GLFW_KEY_1;
        case key_2: return GLFW_KEY_2;
        case key_3: return GLFW_KEY_3;
        case key_4: return GLFW_KEY_4;
        case key_5: return GLFW_KEY_5;
        case key_6: return GLFW_KEY_6;
        case key_7: return GLFW_KEY_7;
        case key_8: return GLFW_KEY_8;
        case key_9: return GLFW_KEY_9;

        case key_f1 : return GLFW_KEY_F1 ;
        case key_f2 : return GLFW_KEY_F2 ;
        case key_f3 : return GLFW_KEY_F3 ;
        case key_f4 : return GLFW_KEY_F4 ;
        case key_f5 : return GLFW_KEY_F5 ;
        case key_f6 : return GLFW_KEY_F6 ;
        case key_f7 : return GLFW_KEY_F7 ;
        case key_f8 : return GLFW_KEY_F8 ;
        case key_f9 : return GLFW_KEY_F9 ;
        case key_f10: return GLFW_KEY_F10;
        case key_f11: return GLFW_KEY_F11;
        case key_f12: return GLFW_KEY_F12;

        case key_left_control   : return GLFW_KEY_LEFT_CONTROL  ;
        case key_right_control  : return GLFW_KEY_RIGHT_CONTROL ;
        case key_left_shift     : return GLFW_KEY_LEFT_SHIFT    ;
        case key_right_shift    : return GLFW_KEY_RIGHT_SHIFT   ;
        case key_left_alt       : return GLFW_KEY_LEFT_ALT      ;
        case key_right_alt      : return GLFW_KEY_RIGHT_ALT     ;
        case key_caps           : return GLFW_KEY_CAPS_LOCK     ;
        case key_tab            : return GLFW_KEY_TAB           ;
        case key_tilde          : return GLFW_KEY_GRAVE_ACCENT  ;
        case key_escape         : return GLFW_KEY_ESCAPE        ;
        case key_enter          : return GLFW_KEY_ENTER         ;

        case key_insert  : return GLFW_KEY_INSERT      ;
        case key_home    : return GLFW_KEY_HOME        ;
        case key_end     : return GLFW_KEY_END         ;
        case key_delete  : return GLFW_KEY_DELETE      ;
        case key_pageup  : return GLFW_KEY_PAGE_UP     ;
        case key_pagedown: return GLFW_KEY_PAGE_DOWN   ;

        case key_left : return GLFW_KEY_LEFT   ;
        case key_right: return GLFW_KEY_RIGHT  ;
        case key_up   : return GLFW_KEY_UP     ;
        case key_down : return GLFW_KEY_DOWN   ;

        default:
            printf("Unsupported key: %i\n", key);
            return GLFW_KEY_UNKNOWN;
    }
}

bool glfw_mouse_button_pressed(window_t* window, mouse_button_t button)
{
    switch (button)
    {
        default:
            EXIT_ERROR("Unknown mousebutton: %i\n", button);
            break;
        case mouse_button_left:
            return glfwGetMouseButton(window->handle, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
        case mouse_button_right:
            return glfwGetMouseButton(window->handle, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;
        case mouse_button_middle:
            return glfwGetMouseButton(window->handle, GLFW_MOUSE_BUTTON_MIDDLE) == GLFW_PRESS;
    }
}

bool glfw_key_pressed(window_t* window, key_t key)
{
    return glfwGetKey(window->handle, key_t_to_glfw(key));
}
