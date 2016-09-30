#include "qprfvfaccessor.h"
#include "qprfreader.h"
#include "qpopenroutinepcap.h"
#include "qprfvfdefine.h"
QPRFVFAccessor::QPRFVFAccessor():
    reader(nullptr),wth(nullptr)
{
    wth = new (std::nothrow) wtap;
}

bool QPRFVFAccessor::openOfflineRF(const QString &filename, unsigned int type, bool do_random)
{
    if(nullptr == reader)
    {
        reader = new QPRFReader;
        //FIXME:
        if(nullptr == reader)
            return false;
        if(!reader->openRawFile(filename))
            return false;
    }
    size = reader->rfSize;
    if(nullptr == wth)
        return false;
    /* initialization */
    wth->file_encap = WTAP_ENCAP_UNKNOWN;
    wth->subtype_sequential_close = NULL;
    wth->subtype_close = NULL;
    wth->file_tsprec = WTAP_TSPREC_USEC;
    wth->priv = NULL;
    wth->wslua_data = NULL;

    //FIXME:
    /* Initialize the array containing a list of interfaces. pcapng_open and
         * erf_open needs this (and libpcap_open for ERF encapsulation types).
         * Always initing it here saves checking for a NULL ptr later. */
//    wth->interface_data = g_array_new(FALSE, FALSE, sizeof(wtapng_if_descr_t));

//    if (wth->random_fh) {
//        wth->fast_seek = g_ptr_array_new();

//        file_set_random_access(wth->fh, FALSE, wth->fast_seek);
//        file_set_random_access(wth->random_fh, TRUE, wth->fast_seek);
//    }


    QPOpenRoutine *open = new QPOpenRoutinePCAP;
    int result = 0;
    result = open->openRoutine(this);
    if(result == WTAP_OPEN_MINE)
    {
        wth->frame_buffer = (struct Buffer *)g_malloc(sizeof(struct Buffer));
        ws_buffer_init(wth->frame_buffer, 1500);
        return true;
    }
    return false;





}

quint32 QPRFVFAccessor::wtapReadBytes(void *buf, quint32 count)
{
    int bytes_read = 0;
    if(nullptr != reader)
        bytes_read = reader->readBytesToBuffer(buf, count);
    return bytes_read;
}

qint64 QPRFVFAccessor::getSize() const
{
    return size;
}

QPRFReader *QPRFVFAccessor::getReader() const
{
    return reader;
}

wtap *QPRFVFAccessor::getWth() const
{
    return wth;
}

bool QPRFVFAccessor::readRawFile(int *err, char **err_info, qint64 *data_offset)
{
    if(wth == nullptr)
    {
        return false;
    }

}
