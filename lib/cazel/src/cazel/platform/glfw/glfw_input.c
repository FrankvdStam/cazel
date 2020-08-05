//
// Created by Frank on 28/07/2020.
//

#include "glfw_input.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

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
    switch(key)
    {
        case key_a:
            return glfwGetKey(window->handle, GLFW_KEY_A) == GLFW_PRESS;
        case key_b:
            return glfwGetKey(window->handle, GLFW_KEY_B) == GLFW_PRESS;
        case key_c:
            return glfwGetKey(window->handle, GLFW_KEY_C) == GLFW_PRESS;
        case key_d:
            return glfwGetKey(window->handle, GLFW_KEY_D) == GLFW_PRESS;
        case key_e:
            return glfwGetKey(window->handle, GLFW_KEY_E) == GLFW_PRESS;
        case key_f:
            return glfwGetKey(window->handle, GLFW_KEY_F) == GLFW_PRESS;
        case key_g:
            return glfwGetKey(window->handle, GLFW_KEY_G) == GLFW_PRESS;
        case key_h:
            return glfwGetKey(window->handle, GLFW_KEY_H) == GLFW_PRESS;
        case key_i:
            return glfwGetKey(window->handle, GLFW_KEY_I) == GLFW_PRESS;
        case key_j:
            return glfwGetKey(window->handle, GLFW_KEY_J) == GLFW_PRESS;
        case key_k:
            return glfwGetKey(window->handle, GLFW_KEY_K) == GLFW_PRESS;
        case key_l:
            return glfwGetKey(window->handle, GLFW_KEY_L) == GLFW_PRESS;
        case key_m:
            return glfwGetKey(window->handle, GLFW_KEY_M) == GLFW_PRESS;
        case key_n:
            return glfwGetKey(window->handle, GLFW_KEY_N) == GLFW_PRESS;
        case key_o:
            return glfwGetKey(window->handle, GLFW_KEY_O) == GLFW_PRESS;
        case key_p:
            return glfwGetKey(window->handle, GLFW_KEY_P) == GLFW_PRESS;
        case key_q:
            return glfwGetKey(window->handle, GLFW_KEY_Q) == GLFW_PRESS;
        case key_r:
            return glfwGetKey(window->handle, GLFW_KEY_R) == GLFW_PRESS;
        case key_s:
            return glfwGetKey(window->handle, GLFW_KEY_S) == GLFW_PRESS;
        case key_t_:
            return glfwGetKey(window->handle, GLFW_KEY_T) == GLFW_PRESS;
        case key_u:
            return glfwGetKey(window->handle, GLFW_KEY_U) == GLFW_PRESS;
        case key_v:
            return glfwGetKey(window->handle, GLFW_KEY_B) == GLFW_PRESS;
        case key_w:
            return glfwGetKey(window->handle, GLFW_KEY_W) == GLFW_PRESS;
        case key_x:
            return glfwGetKey(window->handle, GLFW_KEY_X) == GLFW_PRESS;
        case key_y:
            return glfwGetKey(window->handle, GLFW_KEY_Y) == GLFW_PRESS;
        case key_z:
            return glfwGetKey(window->handle, GLFW_KEY_Z) == GLFW_PRESS;
        case key_0:
            return glfwGetKey(window->handle, GLFW_KEY_0) == GLFW_PRESS;
        case key_1:
            return glfwGetKey(window->handle, GLFW_KEY_1) == GLFW_PRESS;
        case key_2:
            return glfwGetKey(window->handle, GLFW_KEY_2) == GLFW_PRESS;
        case key_3:
            return glfwGetKey(window->handle, GLFW_KEY_3) == GLFW_PRESS;
        case key_4:
            return glfwGetKey(window->handle, GLFW_KEY_4) == GLFW_PRESS;
        case key_5:
            return glfwGetKey(window->handle, GLFW_KEY_5) == GLFW_PRESS;
        case key_6:
            return glfwGetKey(window->handle, GLFW_KEY_6) == GLFW_PRESS;
        case key_7:
            return glfwGetKey(window->handle, GLFW_KEY_7) == GLFW_PRESS;
        case key_8:
            return glfwGetKey(window->handle, GLFW_KEY_8) == GLFW_PRESS;
        case key_9:
            return glfwGetKey(window->handle, GLFW_KEY_9) == GLFW_PRESS;
        case key_f1:
            return glfwGetKey(window->handle, GLFW_KEY_F1) == GLFW_PRESS;
        case key_f2:
            return glfwGetKey(window->handle, GLFW_KEY_F2) == GLFW_PRESS;
        case key_f3:
            return glfwGetKey(window->handle, GLFW_KEY_F3) == GLFW_PRESS;
        case key_f4:
            return glfwGetKey(window->handle, GLFW_KEY_F4) == GLFW_PRESS;
        case key_f5:
            return glfwGetKey(window->handle, GLFW_KEY_F5) == GLFW_PRESS;
        case key_f6:
            return glfwGetKey(window->handle, GLFW_KEY_F6) == GLFW_PRESS;
        case key_f7:
            return glfwGetKey(window->handle, GLFW_KEY_F7) == GLFW_PRESS;
        case key_f8:
            return glfwGetKey(window->handle, GLFW_KEY_F8) == GLFW_PRESS;
        case key_f9:
            return glfwGetKey(window->handle, GLFW_KEY_F9) == GLFW_PRESS;
        case key_f10:
            return glfwGetKey(window->handle, GLFW_KEY_F10) == GLFW_PRESS;
        case key_f11:
            return glfwGetKey(window->handle, GLFW_KEY_F11) == GLFW_PRESS;
        case key_f12:
            return glfwGetKey(window->handle, GLFW_KEY_F12) == GLFW_PRESS;
        case key_left_control:
            return glfwGetKey(window->handle, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS;
        case key_right_control:
            return glfwGetKey(window->handle, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS;
        case key_left_shift:
            return glfwGetKey(window->handle, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS;
        case key_right_shift:
            return glfwGetKey(window->handle, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS;
        case key_left_alt:
            return glfwGetKey(window->handle, GLFW_KEY_LEFT_ALT) == GLFW_PRESS;
        case key_right_alt:
            return glfwGetKey(window->handle, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS;
        case key_caps:
            return glfwGetKey(window->handle, GLFW_KEY_CAPS_LOCK) == GLFW_PRESS;
        case key_tab:
            return glfwGetKey(window->handle, GLFW_KEY_TAB) == GLFW_PRESS;
        case key_tilde:
            return glfwGetKey(window->handle, GLFW_KEY_GRAVE_ACCENT) == GLFW_PRESS;
        case key_escape:
            return glfwGetKey(window->handle, GLFW_KEY_ESCAPE) == GLFW_PRESS;
        case key_enter:
            return glfwGetKey(window->handle, GLFW_KEY_ENTER) == GLFW_PRESS;
        case key_insert:
            return glfwGetKey(window->handle, GLFW_KEY_INSERT) == GLFW_PRESS;
        case key_home:
            return glfwGetKey(window->handle, GLFW_KEY_HOME) == GLFW_PRESS;
        case key_end:
            return glfwGetKey(window->handle, GLFW_KEY_END) == GLFW_PRESS;
        case key_delete:
            return glfwGetKey(window->handle, GLFW_KEY_DELETE) == GLFW_PRESS;
        case key_pageup:
            return glfwGetKey(window->handle, GLFW_KEY_PAGE_UP) == GLFW_PRESS;
        case key_pagedown:
            return glfwGetKey(window->handle, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS;
        default: EXIT_ERROR("Unknown key: %i\n", key);
    }
}
