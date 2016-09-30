#include "qpopenroutinesfactory.h"
#include <QObject>
#include "qpopenroutine.h"

QHash<QString, const QMetaObject*> QPOpenRoutinesFactory::openRoutines;

QPOpenRoutinesFactory::QPOpenRoutinesFactory()
{

}

QPOpenRoutine *QPOpenRoutinesFactory::createObject(const QString &extension)
{
    const QMetaObject *metaObj = openRoutines.value(extension);
    if(metaObj)
    {
        QObject *routine = metaObj->newInstance();
        return qobject_cast<QPOpenRoutine*>(routine);
    }
    else
        return nullptr;
}
