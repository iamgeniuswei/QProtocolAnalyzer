#include "frame_tvbuff.h"
#include "wtap.h"
struct tvb_frame {
    struct tvbuff tvb;

    Buffer *buf;         /* Packet data */

    wtap *wth;           /**< Wiretap session */
    gint64 file_off;     /**< File offset */

    guint offset;
};
static const struct tvb_ops tvb_frame_ops = {
    sizeof(struct tvb_frame), /* size */

//    frame_free,           /* free */
//    frame_offset,         /* offset */
//    frame_get_ptr,        /* get_ptr */
//    frame_memcpy,         /* memcpy */
//    frame_find_guint8,    /* find_guint8 */
//    frame_pbrk_guint8,    /* pbrk_guint8 */
//    frame_clone,          /* clone */
};

tvbuff_t *frame_tvbuff_new(const frame_data *fd, const guint8 *buf)
{
    struct tvb_frame *frame_tvb;
    tvbuff_t *tvb;

    tvb = tvb_new(&tvb_frame_ops);

    /*
     * XXX - currently, the length arguments in
     * tvbuff structure are signed, but the captured
     * and reported length values are unsigned; this means
     * that length values > 2^31 - 1 will appear as
     * negative lengths
     *
     * Captured length values that large will already
     * have been filtered out by the Wiretap modules
     * (the file will be reported as corrupted), to
     * avoid trying to allocate large chunks of data.
     *
     * Reported length values will not have been
     * filtered out, and should not be filtered out,
     * as those lengths are not necessarily invalid.
     *
     * For now, we clip the reported length at G_MAXINT
     *
     * (XXX, is this still a problem?) There was an exception when we call
     * tvb_new_real_data() now there's no one
     */

    tvb->real_data       = buf;
    tvb->length          = fd->cap_len;
    tvb->reported_length = fd->pkt_len > G_MAXINT ? G_MAXINT : fd->pkt_len;
    tvb->initialized     = TRUE;

    /*
     * This is the top-level real tvbuff for this data source,
     * so its data source tvbuff is itself.
     */
    tvb->ds_tvb = tvb;

    frame_tvb = (struct tvb_frame *) tvb;

//    /* XXX, wtap_can_seek() */
//    if (cfile.wth && cfile.wth->random_fh
//#ifdef WANT_PACKET_EDITOR
//        && fd->file_off != -1 /* generic clone for modified packets */
//#endif
//    ) {
//        frame_tvb->wth = cfile.wth;
//        frame_tvb->file_off = fd->file_off;
//        frame_tvb->offset = 0;
//    } else
//        frame_tvb->wth = NULL;

    frame_tvb->buf = NULL;

    return tvb;
}

tvbuff_t *frame_tvbuff_new_buffer(const frame_data *fd, Buffer *buf)
{

}

tvbuff_t *file_tvbuff_new(const frame_data *fd, const guint8 *buf)
{

}

tvbuff_t *file_tvbuff_new_buffer(const frame_data *fd, Buffer *buf)
{

}
