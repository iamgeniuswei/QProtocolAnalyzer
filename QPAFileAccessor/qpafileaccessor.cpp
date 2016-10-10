#include "qpafileaccessor.h"
#include "qpavfmediator.h"
#include "wtap_pkthdr.h"
#include "qprfvfdefine.h"
#include "qparawfilereader.h"
#include <QDebug>
#include "wtap.h"
#include "frame_data.h"
#include "frame_data_sequence.h"
#include <iostream>
#include "epan_dissect.h"
#include "packet.h"
#include "frame_tvbuff.h"
void QPFileAccessor::cf_init(const QString& _filename, int _open_type, bool _is_tempfile)
{
    phdr = std::make_shared<wtap_pkthdr>();
    if(phdr)
        phdr->ft_specific_data.ws_buffer_init(0);
    buf = std::make_shared<Buffer>();
    if(buf)
        buf->ws_buffer_init(1500);
    state = FILE_READ_IN_PROGRESS;
    f_datalen = 0;
    filename = _filename.toStdString();
    is_tempfile = _is_tempfile;
    open_type = _open_type;
    if(wth)
    {
        cd_t = wth->file_type_subtype;
        snap = wth->snapshot_length;
    }
    if(0 == snap)
    {
        has_snap = false;
        snap = WTAP_MAX_PACKET_SIZE;
    }
    else {
        has_snap = true;
    }
    frames = std::make_shared<frame_data_sequence>();
}

int QPFileAccessor::read_packet(dfilter_t *dfcode, epan_dissect_t *edt, column_info *cinfo, gint64 offset)
{
    int row = -1;
    std:shared_ptr<wtap_pkthdr> phdr = wth->phdrPtr();
    const guint8 *buf = wth->wtap_buf_ptr();
    std::shared_ptr<frame_data> fdlocal = std::make_shared<frame_data>();
    quint32 framenum = count + 1;
    fdlocal->frame_data_init(framenum, phdr, offset, cum_bytes);

    dissect_record(nullptr, cd_t, phdr, frame_tvbuff_new(fdlocal, buf), fdlocal, NULL);

    if (rfcode) {
//      epan_dissect_t rf_edt;

//      epan_dissect_init(&rf_edt, cf->epan, TRUE, FALSE);
//      epan_dissect_prime_dfilter(&rf_edt, cf->rfcode);
//      epan_dissect_run(&rf_edt, cf->cd_t, phdr, frame_tvbuff_new(&fdlocal, buf), &fdlocal, NULL);
//      passed = dfilter_apply_edt(cf->rfcode, &rf_edt);
//      epan_dissect_cleanup(&rf_edt);
    }


//    if(passed)
//    {
//        fdata = frame_data_sequence_add(cf->frames, &fdlocal);
//        cf->count++;
//        cf->f_datalen = offset + fdlocal.cap_len;
//    }

    return row;


}

QPFileAccessor::QPFileAccessor()
{

}

QPFileAccessor::~QPFileAccessor()
{

}

cf_status_t QPFileAccessor::cf_open(const QString &fname, unsigned int type, bool is_tempfile, int *err)
{
    if(nullptr == wth)
    {
        wth = std::make_shared<QPAVFMediator>();
        if(nullptr == wth)
            return CF_ERROR;
    }
    if(!wth->openOfflineRawFile(fname, type, true))
        return CF_ERROR;

    cf_init(fname, type, is_tempfile);

    //FIXME:
//    packet_list_queue_draw();
//    cf_callback_invoke(cf_cb_file_opened, cf);

    //FIXME:
//    if (cf->cd_t == WTAP_FILE_TYPE_SUBTYPE_BER) {
//      /* tell the BER dissector the file name */
//      ber_set_filename(cf->filename);
//    }
    //FIXME:
//    wtap_set_cb_new_ipv4(cf->wth, add_ipv4_name);
//    wtap_set_cb_new_ipv6(cf->wth, (wtap_new_ipv6_callback_t) add_ipv6_name);

    return CF_OK;


}

cf_read_status_t QPFileAccessor::cf_read(gboolean from_save)
{
    if(nullptr == wth)
        return CF_READ_ERROR;
    qint64 data_offset = 0;
    int count = 0;
    qint64 size = wth->size();
    while (wth->readRawFile(nullptr, nullptr, &data_offset))
    {
        //FIXME:
        count++;
        std::cout << count << std::endl;
        qDebug() << wth->readerPtr()->getRawPos();
        read_packet(nullptr, nullptr, nullptr, data_offset);
    }

}
