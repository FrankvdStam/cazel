//
// Created by Frank on 06/08/2020.
//

#include "shaders.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


void read_file(const char* file_path, char *buffer[], size_t* file_size)
{
    FILE* file;
    //char* buffer;
    //unsigned long file_size;

    //Open file
    file = fopen(file_path, "rb");
    if (!file)
    {
        fprintf(stderr, "Unable to open file %s", file_path);
        return;
    }

    //Get file length
    fseek(file, 0, SEEK_END);
    *file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    //Allocate memory
    *buffer = (char *)malloc(*file_size + 1);
    if (!*buffer)
    {
        fprintf(stderr, "Memory error!");
        fclose(file);
        return;
    }

    //Read file contents into buffer
    fread(*buffer, *file_size, 1, file);
    fclose(file);
}


//TODO: error handling
void shaders_load_from_file(const char* path, char *vertex_shader_src[], char *fragment_shader_src[])
{
    //Read the file into a malloc'ed buffer
    char* buffer;
    size_t buffer_size;
    read_file(path, &buffer, &buffer_size);


    char* vertex_shader_start_ptr   = strstr(buffer, "#vertex_shader");
    uint32_t vertex_shader_start_index = (vertex_shader_start_ptr - buffer) + strlen("#vertex_shader");
    printf("%u", vertex_shader_start_index);



    char* fragment_shader_start_ptr   = strstr(buffer, "#fragment_shader");
    uint32_t fragment_shader_start_index = (fragment_shader_start_ptr - buffer) + strlen("#fragment_shader");
    printf("%u", fragment_shader_start_index);

    uint32_t vertex_shader_end_index = (fragment_shader_start_ptr - buffer);
    uint32_t fragment_shader_end_index = buffer_size;

    size_t vertex_shader_length = vertex_shader_end_index - vertex_shader_start_index + 1;
    size_t fragment_shader_length = fragment_shader_end_index - fragment_shader_start_index + 1;


    //printf("vertex shader s: %u e: %u\n", vertex_shader_start_index, vertex_shader_end_index);
    //printf("fragment shader s: %u e: %u\n", fragment_shader_start_index, fragment_shader_end_index);

    *vertex_shader_src = (char*)malloc(sizeof(char) * (vertex_shader_length));
    for(size_t i = 0; i < vertex_shader_length; i++)
    {
        (*vertex_shader_src)[i] = buffer[vertex_shader_start_index + i];
    }
    (*vertex_shader_src)[vertex_shader_length-1] = '\0';

    *fragment_shader_src = (char*)malloc(sizeof(char) * (fragment_shader_length));
    for(size_t i = 0; i < fragment_shader_length; i++)
    {
        (*fragment_shader_src)[i] = buffer[fragment_shader_start_index + i];
    }
    (*fragment_shader_src)[fragment_shader_length-1] = '\0';

    free(buffer);
}
