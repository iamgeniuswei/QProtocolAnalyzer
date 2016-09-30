#include "qpopenroutinepcap.h"
#include "qprfvfaccessor.h"
#include "qpdefinepcap.h"
#include <QDebug>

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
        return WTAP_OPEN_MINE;
        break;
    default:
        return WTAP_OPEN_ERROR;
    }
    return WTAP_OPEN_ERROR;
}

bool QPOpenRoutinePCAP::readPacket(QPRFVFAccessor *, int *err, char **err_info, qint64 *data_offset)
{

}

