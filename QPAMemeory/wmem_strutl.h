#ifndef WMEM_STRUTL_H
#define WMEM_STRUTL_H
#include <string.h>

#include <glib.h>
/** @addtogroup wmem
 *  @{
 *    @defgroup wmem-strutl String Utilities
 *
 *    A collection of utility function for operating on C strings with wmem.
 *
 *    @{
 */

extern
gchar *
wmem_strdup(wmem_allocator_t *allocator, const gchar *src)
G_GNUC_MALLOC;

extern
gchar *
wmem_strndup(wmem_allocator_t *allocator, const gchar *src, const size_t len)
G_GNUC_MALLOC;

extern
gchar *
wmem_strdup_printf(wmem_allocator_t *allocator, const gchar *fmt, ...)
G_GNUC_MALLOC G_GNUC_PRINTF(2, 3);

extern
gchar *
wmem_strdup_vprintf(wmem_allocator_t *allocator, const gchar *fmt, va_list ap)
G_GNUC_MALLOC;

extern
gchar *
wmem_strconcat(wmem_allocator_t *allocator, const gchar *first, ...)
G_GNUC_MALLOC G_GNUC_NULL_TERMINATED;

/**
 * Splits a string into a maximum of max_tokens pieces, using the given
 * delimiter. If max_tokens is reached, the remainder of string is appended
 * to the last token. Consecutive delimiters are treated as a single delimiter.
 */
extern
gchar **
wmem_strsplit(wmem_allocator_t *allocator, const gchar *src,
        const gchar *delimiter, int max_tokens);


/**
 * wmem_ascii_strdown:
 * Based on g_ascii_strdown
 * @param allocator  An enumeration of the different types of available allocators.
 * @param str a string.
 * @param len length of str in bytes, or -1 if str is nul-terminated.
 *
 * Converts all upper case ASCII letters to lower case ASCII letters.
 *
 * Return value: a newly-allocated string, with all the upper case
 *               characters in str converted to lower case, with
 *               semantics that exactly match g_ascii_tolower(). (Note
 *               that this is unlike the old g_strdown(), which modified
 *               the string in place.)
 **/
extern
gchar*
wmem_ascii_strdown(wmem_allocator_t *allocator, const gchar *str, gssize len);
/**   @}
 *  @} */


#endif // WMEM_STRUTL_H
