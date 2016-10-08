#ifndef WS_MEMPBRK_H
#define WS_MEMPBRK_H
#ifdef HAVE_SSE4_2
#include <emmintrin.h>
#endif

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

const guint8 *ws_mempbrk_portable_exec(const guint8* haystack, size_t haystacklen, const ws_mempbrk_pattern* pattern, guchar *found_needle);

#ifdef HAVE_SSE4_2
void ws_mempbrk_sse42_compile(ws_mempbrk_pattern* pattern, const gchar *needles);
const char *ws_mempbrk_sse42_exec(const char* haystack, size_t haystacklen, const ws_mempbrk_pattern* pattern, guchar *found_needle);
#endif
#endif // WS_MEMPBRK_H
