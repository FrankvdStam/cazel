//
// Created by Frank on 28/07/2020.
//

#include "buffers.h"

size_t shader_data_type_size(shader_data_type_t type)
{
    switch(type)
    {
        default: EXIT_ERROR("Unknown shader data type.\n");
        case shader_data_type_float  : return 4;
        case shader_data_type_float2 : return 4 * 2;
        case shader_data_type_float3 : return 4 * 3;
        case shader_data_type_float4 : return 4 * 4;
        case shader_data_type_mat3   : return 4 * 4 * 3;
        case shader_data_type_mat4   : return 4 * 4 * 4;
        case shader_data_type_int    : return 4;
        case shader_data_type_int2   : return 4 * 2;
        case shader_data_type_int3   : return 4 * 3;
        case shader_data_type_int4   : return 4 * 4;
        case shader_data_type_bool   : return 1;
    }
}

size_t shader_data_type_component_count(shader_data_type_t type)
{
    switch(type)
    {
        default: EXIT_ERROR("Unknown shader data type.\n");
        case shader_data_type_float  : return 1;
        case shader_data_type_float2 : return 2;
        case shader_data_type_float3 : return 3;
        case shader_data_type_float4 : return 4;
        case shader_data_type_mat3   : return 3 * 3;
        case shader_data_type_mat4   : return 4 * 4;
        case shader_data_type_int    : return 1;
        case shader_data_type_int2   : return 2;
        case shader_data_type_int3   : return 3;
        case shader_data_type_int4   : return 4;
        case shader_data_type_bool   : return 1;
    }
}

buffer_element_t buffers_create_buffer_element(shader_data_type_t data_type)
{
    buffer_element_t buffer_element;
    buffer_element.data_type = data_type;
    buffer_element.size = shader_data_type_size(data_type);
    buffer_element.offset = 0;
    buffer_element.normalized = false;
    return buffer_element;
}

void buffers_create_buffer_layout(buffer_layout_t* buffer_layout, buffer_element_t* elements, size_t size)
{
    buffer_layout->elements = (buffer_element_t*)malloc(sizeof(buffer_element_t ) * size);
    buffer_layout->size = size;

    size_t offset = 0;
    size_t stride = 0;
    for(size_t i = 0; i < size; i++)
    {
        buffer_layout->elements[i] = elements[i];
        buffer_layout->elements[i].offset = offset;
        offset += buffer_layout->elements[i].size;
        stride += buffer_layout->elements[i].size;
    }
    buffer_layout->stride = stride;
}



void buffers_print_layout(buffer_layout_t* layout)
{
    printf("Printing buffer layout. Elements: %i, stride: %i.\n", (int)layout->size, (int)layout->stride);

    for(size_t i = 0; i < layout->size; i++)
    {
        printf("Element %i: size: %i offset: %i\n", (int)i, (int)layout->elements[i].size, (int)layout->elements[i].offset);
    }
}
