#include "tvbuff.h"
tvbuff_t *tvb_new(const tvb_ops *ops)
{
    tvbuff_t *tvb;
    gsize     size = ops->tvb_size;

    g_assert(size >= sizeof(*tvb));

    tvb = (tvbuff_t *) g_slice_alloc(size);

    tvb->next	     = NULL;
    tvb->ops	     = ops;
    tvb->initialized     = FALSE;
    tvb->flags	     = 0;
    tvb->length	     = 0;
    tvb->reported_length = 0;
    tvb->real_data	     = NULL;
    tvb->raw_offset	     = -1;
    tvb->ds_tvb	     = NULL;

    return tvb;
}
