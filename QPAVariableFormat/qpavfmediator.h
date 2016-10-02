#ifndef QPRFFORMAT_H
#define QPRFFORMAT_H

#include "qprfformat_global.h"
#include <QPointer>
#include "wtap.h"


/*
 * this class encapsulate struct wtap
 * QPRFVFAccessor: QP Raw File Variable Formats Accessor.
 */
class QPARawFileReader;
class QPOpenRoutine;
class QPRFFORMATSHARED_EXPORT QPAVFMediator
{

public:
    QPAVFMediator();
    ~QPAVFMediator();
    bool openOfflineRawFile(const QString &filename, unsigned int type, bool do_random);
    bool readPacketByFormat(int *, char **, qint64 *);
    bool seekReadPacketByFormat(int *, char **, qint64 *);
    void closeByFormat();
    void sequentialCloseByFormat();


    bool readRawFile(int *err, char **err_info, qint64 *data_offset);


    quint32 wtapReadPacketBytes(Buffer *buf, quint32 count);

    quint32 wtapReadBytes(void *buf, quint32 count);

    qint64 size() const;
    qint64 curSeekPos() const;
    bool isCompressed() const;

    QPARawFileReader *getReader() const;

    wtap *getWth() const;


    quint32 getSnapshotLength() const;

    qint32 getRawFileSubType() const;

    qint32 getRawFileEncapsulation() const;

    qint32 getRawFileTSPrecision() const;

    Buffer *getFrame_buffer() const;

private:
    void init();

private:
    QPARawFileReader *reader;
    wtap *wth;
//    qint64 size;
    QPOpenRoutine *open;
    quint32 snapshotLength;
    qint32 rawFileSubType;
    qint32 rawFileEncapsulation;
    qint32 rawFileTSPrecision;
    Buffer *frame_buffer;
    wtap_pkthdr phdr;
    void *priv;
    void *wslua_data;
    GArray *interface_data;
};

#endif // QPRFFORMAT_H
