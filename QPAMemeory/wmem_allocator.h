#ifndef WMEM_ALLOCATOR_H
#define WMEM_ALLOCATOR_H
#include "wmem_core.h"

struct _wmem_user_cb_container_t;

/* See section "4. Internal Design" of doc/README.wmem for details
 * on this structure */
struct _wmem_allocator_t {
    /* Consumer functions */
    void *(*alloc)(void *private_data, const size_t size);
    void  (*free)(void *private_data, void *ptr);
    void *(*realloc)(void *private_data, void *ptr, const size_t size);

    /* Producer/Manager functions */
    void  (*free_all)(void *private_data);
    void  (*gc)(void *private_data);
    void  (*cleanup)(void *private_data);

    /* Callback List */
    struct _wmem_user_cb_container_t *callbacks;

    /* Implementation details */
    void                        *private_data;
    enum _wmem_allocator_type_t  type;
    gboolean                     in_scope;
};


#endif // WMEM_ALLOCATOR_H
