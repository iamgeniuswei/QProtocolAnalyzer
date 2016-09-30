#ifndef QPRFFORMAT_H
#define QPRFFORMAT_H

#include "qprfformat_global.h"
#include <QPointer>
#include "wtap.h"


/*
 * this class encapsulate struct wtap
 * QPRFVFAccessor: QP Raw File Variable Formats Accessor.
 */
class QPRFReader;

class QPRFFORMATSHARED_EXPORT QPRFVFAccessor
{

public:
    QPRFVFAccessor();
    bool openOfflineRF(const QString &filename, unsigned int type, bool do_random);
    bool readRawFile(int *err, char **err_info, qint64 *data_offset);
    quint32 wtapReadBytes(void *buf, quint32 count);

    qint64 getSize() const;

    QPRFReader *getReader() const;

    wtap *getWth() const;

private:
    QPRFReader *reader;
    wtap *wth;
    qint64 size;

};

#endif // QPRFFORMAT_H
