#include <string.h>
#include <glib.h>

#include "wmem_core.h"
#include "wmem_miscutl.h"

void *
wmem_memdup(wmem_allocator_t *allocator, const void *source, const size_t size)
{
    void *dest;

    dest = wmem_alloc(allocator, size);
    memcpy(dest, source, size);

    return dest;
}
