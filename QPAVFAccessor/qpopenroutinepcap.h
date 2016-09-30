#ifndef QPOPENROUTINEPCAP_H
#define QPOPENROUTINEPCAP_H

#include "qpopenroutine.h"
#include "qprfvfstat.h"
#include "qpdefinepcap.h"
class QPOpenRoutinePCAP : public QPOpenRoutine
{
public:
    QPOpenRoutinePCAP();
    wtap_open_return_val openRoutine(QPRFVFAccessor *rfvfAccessor);
    bool readPacket(QPRFVFAccessor *, int *err, char **err_info, qint64 *data_offset);
private:
    bool readPacketData(QPRFVFAccessor* wth);
    bool readPcapPacketHeader(QPRFVFAccessor* wth, pcaprec_ss990915_hdr *hdr);

};

#endif // QPOPENROUTINEPCAP_H
