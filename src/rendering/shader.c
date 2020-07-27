//
// Created by Frank on 06/07/2020.
//

#include "shader.h"

GLuint shaders[10];

GLuint shader_create(const char* vertex_shader_source, const char* fragment_shader_source)
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

    GLuint shader = glCreateProgram();
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



void init_shaders()
{
    const char* vertex_shader_source = "#version 330 core\n"
                                       "layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0\n"
                                       "layout (location = 1) in vec3 aColor; // the color variable has attribute position 1\n"
                                       "  \n"
                                       "out vec3 ourColor; // output a color to the fragment shader\n"
                                       "\n"
                                       "void main()\n"
                                       "{\n"
                                       "    gl_Position = vec4(aPos, 1.0);\n"
                                       "    ourColor = aColor; // set ourColor to the input color we got from the vertex data\n"
                                       "}\0";



    //const char* vertex_shader_source =   "#version 330 core\n"
    //                                     "layout (location = 0) in vec3 aPos;\n"
    //                                     "layout (location = 1) in vec3 aColor; // the color variable has attribute position 1\n"
    //                                     "out vec3 ourColor; // output a color to the fragment shader\n"
    //                                     "void main()\n"
    //                                     "{\n"
    //                                     "    gl_Position = vec4(aPos, 1.0);\n"
    //                                     "    ourColor = aColor; // set ourColor to the input color we got from the vertex data\n"
    //                                     "}\0";

    const char* fragment_shader_source = "#version 330 core\n"
                                       "out vec4 FragColor;\n"
                                       "in vec3 ourColor;"
                                       "//uniform vec4 fill_color; // we set this variable in the OpenGL code.\n"
                                       "void main()\n"
                                       "{\n"
                                       "    FragColor = vec4(ourColor, 1.0);\n"
                                       "}\0";

    GLuint color_shader = shader_create(vertex_shader_source, fragment_shader_source);
    shaders[SHADER_COLOR] = color_shader;
}

GLuint get_shader(size_t shader)
{
    return shaders[shader];
}

void free_shaders()
{
    glDeleteProgram(shaders[SHADER_COLOR]);
}

//void shader_use(GLuint shader)
//{
//    glUseProgram(shader);
//}
//
//void shader_free(GLuint shader)
//{
//    glDeleteProgram(shader);
//}