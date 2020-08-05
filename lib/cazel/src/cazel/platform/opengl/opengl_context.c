//
// Created by Frank on 28/07/2020.
//

#include "opengl_context.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "../../../../lib/glad/include/glad/glad.h"
#include "../../application.h"
#include "../../input.h"


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

GLenum shader_data_type_to_gl_enum(shader_data_type_t type)
{
    switch(type)
    {
        default: EXIT_ERROR("Unknown shader data type.\n");

        case shader_data_type_float  :
        case shader_data_type_float2 :
        case shader_data_type_float3 :
        case shader_data_type_float4 :
        case shader_data_type_mat3   :
        case shader_data_type_mat4   : return GL_FLOAT;

        case shader_data_type_int    :
        case shader_data_type_int2   :
        case shader_data_type_int3   :
        case shader_data_type_int4   : return GL_INT;

        case shader_data_type_bool   : return GL_BOOL;
    }
}

void gl_debug_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    if(severity == GL_DEBUG_SEVERITY_NOTIFICATION)
    {
        return;
    }
    printf("%s\n", message);
}

void glfw_close_window_event_callback(GLFWwindow* window) {
    event_t event = event_create_empty();
    event.type = event_window_close;
    application_on_event(event);
}

void glfw_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    event_t event = event_create_empty();

    switch(action)
    {
        case GLFW_RELEASE:
            event.type = event_key_released;
            break;
        case GLFW_PRESS:
            event.type = event_key_pressed;
            break;
        case GLFW_REPEAT:
            event.type = event_key_repeated;
            break;
        default:
            EXIT_ERROR("GLFW unsupported event type: %i\n", action);
            break;
    }

    event.key = glfw_key_to_key_t(key);
    application_on_event(event);
    //printf("key: %i, scancode: %i, action: %i, mods: %i\n", key, scancode, action, mods);
}

void opengl_context_init(window_t* window)
{
    glfwMakeContextCurrent(window->handle);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        EXIT_ERROR("Failed to initialize glad\n");
    }
    glEnable(GL_DEBUG_OUTPUT);
    GLDEBUGPROC proc = gl_debug_callback;
    glDebugMessageCallback(proc, NULL);
    glfwSetWindowCloseCallback(window->handle, glfw_close_window_event_callback);
    glfwSetKeyCallback(window->handle, glfw_key_callback);


    //glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    //{
    //    WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
//
    //    switch (action)
    //    {
    //        case GLFW_PRESS:
    //        {
    //            KeyPressedEvent event(static_cast<KeyCode>(key), 0);
    //            data.EventCallback(event);
    //            break;
    //        }
    //        case GLFW_RELEASE:
    //        {
    //            KeyReleasedEvent event(static_cast<KeyCode>(key));
    //            data.EventCallback(event);
    //            break;
    //        }
    //        case GLFW_REPEAT:
    //        {
    //            KeyPressedEvent event(static_cast<KeyCode>(key), 1);
    //            data.EventCallback(event);
    //            break;
    //        }
    //    }
    //});
}

void opengl_context_swap_buffers(window_t* window)
{
    glfwSwapBuffers(window->handle);
}

//========================================================================================================================================================================================================================
//Vertex array
void opengl_context_create_vertex_array(vertex_array_t* vertex_array)
{
    vertex_array->vertex_buffer_id = 0;
    vertex_array->vertex_count = 0;
    vertex_array->index_buffer_id = 0;
    vertex_array->index_count = 0;
    vertex_array->shader_id = 0;
    glGenVertexArrays(1, &vertex_array->vertex_array_id);
}

void opengl_context_bind_vertex_array(vertex_array_t* vertex_array)
{
    glBindVertexArray(vertex_array->vertex_array_id);
}

void opengl_context_free_vertex_array(vertex_array_t* vertex_array)
{
    glDeleteVertexArrays(1, &vertex_array->vertex_array_id);
}

//========================================================================================================================================================================================================================
//Vertex buffers

void opengl_context_create_vertex_buffer(vertex_array_t* vertex_array, float* vertices, size_t count, size_t total_floats)
{
    vertex_array->vertex_total_floats = total_floats;
    vertex_array->vertex_count = count;
    glGenBuffers(1, &vertex_array->vertex_buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_array->vertex_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * total_floats, vertices, GL_STATIC_DRAW);
}

void opengl_context_bind_vertex_buffer(vertex_array_t* vertex_array)
{
    glBindBuffer(GL_ARRAY_BUFFER, vertex_array->vertex_buffer_id);
}

void opengl_context_free_vertex_buffer(vertex_array_t* vertex_array)
{
    glDeleteBuffers(GL_ARRAY_BUFFER, &vertex_array->vertex_buffer_id);
}

void opengl_context_set_vertex_buffer_layout(vertex_array_t* vertex_array)
{
    for(unsigned int i = 0; i < vertex_array->vertex_layout.size; i++)
    {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(
                i,
                shader_data_type_component_count(vertex_array->vertex_layout.elements[i].data_type),
                shader_data_type_to_gl_enum(vertex_array->vertex_layout.elements[i].data_type),
                vertex_array->vertex_layout.elements[i].normalized ? GL_TRUE : GL_FALSE,
                vertex_array->vertex_layout.stride,
                (const void*)vertex_array->vertex_layout.elements[i].offset);
    }
}


//========================================================================================================================================================================================================================
//index buffers
void opengl_context_create_index_buffer(vertex_array_t* vertex_array, uint32_t* indices, size_t count)
{
    vertex_array->index_count = count;
    glGenBuffers(1, &vertex_array->index_buffer_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertex_array->index_buffer_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * count, indices, GL_STATIC_DRAW);
}

void opengl_context_bind_index_buffer(vertex_array_t* vertex_array)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertex_array->index_buffer_id);
}

void opengl_context_free_index_buffer(vertex_array_t* vertex_array)
{
    glDeleteBuffers(GL_ELEMENT_ARRAY_BUFFER, &vertex_array->index_buffer_id);
}


//========================================================================================================================================================================================================================
//Shaders

unsigned int opengl_context_create_shader(const char* vertex_shader_source, const char* fragment_shader_source)
{
    int  success;
    char buffer[512];

    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, buffer);
        printf("Vertex shader failed to compile: %s\n", buffer);
    }

    unsigned int fragment_shader;
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, buffer);
        printf("Fragment shader failed to compile: %s\n", buffer);
    }

    unsigned int shader = glCreateProgram();
    glAttachShader(shader, vertex_shader);
    glAttachShader(shader, fragment_shader);
    glLinkProgram(shader);

    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shader, 512, NULL, buffer);
        printf("Shader linking failed: %s", buffer);
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return shader;
}


void opengl_context_bind_shader(unsigned int shader)
{
    glUseProgram(shader);
}

void opengl_context_free_shader(unsigned int shader)
{
    glDeleteProgram(shader);
}



//========================================================================================================================================================================================================================
//Clear color

//Set the color the screen should clear to
void opengl_context_set_clear_color(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

//Clear the screen to the clear color set by context_set_clear_color
void opengl_context_clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


//========================================================================================================================================================================================================================
//Uniforms

void opengl_context_upload_uniform_mat4(unsigned int shader, const char* name, mat4 matrix)
{
    int uniform_location = glGetUniformLocation(shader, name);
    if(uniform_location == -1)
    {
        EXIT_ERROR("Invalid uniform: %s\n", name);
    }
    glUniformMatrix4fv(uniform_location, 1, GL_FALSE, matrix[0]);
}

