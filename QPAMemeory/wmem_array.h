#ifndef WMEM_ARRAY_H
#define WMEM_ARRAY_H
#include <string.h>
#include <glib.h>

#include "wmem_core.h"
/** @addtogroup wmem
 *  @{
 *    @defgroup wmem-array Array
 *
 *    A resizable array implementation on top of wmem.
 *
 *    @{
 */

struct _wmem_array_t;

typedef struct _wmem_array_t wmem_array_t;

extern
wmem_array_t *
wmem_array_sized_new(wmem_allocator_t *allocator, gsize elem_size,
                     guint alloc_count)
G_GNUC_MALLOC;

extern
wmem_array_t *
wmem_array_new(wmem_allocator_t *allocator, const gsize elem_size)
G_GNUC_MALLOC;

extern
void
wmem_array_append(wmem_array_t *array, const void *in, guint count);

#define wmem_array_append_one(ARRAY, VAL) \
    wmem_array_append((ARRAY), &(VAL), 1)

extern
void *
wmem_array_index(wmem_array_t *array, guint array_index);

extern
void
wmem_array_sort(wmem_array_t *array, int (*compar)(const void*,const void*));

extern
void *
wmem_array_get_raw(wmem_array_t *array);

extern
guint
wmem_array_get_count(wmem_array_t *array);


#endif // WMEM_ARRAY_H
