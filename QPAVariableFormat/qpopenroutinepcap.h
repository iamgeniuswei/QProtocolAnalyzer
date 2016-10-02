#ifndef QPOPENROUTINEPCAP_H
#define QPOPENROUTINEPCAP_H

#include "qpopenroutine.h"
#include "qprfvfstat.h"
#include "qpdefinepcap.h"
class QPOpenRoutinePCAP : public QPOpenRoutine
{
public:
    QPOpenRoutinePCAP();
    wtap_open_return_val openRoutine(QPAVFMediator *rfvfAccessor);
    bool readPacket(QPAVFMediator *, int *err, char **err_info, qint64 *data_offset);
private:
    bool readPacketData(QPAVFMediator* wth);
    bool libpcapReadHeader(QPAVFMediator* wth, pcaprec_ss990915_hdr *hdr);

};

#endif // QPOPENROUTINEPCAP_H
