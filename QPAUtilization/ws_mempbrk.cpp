/* see bug 10798: there is a bug in the compiler the buildbots use for Mac OSX
   and SSE4.2, so we're not going to use SSE4.2 with Mac OSX right now, for
   older Mac OSX compilers.
 */
#ifdef __APPLE__
#if defined(__clang__) && (__clang_major__ >= 6)
/* allow HAVE_SSE4_2 to be used for clang 6.0+ case because we know it works */
#else
/* don't allow it otherwise, for Mac OSX */
#undef HAVE_SSE4_2
#endif
#endif

#include <glib.h>
#include "ws_mempbrk.h"

void
ws_mempbrk_compile(ws_mempbrk_pattern* pattern, const gchar *needles)
{
    const gchar *n = needles;
    while (*n) {
        pattern->patt[(int)*n] = 1;
        n++;
    }

#ifdef HAVE_SSE4_2
    ws_mempbrk_sse42_compile(pattern, needles);
#endif
}


const guint8 *
ws_mempbrk_portable_exec(const guint8* haystack, size_t haystacklen, const ws_mempbrk_pattern* pattern, guchar *found_needle)
{
    const guint8 *haystack_end = haystack + haystacklen;

    while (haystack < haystack_end) {
        if (pattern->patt[*haystack]) {
            if (found_needle)
                *found_needle = *haystack;
            return haystack;
        }
        haystack++;
    }

    return NULL;
}


extern const guint8 *
ws_mempbrk_exec(const guint8* haystack, size_t haystacklen, const ws_mempbrk_pattern* pattern, guchar *found_needle)
{
#ifdef HAVE_SSE4_2
    if (haystacklen >= 16 && pattern->use_sse42)
        return ws_mempbrk_sse42_exec(haystack, haystacklen, pattern, found_needle);
#endif

    return ws_mempbrk_portable_exec(haystack, haystacklen, pattern, found_needle);
}
