#ifndef TVBUFF_H
#define TVBUFF_H
#include <glib.h>
/*
 * Tvbuff flags.
 */
#define TVBUFF_FRAGMENT		0x00000001	/* this is a fragment */
struct tvbuff;
typedef tvbuff tvbuff_t;

struct tvb_ops {
    gsize tvb_size;
    void (*tvb_free)(struct tvbuff *tvb);
    guint (*tvb_offset)(const struct tvbuff *tvb, guint counter);
    const guint8 *(*tvb_get_ptr)(struct tvbuff *tvb, guint abs_offset, guint abs_length);
    void *(*tvb_memcpy)(struct tvbuff *tvb, void *target, guint offset, guint length);

    gint (*tvb_find_guint8)(tvbuff_t *tvb, guint abs_offset, guint limit, guint8 needle);
    gint (*tvb_ws_mempbrk_pattern_guint8)(tvbuff_t *tvb, guint abs_offset, guint limit, /*const ws_mempbrk_pattern* pattern,*/ guchar *found_needle);

    tvbuff_t *(*tvb_clone)(tvbuff_t *tvb, guint abs_offset, guint abs_length);
};

struct tvbuff {
    /* Doubly linked list pointers */
    tvbuff_t                *next;

    /* Record-keeping */
    const struct tvb_ops   *ops;
    gboolean		initialized;
    guint			flags;
    struct tvbuff		*ds_tvb;  /**< data source top-level tvbuff */

    /** We're either a TVBUFF_REAL_DATA or a
     * TVBUFF_SUBSET that has a backing buffer that
     * has real_data != NULL, or a TVBUFF_COMPOSITE
     * which has flattened its data due to a call
     * to tvb_get_ptr().
     */
    const guint8		*real_data;

    /** Length of virtual buffer (and/or real_data). */
    guint			length;

    /** Reported length. */
    guint			reported_length;

    /* Offset from beginning of first TVBUFF_REAL. */
    gint			raw_offset;
};

extern tvbuff_t *tvb_new(const struct tvb_ops *ops);

#endif // TVBUFF_H
