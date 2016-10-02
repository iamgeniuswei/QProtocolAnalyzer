#include "qpavfmediator.h"
#include "qparawfilereader.h"
#include "qpopenroutinepcap.h"
#include "qprfvfdefine.h"
QPAVFMediator::QPAVFMediator():
    reader(nullptr),wth(nullptr),open(nullptr),\
    priv(nullptr), wslua_data(nullptr)
{
    wth = new (std::nothrow) wtap;
}

QPAVFMediator::~QPAVFMediator()
{

}


bool QPAVFMediator::openOfflineRawFile(const QString &filename, unsigned int type, bool do_random)
{
    if(nullptr == reader)
    {
        reader = new QPARawFileReader;
        //FIXME:
        if(nullptr == reader)
            return false;
        if(!reader->openRawFile(filename))
            return false;
    }
//    size = reader->rfSize;
    if(nullptr == wth)
        return false;
    /* initialization */
    init();
//    wth->file_encap = WTAP_ENCAP_UNKNOWN;
//    wth->subtype_sequential_close = NULL;
//    wth->subtype_close = NULL;
//    wth->file_tsprec = WTAP_TSPREC_USEC;
//    wth->priv = NULL;
//    wth->wslua_data = NULL;

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


    open = new QPOpenRoutinePCAP;
    int result = 0;
    result = open->openRoutine(this);
    if(result == WTAP_OPEN_MINE)
    {
        frame_buffer = (struct Buffer *)g_malloc0(sizeof(struct Buffer));
        ws_buffer_init(frame_buffer, 1500);
        return true;
    }
    return false;





}

quint32 QPAVFMediator:: wtapReadBytes(void *buf, quint32 count)
{


    int bytes_read = 0;
    if(nullptr != reader)
        bytes_read = reader->readBytesToBuffer(buf, count);
    return bytes_read;
}

qint64 QPAVFMediator::size() const
{
    if(reader)
        return reader->rfSize;
}

qint64 QPAVFMediator::curSeekPos() const
{
    if(reader)
        return reader->rawPos;
}

bool QPAVFMediator::isCompressed() const
{
    //FIXME:
    return false;
}

QPARawFileReader *QPAVFMediator::getReader() const
{
    return reader;
}

wtap *QPAVFMediator::getWth() const
{
    return wth;
}

quint32 QPAVFMediator::getSnapshotLength() const
{
    return snapshotLength;
}

qint32 QPAVFMediator::getRawFileSubType() const
{
    return rawFileSubType;
}

qint32 QPAVFMediator::getRawFileEncapsulation() const
{
    return rawFileEncapsulation;
}

qint32 QPAVFMediator::getRawFileTSPrecision() const
{
    return rawFileTSPrecision;
}

void QPAVFMediator::init()
{
    rawFileEncapsulation = WTAP_ENCAP_UNKNOWN;
    rawFileTSPrecision = WTAP_TSPREC_USEC;
    interface_data = g_array_new(false, false, sizeof(wtapng_if_descr_t));
}

Buffer *QPAVFMediator::getFrame_buffer() const
{
    return frame_buffer;
}


bool QPAVFMediator::readRawFile(int *err, char **err_info, qint64 *data_offset)
{
    phdr.pkt_encap = rawFileEncapsulation;
    phdr.pkt_tsprec = rawFileTSPrecision;

    if(wth == nullptr)
    {
        return false;
    }
    if(!readPacketByFormat(err, err_info, data_offset))
    {
        return false;
    }
    return true;

}

bool QPAVFMediator::readPacketByFormat(int *err, char **err_info, qint64 *data_offset)
{
    return open->readPacket(this, err, err_info, data_offset);
}

bool QPAVFMediator::seekReadPacketByFormat(int *, char **, qint64 *)
{
    return true;
}

void QPAVFMediator::closeByFormat()
{

}

void QPAVFMediator::sequentialCloseByFormat()
{

}

quint32 QPAVFMediator::wtapReadPacketBytes(Buffer *buf, quint32 count)
{
    ws_buffer_assure_space(buf, count);
    return wtapReadBytes(buf->data, count);
}
