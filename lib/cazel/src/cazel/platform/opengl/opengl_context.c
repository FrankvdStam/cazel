//
// Created by Frank on 28/07/2020.
//

#include "opengl_context.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "../../../../lib/glad/include/glad/glad.h"
#include "../../application.h"
#include "../../input.h"
#include "../glfw/glfw_input.h"
#include "../../renderer/shaders.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../../../lib/stb/stb_image.h"



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


//========================================================================================================================================================================================================================
//Events

void gl_debug_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
    if(severity == GL_DEBUG_SEVERITY_NOTIFICATION)
    {
        return;
    }
    printf("%s\n", message);
}

void print_opengl_info()
{
    const unsigned char* vendor = glGetString(GL_VENDOR);
    const unsigned char* renderer = glGetString(GL_RENDERER);
    const unsigned char* version = glGetString(GL_VERSION);

    printf("OpenGL info\n");
    printf("Vendor: %s\n", vendor);
    printf("renderer: %s\n", renderer);
    printf("version: %s\n", version);
}

//========================================================================================================================================================================================================================
//Initialization

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


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);

    print_opengl_info();
}

void opengl_context_enable_blending()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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

void opengl_context_create_vertex_buffer(vertex_array_t* vertex_array, void* vertices, size_t count, size_t total_floats)
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

void opengl_context_create_shader_from_file(vertex_array_t* vertex_array, const char* filepath)
{
    char* vertex_shader_source;
    char* fragment_shader_source;

    shaders_load_from_file(filepath, &vertex_shader_source, &fragment_shader_source);

    //printf("vertex shader: \n%s\n", vertex_shader_source);
    //printf("fragment: \n%s\n", fragment_shader_source);

    opengl_context_create_shader(vertex_array, vertex_shader_source, fragment_shader_source);

    free(vertex_shader_source);
    free(fragment_shader_source);
}


void opengl_context_create_shader(vertex_array_t* vertex_array, const char* vertex_shader_source, const char* fragment_shader_source)
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

    vertex_array->shader_id = shader;
}


void opengl_context_bind_shader(vertex_array_t* vertex_array)
{
    glUseProgram(vertex_array->shader_id);
}

void opengl_context_free_shader(vertex_array_t* vertex_array)
{
    glDeleteProgram(vertex_array->shader_id);
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

void opengl_context_upload_uniform_int(unsigned int shader, const char* name, int i)
{
    int uniform_location = glGetUniformLocation(shader, name);
    glUniform1i(uniform_location, i);
}

void opengl_context_upload_uniform_float(unsigned int shader, const char* name, float f)
{
    int uniform_location = glGetUniformLocation(shader, name);
    glUniform1f(uniform_location, f);
}

void opengl_context_upload_uniform_vec2(unsigned int shader, const char* name, vec2 vec)
{
    int uniform_location = glGetUniformLocation(shader, name);
    glUniform2f(uniform_location, vec[0], vec[1]);
}

void opengl_context_upload_uniform_vec3(unsigned int shader, const char* name, vec3 vec)
{
    int uniform_location = glGetUniformLocation(shader, name);
    glUniform3f(uniform_location, vec[0], vec[1], vec[2]);
}

void opengl_context_upload_uniform_vec4(unsigned int shader, const char* name, vec4 vec)
{
    int uniform_location = glGetUniformLocation(shader, name);
    glUniform4f(uniform_location, vec[0], vec[1], vec[2], vec[3]);
}

void opengl_context_upload_uniform_mat3(unsigned int shader, const char* name, mat3 matrix)
{
    int uniform_location = glGetUniformLocation(shader, name);
    glUniformMatrix4fv(uniform_location, 1, GL_FALSE, matrix[0]);
}

void opengl_context_upload_uniform_mat4(unsigned int shader, const char* name, mat4 matrix)
{
    int uniform_location = glGetUniformLocation(shader, name);
    glUniformMatrix4fv(uniform_location, 1, GL_FALSE, matrix[0]);
}

//========================================================================================================================================================================================================================
//Time

float opengl_context_get_time()
{
    return glfwGetTime();
}

//========================================================================================================================================================================================================================
//Textures

unsigned int opengl_context_load_texture(const char* filepath)
{
    unsigned int texture_id;
    int width, height, channels;
    stbi_set_flip_vertically_on_load(1);
    stbi_uc* texture = stbi_load(filepath, &width, &height, &channels, 0);

    if(!texture)
    {
        EXIT_ERROR("Texture not found: %s\n", filepath);
    }

    GLenum internal_format = 0;
    GLenum format = 0;
    if(channels == 3)
    {
        internal_format = GL_RGB8;
        format = GL_RGB;
    }
    else if (channels == 4)
    {
        internal_format = GL_RGBA8;
        format = GL_RGBA;
    }

    if(internal_format == 0 || format == 0)
    {
        EXIT_ERROR("Can't determine format for %s\n", filepath);
    }

    glCreateTextures(GL_TEXTURE_2D, 1, &texture_id);
    glTextureStorage2D(texture_id, 1, internal_format, width, height);

    glTextureParameteri(texture_id, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(texture_id, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTextureSubImage2D(texture_id, 0, 0, 0, width, height, format, GL_UNSIGNED_BYTE, texture);

    stbi_image_free(texture);

    return texture_id;
}

void opengl_context_bind_texture(uint32_t slot, unsigned int texture_id)
{
    glBindTextureUnit(slot, texture_id);
}

void opengl_context_delete_texture(unsigned int texture_id)
{
    glDeleteTextures(1, &texture_id);
}



void opengl_context_set_viewport(uint32_t x, uint32_t y)
{
    glViewport(0, 0, x, y);
}
























