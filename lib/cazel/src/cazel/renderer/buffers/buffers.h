//
// Created by Frank on 28/07/2020.
//

#ifndef SANDBOX_BUFFERS_H
#define SANDBOX_BUFFERS_H

#include "../../core.h"

typedef enum
{
    shader_data_type_float,
    shader_data_type_float2,
    shader_data_type_float3,
    shader_data_type_float4,
    shader_data_type_mat3,
    shader_data_type_mat4,
    shader_data_type_int,
    shader_data_type_int2,
    shader_data_type_int3,
    shader_data_type_int4,
    shader_data_type_bool,
} shader_data_type_t;



typedef struct
{
    shader_data_type_t data_type;
    size_t size;
    size_t offset;
    bool normalized;
} buffer_element_t;



typedef struct
{
    buffer_element_t* elements;
    size_t size;
    size_t stride;
} buffer_layout_t;


size_t shader_data_type_size(shader_data_type_t type);
size_t shader_data_type_component_count(shader_data_type_t type);


buffer_element_t buffers_create_buffer_element(shader_data_type_t data_type);
void buffers_create_buffer_layout(buffer_layout_t* buffer_layout, buffer_element_t* elements, size_t size);

void buffers_print_layout(buffer_layout_t* layout);

#endif //SANDBOX_BUFFERS_H
