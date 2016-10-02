#ifndef WMEM_ALLOCATOR_BLOCK_H
#define WMEM_ALLOCATOR_BLOCK_H
#include "wmem_core.h"
extern
void
wmem_block_allocator_init(wmem_allocator_t *allocator);

/* Exposed only for testing purposes */
extern
void
wmem_block_verify(wmem_allocator_t *allocator);

#endif // WMEM_ALLOCATOR_BLOCK_H
