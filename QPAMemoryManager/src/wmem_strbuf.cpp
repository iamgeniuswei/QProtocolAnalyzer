/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "wmem_strbuf.h"
#include <glib-2.0/glib.h>
#include "wmem_core.h"
#include <string.h>
#define DEFAULT_MINIMUM_LEN 16

/* _ROOM accounts for the null-terminator, _RAW_ROOM does not.
 * Some functions need one, some functions need the other. */
#define WMEM_STRBUF_ROOM(S) ((S)->alloc_len - (S)->len - 1)
#define WMEM_STRBUF_RAW_ROOM(S) ((S)->alloc_len - (S)->len)

wmem_strbuf_t *
wmem_strbuf_sized_new(wmem_allocator_t *allocator,
                      gsize alloc_len, gsize max_len)
{
    wmem_strbuf_t *strbuf;

    g_assert((max_len == 0) || (alloc_len <= max_len));

    strbuf = wmem_new(allocator, wmem_strbuf_t);

    strbuf->allocator = allocator;
    strbuf->len       = 0;
    strbuf->alloc_len = alloc_len ? alloc_len : DEFAULT_MINIMUM_LEN;
    strbuf->max_len   = max_len;

    strbuf->str    = (gchar *)wmem_alloc(strbuf->allocator, strbuf->alloc_len);
    strbuf->str[0] = '\0';

    return strbuf;
}

wmem_strbuf_t *
wmem_strbuf_new(wmem_allocator_t *allocator, const gchar *str)
{
    wmem_strbuf_t *strbuf;
    gsize          len, alloc_len;

    len       = str ? strlen(str) : 0;
    alloc_len = DEFAULT_MINIMUM_LEN;

    /* +1 for the null-terminator */
    while (alloc_len < (len + 1)) {
        alloc_len *= 2;
    }

    strbuf = wmem_strbuf_sized_new(allocator, alloc_len, 0);

    if (str && len > 0) {
        g_strlcpy(strbuf->str, str, alloc_len);
        strbuf->len = len;
    }

    return strbuf;
}

static inline void
wmem_strbuf_grow(wmem_strbuf_t *strbuf, const gsize to_add)
{
    gsize  new_alloc_len, new_len;

    /* short-circuit for efficiency if we have room already; greatly speeds up
     * repeated calls to wmem_strbuf_append_c and others which grow a little bit
     * at a time.
     */
    if (WMEM_STRBUF_ROOM(strbuf) >= to_add) {
        return;
    }

    new_alloc_len = strbuf->alloc_len;
    new_len = strbuf->len + to_add;

    /* +1 for the null-terminator */
    while (new_alloc_len < (new_len + 1)) {
        new_alloc_len *= 2;
    }

    /* max length only enforced if not 0 */
    if (strbuf->max_len && new_alloc_len > strbuf->max_len) {
        new_alloc_len = strbuf->max_len;
    }

    if (new_alloc_len == strbuf->alloc_len) {
        return;
    }

    strbuf->str = (gchar *)wmem_realloc(strbuf->allocator, strbuf->str, new_alloc_len);

    strbuf->alloc_len = new_alloc_len;
}

void
wmem_strbuf_append(wmem_strbuf_t *strbuf, const gchar *str)
{
    gsize append_len;

    if (!str || str[0] == '\0') {
        return;
    }

    append_len = strlen(str);

    wmem_strbuf_grow(strbuf, append_len);

    g_strlcpy(&strbuf->str[strbuf->len], str, WMEM_STRBUF_RAW_ROOM(strbuf));

    strbuf->len = MIN(strbuf->len + append_len, strbuf->alloc_len - 1);
}

#ifndef _WIN32
static void
wmem_strbuf_append_vprintf(wmem_strbuf_t *strbuf, const gchar *fmt, va_list ap)
{
    va_list ap2;
    gsize append_len;

    G_VA_COPY(ap2, ap);

    append_len = g_printf_string_upper_bound(fmt, ap);

    /* -1 because g_printf_string_upper_bound counts the null-terminator, but
     * wmem_strbuf_grow does not */
    wmem_strbuf_grow(strbuf, append_len - 1);

    append_len = g_vsnprintf(&strbuf->str[strbuf->len],
            (gulong) WMEM_STRBUF_RAW_ROOM(strbuf),
            fmt, ap2);

    va_end(ap2);

    strbuf->len = MIN(strbuf->len + append_len, strbuf->alloc_len - 1);
}
#else /* _WIN32 */
/*
 * GLib's v*printf routines are surprisingly slow on Windows, at least with
 * GLib 2.40.0. This appears to be due to GLib using the gnulib version of
 * vasnprintf when compiled under MinGW. If GLib ever ends up using the
 * native Windows v*printf routines this can be removed.
 */
static void
wmem_strbuf_append_vprintf(wmem_strbuf_t *strbuf, const gchar *fmt, va_list ap)
{
    va_list ap2;
    gsize append_len;
    gsize printed_len;

    G_VA_COPY(ap2, ap);

    append_len = _vscprintf(fmt, ap);

    wmem_strbuf_grow(strbuf, append_len);

    printed_len = vsnprintf_s(&strbuf->str[strbuf->len],
            (gulong) WMEM_STRBUF_RAW_ROOM(strbuf),
            _TRUNCATE,
            fmt, ap2);
    if (printed_len > -1) append_len = printed_len;

    va_end(ap2);

    strbuf->len = MIN(strbuf->len + append_len, strbuf->alloc_len - 1);
}
#endif /* _WIN32 */

void
wmem_strbuf_append_printf(wmem_strbuf_t *strbuf, const gchar *format, ...)
{
    va_list ap;

    va_start(ap, format);
    wmem_strbuf_append_vprintf(strbuf, format, ap);
    va_end(ap);
}

void
wmem_strbuf_append_c(wmem_strbuf_t *strbuf, const gchar c)
{
    wmem_strbuf_grow(strbuf, 1);

    /* one for the char, one for the null-terminator */
    if (WMEM_STRBUF_ROOM(strbuf) >= 1) {
        strbuf->str[strbuf->len] = c;
        strbuf->len++;
        strbuf->str[strbuf->len] = '\0';
    }
}

void
wmem_strbuf_append_unichar(wmem_strbuf_t *strbuf, const gunichar c)
{
    gchar buf[6];
    gsize charlen;

    charlen = g_unichar_to_utf8(c, buf);

    wmem_strbuf_grow(strbuf, charlen);

    if (WMEM_STRBUF_ROOM(strbuf) >= charlen) {
        memcpy(&strbuf->str[strbuf->len], buf, charlen);
        strbuf->len += charlen;
        strbuf->str[strbuf->len] = '\0';
    }
}

void
wmem_strbuf_truncate(wmem_strbuf_t *strbuf, const gsize len)
{
    if (len >= strbuf->len) {
        return;
    }

    strbuf->str[len] = '\0';
    strbuf->len = len;
}

const gchar *
wmem_strbuf_get_str(wmem_strbuf_t *strbuf)
{
    return strbuf->str;
}

gsize
wmem_strbuf_get_len(wmem_strbuf_t *strbuf)
{
    return strbuf->len;
}

/* Truncates the allocated memory down to the minimal amount, frees the header
 * structure, and returns a non-const pointer to the raw string. The
 * wmem_strbuf_t structure cannot be used after this is called.
 */
char *
wmem_strbuf_finalize(wmem_strbuf_t *strbuf)
{
    char *ret;

    ret = (char *)wmem_realloc(strbuf->allocator, strbuf->str, strbuf->len+1);

    wmem_free(strbuf->allocator, strbuf);

    return ret;
}

