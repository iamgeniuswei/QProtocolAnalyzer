#ifndef WMEM_LIST_H
#define WMEM_LIST_H
#include <string.h>
#include <glib.h>

#include "wmem_core.h"
/** @addtogroup wmem
 *  @{
 *    @defgroup wmem-list Doubly-Linked List
 *
 *    A doubly-linked list implementation on top of wmem.
 *
 *    @{
 */

struct _wmem_list_t;
struct _wmem_list_frame_t;

typedef struct _wmem_list_t       wmem_list_t;
typedef struct _wmem_list_frame_t wmem_list_frame_t;

extern
guint
wmem_list_count(const wmem_list_t *list);

extern
wmem_list_frame_t *
wmem_list_head(const wmem_list_t *list);

extern
wmem_list_frame_t *
wmem_list_tail(const wmem_list_t *list);

extern
wmem_list_frame_t *
wmem_list_frame_next(const wmem_list_frame_t *frame);

extern
wmem_list_frame_t *
wmem_list_frame_prev(const wmem_list_frame_t *frame);

extern
void *
wmem_list_frame_data(const wmem_list_frame_t *frame);

extern
void
wmem_list_remove(wmem_list_t *list, void *data);

extern
void
wmem_list_remove_frame(wmem_list_t *list, wmem_list_frame_t *frame);

extern
void
wmem_list_prepend(wmem_list_t *list, void *data);

extern
void
wmem_list_append(wmem_list_t *list, void *data);

extern
wmem_list_t *
wmem_list_new(wmem_allocator_t *allocator)
G_GNUC_MALLOC;

extern
void
wmem_destroy_list(wmem_list_t *list);



#endif // WMEM_LIST_H
