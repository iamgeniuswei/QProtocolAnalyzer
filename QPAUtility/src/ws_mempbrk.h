/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ws_mempbrk.h
 * Author: lenovo
 *
 * Created on September 25, 2017, 4:57 PM
 */

#ifndef WS_MEMPBRK_H
#define WS_MEMPBRK_H
#include <emmintrin.h>
#include <glib-2.0/glib.h>
/** The pattern object used for ws_mempbrk_exec().
 */
typedef struct {
    gchar patt[256];
#ifdef HAVE_SSE4_2
    gboolean use_sse42;
    __m128i mask;
#endif
} ws_mempbrk_pattern;

/** Compile the pattern for the needles to find using ws_mempbrk_exec().
 */
extern void ws_mempbrk_compile(ws_mempbrk_pattern* pattern, const gchar *needles);

/** Scan for the needles specified by the compiled pattern.
 */
extern const guint8 *ws_mempbrk_exec(const guint8* haystack, size_t haystacklen, const ws_mempbrk_pattern* pattern, guchar *found_needle);

#endif /* WS_MEMPBRK_H */

