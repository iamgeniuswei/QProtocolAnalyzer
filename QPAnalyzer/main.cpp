#include <QCoreApplication>
#include <QDebug>
#include <QFileInfo>
#include "qpfileaccessor.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "-------------------QProtocolAnalyzer Build 0.01-----------------";

    QFileInfo info;
    info.setFile("/home/lenovo/Documents/test.pcap");
    qDebug() << info.completeSuffix();
    qDebug() << info.absoluteFilePath();

    QPFileAccessor *accessor = new QPFileAccessor;
    qDebug() << accessor->cf_open(info.absoluteFilePath(), 0, 0, nullptr );
    accessor->cf_read(false);

    return a.exec();
}
