#include "qpfileaccessor.h"
#include "qpavfmediator.h"
#include "wtap_pkthdr.h"
#include "qprfvfdefine.h"
#include "qparawfilereader.h"
#include <QDebug>
#include "wtap.h"
#include "frame_data.h"
#include "frame_data_sequence.h"
#include <iostream>
void QPFileAccessor::cf_init()
{
    cf = new (std::nothrow) capture_file;
    if(nullptr != cf)
    {
        memset(cf, 0, sizeof(cf));
        //FIXME:
        cf->wth = rfvfAccessor->getWth();
        wtap_phdr_init(&cf->phdr);
        ws_buffer_init(&cf->buf, 1500);
        cf->state = FILE_READ_IN_PROGRESS;
        cf->f_datalen = 0;
//        cf->filename = (gchar*)fname.constData();
//        cf->is_tempfile = is_tempfile;
        cf->unsaved_changes = false;
        cf->computed_elapsed = 0;
//        cf->open_type = type;
        cf->linktypes = g_array_sized_new(FALSE, FALSE, (guint)sizeof(int), 1);
        cf->count = 0;
        cf->packet_comment_count = 0;
        cf->displayed_count = 0;
        cf->marked_count = 0;
        cf->ignored_count = 0;
        cf->ref_time_count = 0;
        cf->drops_known = FALSE;
        cf->drops     = 0;
        //FIXME:
    //    cf->snap      = wtap_snapshot_length(cf->wth);
        if (cf->snap == 0) {
          /* Snapshot length not known. */
          cf->has_snap = FALSE;
          cf->snap = WTAP_MAX_PACKET_SIZE;
        } else
          cf->has_snap = TRUE;

        /* Allocate a frame_data_sequence for the frames in this file */
        //FIXME:
    //    cf->frames = new_frame_data_sequence();
        nstime_set_zero(&cf->elapsed_time);
        cf->ref = NULL;
        cf->prev_dis = NULL;
        cf->prev_cap = NULL;
        cf->cum_bytes = 0;


    }
}

int QPFileAccessor::read_packet(dfilter_t *dfcode, epan_dissect_t *edt, column_info *cinfo, gint64 offset)
{
    int row = -1;
    wtap_pkthdr *phdr = wtap_phdr(cf->wth);
    const guint8 *buf = wtap_buf_ptr(cf->wth);
    frame_data fdlocal;
    quint32 framenum;
    frame_data *fdata;
    framenum = cf->count + 1;
    frame_data_init(&fdlocal, framenum, phdr, offset, cf->cum_bytes);
    bool passed = true;
    if(passed)
    {
        fdata = frame_data_sequence_add(cf->frames, &fdlocal);
        cf->count++;
        cf->f_datalen = offset + fdlocal.cap_len;
    }

    return row;


}

QPFileAccessor::QPFileAccessor():rfvfAccessor(nullptr),cf(nullptr)
{

}

cf_status_t QPFileAccessor::cf_open(/*capture_file *cf, */const QString &fname, unsigned int type, gboolean is_tempfile, int *err)
{
    if(nullptr == rfvfAccessor)
    {
        rfvfAccessor = new (std::nothrow) QPAVFMediator;
        if(nullptr == rfvfAccessor)
            return CF_ERROR;
    }
    if(!rfvfAccessor->openOfflineRawFile(fname, type, true))
        return CF_ERROR;

    cf_init();
    if(nullptr == cf)
        return CF_ERROR;

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
    if(nullptr == rfvfAccessor)
        return CF_READ_ERROR;
    qint64 data_offset = 0;
    int count = 0;
    qint64 size = rfvfAccessor->size();
    while (rfvfAccessor->readRawFile(nullptr, nullptr, &data_offset))
    {
        //FIXME:
        count++;
        std::cout << count << std::endl;
        qDebug() << rfvfAccessor->getReader()->getRawPos();
//        read_packet(nullptr, nullptr, nullptr, data_offset);
    }

}
