/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "wmem_miscutl.h"
#include "wmem_core.h"
#include <string.h>
void *
wmem_memdup(wmem_allocator_t *allocator, const void *source, const size_t size)
{
    void *dest;

    dest = wmem_alloc(allocator, size);
    memcpy(dest, source, size);

    return dest;
}