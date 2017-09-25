/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_list.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午9:52
 */

#ifndef WMEM_LIST_H
#define WMEM_LIST_H
#include <glib-2.0/glib.h>
#include "wmem_allocator.h"
/** @addtogroup wmem
 *  @{
 *    @defgroup wmem-list Doubly-Linked List
 *
 *    A doubly-linked list implementation on top of wmem.
 *
 *    @{
 */
typedef struct _wmem_list_frame_t {
    struct _wmem_list_frame_t *next, *prev;
    void *data;
}wmem_list_frame_t;
typedef struct _wmem_list_t {
    guint count;
    wmem_list_frame_t  *head, *tail;
    wmem_allocator_t   *allocator;
}wmem_list_t;




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

/*
 * Linear search, search is O(n)
 */
extern
wmem_list_frame_t *
wmem_list_find(wmem_list_t *list, const void *data);

extern
wmem_list_frame_t *
wmem_list_find_custom(wmem_list_t *list, const void *data, GCompareFunc func);

extern
void
wmem_list_prepend(wmem_list_t *list, void *data);

extern
void
wmem_list_append(wmem_list_t *list, void *data);

extern
void
wmem_list_insert_sorted(wmem_list_t *list, void* data, GCompareFunc func);


extern
wmem_list_t *
wmem_list_new(wmem_allocator_t *allocator)
G_GNUC_MALLOC;

extern
void
wmem_list_foreach(wmem_list_t *list, GFunc foreach_func, gpointer user_data);

extern
void
wmem_destroy_list(wmem_list_t *list);

/**   @}
 *  @} */

#endif /* WMEM_LIST_H */

