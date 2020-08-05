//
// Created by Frank on 27/07/2020.
//

#include "nuklear_layer.h"
#include "../window.h"

//window/opengl
#define GLFW_INCLUDE_NONE
#include "../../../lib/glfw/include/GLFW/glfw3.h"
#include "../../../lib/glad/include/glad/glad.h"

#include "../context.h"

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_GLFW_GL3_IMPLEMENTATION
#define NK_KEYSTATE_BASED_INPUT

#include "../../../lib/Nuklear/nuklear.h"
#include "../../../lib/Nuklear/demo/glfw_opengl3/nuklear_glfw_gl3.h"


#define MAX_VERTEX_BUFFER 512 * 1024
#define MAX_ELEMENT_BUFFER 128 * 1024

static struct nk_glfw glfw = {0};
static window_t s_window;
static struct nk_context *nuklear_context;
static struct nk_colorf bg;

void nuklear_layer_on_attach()
{
    nuklear_context = nk_glfw3_init(&glfw, s_window.handle, NK_GLFW3_INSTALL_CALLBACKS);
    struct nk_font_atlas *atlas;
    nk_glfw3_font_stash_begin(&glfw, &atlas);
    nk_glfw3_font_stash_end(&glfw);


    bg.r = 0.10f, bg.g = 0.18f, bg.b = 0.24f, bg.a = 1.0f;
}



void nuklear_layer_on_detach()
{
    nk_glfw3_shutdown(&glfw);
}

void nuklear_layer_on_update()
{
    glfwPollEvents();

    nk_glfw3_new_frame(&glfw);

    /* GUI */
    if (nk_begin(nuklear_context, "Demo", nk_rect(50, 50, 230, 250),
                 NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
                 NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
    {
        enum {EASY, HARD};
        static int op = EASY;
        static int property = 20;
        nk_layout_row_static(nuklear_context, 30, 80, 1);
        if (nk_button_label(nuklear_context, "button"))
            fprintf(stdout, "button pressed\n");

        nk_layout_row_dynamic(nuklear_context, 30, 2);
        if (nk_option_label(nuklear_context, "easy", op == EASY)) op = EASY;
        if (nk_option_label(nuklear_context, "hard", op == HARD)) op = HARD;

        nk_layout_row_dynamic(nuklear_context, 25, 1);
        nk_property_int(nuklear_context, "Compression:", 0, &property, 100, 10, 1);

        nk_layout_row_dynamic(nuklear_context, 20, 1);
        nk_label(nuklear_context, "background:", NK_TEXT_LEFT);
        nk_layout_row_dynamic(nuklear_context, 25, 1);
        if (nk_combo_begin_color(nuklear_context, nk_rgb_cf(bg), nk_vec2(nk_widget_width(nuklear_context),400))) {
            nk_layout_row_dynamic(nuklear_context, 120, 1);
            bg = nk_color_picker(nuklear_context, bg, NK_RGBA);
            nk_layout_row_dynamic(nuklear_context, 25, 1);
            bg.r = nk_propertyf(nuklear_context, "#R:", 0, bg.r, 1.0f, 0.01f,0.005f);
            bg.g = nk_propertyf(nuklear_context, "#G:", 0, bg.g, 1.0f, 0.01f,0.005f);
            bg.b = nk_propertyf(nuklear_context, "#B:", 0, bg.b, 1.0f, 0.01f,0.005f);
            bg.a = nk_propertyf(nuklear_context, "#A:", 0, bg.a, 1.0f, 0.01f,0.005f);
            nk_combo_end(nuklear_context);
        }
    }
    nk_end(nuklear_context);

    glViewport(0, 0, s_window.width, s_window.height);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(bg.r, bg.g, bg.b, bg.a);

    nk_glfw3_render(&glfw, NK_ANTI_ALIASING_ON, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER);
    context_swap_buffers(&s_window);
    //glfwSwapBuffers(s_window.handle);

}


void nuklear_layer_on_dispatch_event(event_t event)
{

}

layer_t nuklear_layer_init(window_t window)
{
    s_window = window;

    layer_t layer;
    layer_init(&layer, "Nuklear");
    layer.attach = &nuklear_layer_on_attach;
    layer.detach = &nuklear_layer_on_detach;
    layer.update = &nuklear_layer_on_update;
    layer.event = &nuklear_layer_on_dispatch_event;
    return layer;
}







