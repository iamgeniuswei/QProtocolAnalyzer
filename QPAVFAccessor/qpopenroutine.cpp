#include "qpopenroutine.h"

QPOpenRoutine::QPOpenRoutine(QObject *parent) : QObject(parent)
{

}

QString QPOpenRoutine::getName() const
{
    return name;
}

void QPOpenRoutine::setName(const QString &value)
{
    name = value;
}

void QPOpenRoutine::setType(const wtap_open_type &value)
{
    type = value;
}

void QPOpenRoutine::setExtensions(const QString &value)
{
    extensions = value;
}
