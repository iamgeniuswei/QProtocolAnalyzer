#ifndef WMEM_ALLOCATOR_STRICT_H
#define WMEM_ALLOCATOR_STRICT_H
#include "wmem_core.h"
extern
void
wmem_strict_allocator_init(wmem_allocator_t *allocator);

extern
void
wmem_strict_check_canaries(wmem_allocator_t *allocator);
#endif // WMEM_ALLOCATOR_STRICT_H
