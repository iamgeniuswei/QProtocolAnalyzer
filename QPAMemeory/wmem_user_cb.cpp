#include "wmem_user_cb.h"
typedef struct _wmem_user_cb_container_t {
    wmem_user_cb_t                    cb;
    void                             *user_data;
    struct _wmem_user_cb_container_t *next;
    guint                             id;
} wmem_user_cb_container_t;

void
wmem_call_callbacks(wmem_allocator_t *allocator, wmem_cb_event_t event)
{
    wmem_user_cb_container_t **prev, *cur;
    gboolean again;

    prev = &(allocator->callbacks);
    cur  = allocator->callbacks;

    while (cur) {

        /* call it */
        again = cur->cb(allocator, event, cur->user_data);

        /* if the callback requested deregistration, or this is being triggered
         * by the final destruction of the allocator, remove the callback */
        if (! again || event == WMEM_CB_DESTROY_EVENT) {
            *prev = cur->next;
            wmem_free(NULL, cur);
            cur = *prev;
        }
        else {
            prev = &(cur->next);
            cur  = cur->next;
        }
    }
}

guint
wmem_register_callback(wmem_allocator_t *allocator,
        wmem_user_cb_t callback, void *user_data)
{
    wmem_user_cb_container_t *container;
    static guint next_id = 0;

    container = wmem_new(NULL, wmem_user_cb_container_t);

    container->cb        = callback;
    container->user_data = user_data;
    container->next      = allocator->callbacks;
    container->id        = next_id++;

    allocator->callbacks = container;

    return container->id;
}

void
wmem_unregister_callback(wmem_allocator_t *allocator, guint id)
{
    wmem_user_cb_container_t **prev, *cur;

    prev = &(allocator->callbacks);
    cur  = allocator->callbacks;

    while (cur) {

        if (cur->id == id) {
            *prev = cur->next;
            wmem_free(NULL, cur);
            return;
        }

        prev = &(cur->next);
        cur  = cur->next;
    }
}
