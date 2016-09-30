#ifndef QPOPENROUTINEPCAP_H
#define QPOPENROUTINEPCAP_H

#include "qpopenroutine.h"
#include "qprfvfstat.h"
class QPOpenRoutinePCAP : public QPOpenRoutine
{
public:
    QPOpenRoutinePCAP();
    wtap_open_return_val openRoutine(QPRFVFAccessor *rfvfAccessor);
    bool readPacket(QPRFVFAccessor *, int *err, char **err_info, qint64 *data_offset);

};

#endif // QPOPENROUTINEPCAP_H
