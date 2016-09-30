#include "qpopenroutinepcap.h"
#include "qprfvfaccessor.h"
#include "qpdefinepcap.h"
#include <QDebug>
#include "qprfreader.h"

QPOpenRoutinePCAP::QPOpenRoutinePCAP()
{
    setName("Wireshark/tcpdump/... - pcap");
    setType(OPEN_INFO_MAGIC);
    setExtensions("pcap");
}

wtap_open_return_val QPOpenRoutinePCAP::openRoutine(QPRFVFAccessor *rfvfAccessor)
{
    if(nullptr == rfvfAccessor)
        return WTAP_OPEN_ERROR;
    quint32 magic = 0;

    //FIXME:
    qDebug() << rfvfAccessor->wtapReadBytes(&magic, sizeof (magic));
//    if(rfvfAccessor->wtapReadBytes(&magic, sizeof magic) < sizeof(magic))
//        return WTAP_OPEN_ERROR;
    switch (magic) {
    case PCAP_MAGIC:
//        return WTAP_OPEN_MINE;
        break;
    default:
        return WTAP_OPEN_ERROR;
    }

    struct pcap_hdr hdr;
    memset(&hdr, 0, sizeof hdr);
    if (!rfvfAccessor->wtapReadBytes(&hdr, sizeof hdr))
        return WTAP_OPEN_ERROR;
    return WTAP_OPEN_MINE;
}

bool QPOpenRoutinePCAP::readPacket(QPRFVFAccessor *wth, int *err, char **err_info, qint64 *data_offset)
{
    *data_offset = wth->getReader()->getRawPos();
    return readPacketData(wth);
}

bool QPOpenRoutinePCAP::readPacketData(QPRFVFAccessor *wth)
{
    struct pcaprec_ss990915_hdr hdr;
    quint32 packet_size;
    quint32 orig_size;
    int phdr_len = 0;
    libpcap_t *libpcap;

    if(!readPcapPacketHeader(wth, &hdr))
        return false;

    packet_size = hdr.hdr.incl_len;
    orig_size = hdr.hdr.orig_len;

    if(!wth->wtapReadBytes(wth->getWth()->frame_buffer, packet_size))
        return false;


}

bool QPOpenRoutinePCAP::readPcapPacketHeader(QPRFVFAccessor *wth, pcaprec_ss990915_hdr *hdr)
{
    int bytes_to_read;
    guint32 temp;
    libpcap_t *libpcap;
    bytes_to_read = sizeof(pcaprec_hdr);

//    switch (wth->fileTypeSubtype()) {

//    case WTAP_FILE_TYPE_SUBTYPE_PCAP:
//    case WTAP_FILE_TYPE_SUBTYPE_PCAP_AIX:
//    case WTAP_FILE_TYPE_SUBTYPE_PCAP_NSEC:
//        bytes_to_read = sizeof (struct pcaprec_hdr);
//        break;

//    case WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990417:
//    case WTAP_FILE_TYPE_SUBTYPE_PCAP_SS991029:
//        bytes_to_read = sizeof (struct pcaprec_modified_hdr);
//        break;

//    case WTAP_FILE_TYPE_SUBTYPE_PCAP_SS990915:
//        bytes_to_read = sizeof (struct pcaprec_ss990915_hdr);
//        break;

//    case WTAP_FILE_TYPE_SUBTYPE_PCAP_NOKIA:
//        bytes_to_read = sizeof (struct pcaprec_nokia_hdr);
//        break;

//    default:
//        g_assert_not_reached();
//        bytes_to_read = 0;
//    }
    if(!wth->wtapReadBytes(hdr, bytes_to_read))
        return false;
    //FIXME:
//    libpcap = (libpcap_t  *)(wth->getPriv());
//    if(libpcap->byte_swapped)
//    {
//        /* Byte-swap the record header fields. */
//        hdr->hdr.ts_sec = GUINT32_SWAP_LE_BE(hdr->hdr.ts_sec);
//        hdr->hdr.ts_usec = GUINT32_SWAP_LE_BE(hdr->hdr.ts_usec);
//        hdr->hdr.incl_len = GUINT32_SWAP_LE_BE(hdr->hdr.incl_len);
//        hdr->hdr.orig_len = GUINT32_SWAP_LE_BE(hdr->hdr.orig_len);
//    }
//    switch (libpcap->lengths_swapped) {
//    case NOT_SWAPPED:

//        break;
//    case MAYBE_SWAPPED:
//        if(hdr->hdr.incl_len  <= hdr->hdr.orig_len)
//        {
//            break;
//        }
//    case SWAPPED:
//        temp = hdr->hdr.orig_len;
//        hdr->hdr.orig_len = hdr->hdr.incl_len;
//        hdr->hdr.incl_len = temp;
//        break;
//    default:
//        break;
//    }
    return true;
}

