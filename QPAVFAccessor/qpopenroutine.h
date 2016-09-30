#ifndef QPOPENROUTINE_H
#define QPOPENROUTINE_H

#include <QObject>
#include "qprfvfstat.h"
class QPRFVFAccessor;
class QPOpenRoutine : public QObject
{
    Q_OBJECT
public:
    explicit QPOpenRoutine(QObject *parent = 0);
    virtual wtap_open_return_val openRoutine(QPRFVFAccessor *) = 0;
    virtual bool readPacket(QPRFVFAccessor *, int *err, char **err_info, qint64 *data_offset) = 0;

    QString getName() const;
    void setName(const QString &value);

    void setType(const wtap_open_type &value);
    void setExtensions(const QString &value);

private:
    QString name;
    wtap_open_type type;
    QString extensions;
    QStringList extensionsSet;
    void *wsluaData;
};

#endif // QPOPENROUTINE_H
