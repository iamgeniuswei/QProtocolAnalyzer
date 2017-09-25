/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_array.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午9:44
 */

#ifndef WMEM_ARRAY_H
#define WMEM_ARRAY_H
#include "wmem_allocator.h"
#include <glib-2.0/glib.h>
/** @addtogroup wmem
 *  @{
 *    @defgroup wmem-array Array
 *
 *    A resizable array implementation on top of wmem.
 *
 *    @{
 */

/* Holds a wmem-allocated array.
 *  elem_len is the size of each element
 *  elem_count is the number of used elements
 *  alloc_count is the length (in elems) of the raw buffer pointed to by buf,
 *      regardless of how many elems are used (the contents)
 */
typedef struct _wmem_array_t {
    wmem_allocator_t *allocator;

    guint8 *buf;

    gsize elem_size;

    guint elem_count;
    guint alloc_count;

    gboolean null_terminated;
}wmem_array_t;


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
wmem_array_set_null_terminator(wmem_array_t *array);

extern
void
wmem_array_bzero(wmem_array_t *array);

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

/**   @}
 *  @} */

#endif /* WMEM_ARRAY_H */

