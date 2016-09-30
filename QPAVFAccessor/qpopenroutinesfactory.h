#ifndef QPOPENROUTINESFACTORY_H
#define QPOPENROUTINESFACTORY_H
#include <QHash>
#include <QMetaObject>
class QPOpenRoutine;
class QPOpenRoutinesFactory
{
public:
    QPOpenRoutinesFactory();
    template<typename T>
    void registerOpenRoutine(const QString &extension)
    {
        openRoutines.insert(extension, &(T::staticMetaObject));
    }

    static QPOpenRoutine *createObject(const QString &extension);

private:
    static QHash<QString, const QMetaObject*> openRoutines;
};

#endif // QPOPENROUTINESFACTORY_H
