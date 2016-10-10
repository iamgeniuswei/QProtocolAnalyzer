#include "frame_data.h"
#include "wtap_pkthdr.h"
#include "qprfvfdefine.h"
frame_data::frame_data()
{}

void frame_data::frame_data_init(quint32 _num, const std::shared_ptr<wtap_pkthdr> _phdr, qint64 _offset, quint32 _cum_bytes)
{
    num = _num;
    if(_phdr)
    {
        pkt_len = _phdr->len;
        cap_len = _phdr->len;
        lnk_t = _phdr->pkt_encap;
        has_ts = (_phdr->presence_flags & WTAP_HAS_TS) ? 1 : 0;
        has_phdr_comment = (_phdr->opt_comment != nullptr);
        tsprec = _phdr->pkt_tsprec;
        //FIXME:
//        abs_ts.secs = _phdr->ts.secs;
//        abs_ts.nsecs = _phdr->ts.nsecs;
//        shift_offset.secs = 0;
//        shift_offset.nsecs = 0;
    }
    cum_bytes = _cum_bytes + pkt_len;
    file_off = _offset;
}
