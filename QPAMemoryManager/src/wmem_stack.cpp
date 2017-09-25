/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "wmem_stack.h"
/* Wmem stack is implemented as a simple wrapper over Wmem list */

void *
wmem_stack_peek(const wmem_stack_t *stack)
{
    wmem_list_frame_t *frame;

    frame = wmem_list_head(stack);

    g_assert(frame);

    return wmem_list_frame_data(frame);
}

void *
wmem_stack_pop(wmem_stack_t *stack)
{
    void *data;

    data = wmem_stack_peek(stack);

    wmem_list_remove(stack, data);

    return data;
}
