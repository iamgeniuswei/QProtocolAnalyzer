#include <QCoreApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "-------------------QProtocolAnalyzer Build 0.01-----------------";

    return a.exec();
}
