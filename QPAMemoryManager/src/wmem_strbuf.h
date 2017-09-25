/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   wmem_strbuf.h
 * Author: lenovo
 *
 * Created on 2017年9月24日, 下午10:03
 */

#ifndef WMEM_STRBUF_H
#define WMEM_STRBUF_H
#include "wmem_allocator.h"
#include <glib-2.0/glib.h>
/** @addtogroup wmem
 *  @{
 *    @defgroup wmem-strbuf String Buffer
 *
 *    A string object implementation on top of wmem.
 *
 *    @{
 */

typedef struct _wmem_strbuf_t {
    wmem_allocator_t *allocator;

    gchar *str;

    gsize len;
    gsize alloc_len;
    gsize max_len;
}wmem_strbuf_t;



extern
wmem_strbuf_t *
wmem_strbuf_sized_new(wmem_allocator_t *allocator,
                      gsize alloc_len, gsize max_len)
G_GNUC_MALLOC;

#define wmem_strbuf_new_label(ALLOCATOR) \
    wmem_strbuf_sized_new((ALLOCATOR), 0, ITEM_LABEL_LENGTH)

extern
wmem_strbuf_t *
wmem_strbuf_new(wmem_allocator_t *allocator, const gchar *str)
G_GNUC_MALLOC;

extern
void
wmem_strbuf_append(wmem_strbuf_t *strbuf, const gchar *str);

extern
void
wmem_strbuf_append_printf(wmem_strbuf_t *strbuf, const gchar *format, ...)
G_GNUC_PRINTF(2, 3);

extern
void
wmem_strbuf_append_c(wmem_strbuf_t *strbuf, const gchar c);

extern
void
wmem_strbuf_append_unichar(wmem_strbuf_t *strbuf, const gunichar c);

extern
void
wmem_strbuf_truncate(wmem_strbuf_t *strbuf, const gsize len);

extern
const gchar *
wmem_strbuf_get_str(wmem_strbuf_t *strbuf);

extern
gsize
wmem_strbuf_get_len(wmem_strbuf_t *strbuf);

/** Truncates the allocated memory down to the minimal amount, frees the header
 *  structure, and returns a non-const pointer to the raw string. The
 *  wmem_strbuf_t structure cannot be used after this is called. Basically a
 *  destructor for when you still need the underlying C-string.
 */
extern
char *
wmem_strbuf_finalize(wmem_strbuf_t *strbuf);

/**   @}
 *  @} */


#endif /* WMEM_STRBUF_H */

