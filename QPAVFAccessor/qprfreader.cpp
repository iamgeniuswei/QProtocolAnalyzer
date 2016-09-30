#include "qprfreader.h"
#include <QFileInfo>
#include <QDebug>

QPRFReader::QPRFReader():rfSize(0)
{

}

QPRFReader::~QPRFReader()
{

}

bool QPRFReader::openRawFile(const QString &filename)
{
    rfInfo = new QFileInfo;
    if(nullptr != rfInfo)
    {
        rfInfo->setFile(filename);
        //FIXME:
        qDebug() << rfInfo->isFile() << rfInfo->isReadable();


        if(!rfInfo->isFile() && !rfInfo->isReadable())
            return false;
        rfSize = rfInfo->size();
        QByteArray ba = filename.toLocal8Bit();
        char* _filePath = ba.data();
        fd.open(_filePath, fstream::in | fstream::binary);
        if(!fd.is_open())
            return false;
        return true;
    }
    return false;
}

quint32 QPRFReader::readBytesToBuffer(void *buf, quint32 bytes)
{
    if((rawPos + bytes) >  rfSize)
        return 0;
    if(fd.is_open())
    {
        fd.seekg(rawPos);
        fd.read(reinterpret_cast<char*>(buf), bytes);
        int len = fd.gcount();
        rawPos += len;
        return len;
    }
    return 0;
}

qint64 QPRFReader::getRawPos() const
{
    return rawPos;
}
