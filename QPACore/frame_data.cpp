#include "frame_data.h"
#include "wtap_pkthdr.h"
#include "qprfvfdefine.h"
void frame_data_init(frame_data *fdata, guint32 num, const wtap_pkthdr *phdr, gint64 offset, guint32 cum_bytes)
{
    if(nullptr == fdata)
        return;
    fdata->pfd = NULL;
    fdata->num = num;
    fdata->pkt_len = phdr->len;
    fdata->cum_bytes = cum_bytes + phdr->len;
    fdata->cap_len = phdr->caplen;
    fdata->file_off = offset;
    fdata->subnum = 0;
    /* To save some memory, we coerce it into a gint16 */
    g_assert(phdr->pkt_encap <= G_MAXINT16);
    fdata->lnk_t = (gint16) phdr->pkt_encap;
    fdata->flags.passed_dfilter = 0;
    fdata->flags.dependent_of_displayed = 0;
    fdata->flags.encoding = PACKET_CHAR_ENC_CHAR_ASCII;
    fdata->flags.visited = 0;
    fdata->flags.marked = 0;
    fdata->flags.ref_time = 0;
    fdata->flags.ignored = 0;
    fdata->flags.has_ts = (phdr->presence_flags & WTAP_HAS_TS) ? 1 : 0;
    fdata->flags.has_phdr_comment = (phdr->opt_comment != NULL);
    fdata->flags.has_user_comment = 0;
    fdata->tsprec = (gint16)phdr->pkt_tsprec;
    fdata->color_filter = NULL;
    fdata->abs_ts.secs = phdr->ts.secs;
    fdata->abs_ts.nsecs = phdr->ts.nsecs;
    fdata->shift_offset.secs = 0;
    fdata->shift_offset.nsecs = 0;
    fdata->frame_ref_num = 0;
    fdata->prev_dis_num = 0;


}
