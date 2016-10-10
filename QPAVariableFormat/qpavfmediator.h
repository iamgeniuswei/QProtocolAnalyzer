#ifndef QPRFFORMAT_H
#define QPRFFORMAT_H
#include "qprfformat_global.h"
#include <memory>
#include <QPointer>
#include "wtap.h"


/*
 * this class encapsulate struct wtap
 * QPRFVFAccessor: QP Raw File Variable Formats Accessor.
 */
struct wtap;
class QPARawFileReader;
class QPOpenRoutine;
class QPRFFORMATSHARED_EXPORT QPAVFMediator
{
    friend class QPFileAccessor;
public:
    QPAVFMediator();
    ~QPAVFMediator();
    bool openOfflineRawFile(const QString &filename, unsigned int type, bool do_random);
    bool readPacketByFormat(int *, char **, qint64 *);
    bool seekReadPacketByFormat(int *, char **, qint64 *);
    void closeByFormat();
    void sequentialCloseByFormat();


    bool readRawFile(int *err, char **err_info, qint64 *data_offset);


    quint32 wtapReadPacketBytes(std::shared_ptr<Buffer> buf, quint32 count);

    quint32 wtapReadBytes(void *buf, quint32 count);

    qint64 size() const;
    qint64 curSeekPos() const;
    bool isCompressed() const;

    std::shared_ptr<QPARawFileReader> readerPtr() const;



    std::shared_ptr<Buffer> frame_buffer_ptr() const;

public:
    std::shared_ptr<wtap_pkthdr> phdrPtr() const;
    quint8* wtap_buf_ptr() const;

private:
    void init();

private:
    std::shared_ptr<QPARawFileReader> reader;
    std::shared_ptr<QPOpenRoutine> open;
    qint32 file_type_subtype;
    quint32 snapshot_length;
    std::shared_ptr<Buffer> frame_buffer;
    std::shared_ptr<wtap_pkthdr> phdr;
    wtapng_section_s shb_hdr;
    std::vector<std::shared_ptr<void>> interface_data;
    std::shared_ptr<wtapng_name_res_t> nrb_hdr;
    std::shared_ptr<void> priv;
    std::shared_ptr<void> wslua_data;
    qint32 file_encap;
    qint32 file_tsprec;
};
#endif // QPRFFORMAT_H
