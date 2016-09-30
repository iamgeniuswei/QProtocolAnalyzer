#ifndef QPRFREADER_H
#define QPRFREADER_H
#include <fstream>
#include <QObject>
using namespace std;
/*
 * encapsulate wtap_reader
 * file_wrappers.h/.c
 */
class QFileInfo;
class QPRFVFAccessor;
class QPRFReader
{
public:
    QPRFReader();
    ~QPRFReader();
    bool openRawFile(const QString &filename);
    quint32 readBytesToBuffer(void *buf, quint32 bytes);


    qint64 getRawPos() const;

private:
    QFileInfo *rfInfo;
    qint64 rfSize;
    fstream fd;
    qint64 rawPos;
    friend class QPRFVFAccessor;
};

#endif // QPRFREADER_H
