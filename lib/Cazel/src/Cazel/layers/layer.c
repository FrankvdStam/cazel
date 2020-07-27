//
// Created by Frank on 27/07/2020.
//

#include "layer.h"
layer_t layer_init(char* name)
{
    layer_t layer;
    layer.name = malloc(sizeof(char) * (strlen(name)+1));
    strcpy(layer.name, name);
    return layer;
}

void layer_free(layer_t* layer)
{
    free(layer->name);
}

layer_stack_t layer_stack_init(size_t size)
{
    layer_stack_t stack;
    stack.size = size;
    stack.add_index = 0;
    stack.layers = (layer_t*)malloc(sizeof(layer_t) * size);
    return stack;
}

void layer_stack_free(layer_stack_t* stack)
{
    free(stack->layers);
}

void layer_stack_add(layer_stack_t* stack, const layer_t layer)
{
    if(stack->add_index >= stack->size)
    {
        stack->size = stack->size * 2;
        stack->layers = realloc(stack->layers, stack->size);
    }
    stack->layers[stack->add_index] = layer;
    stack->add_index++;
}

void layer_stack_print_names(layer_stack_t* stack)
{
    printf("Layer names:\n");
    for(size_t i = 0; i < stack->add_index; i++)
    {
        printf("%s\n", stack->layers[i]);
    }
}