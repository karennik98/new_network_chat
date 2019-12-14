#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server server;
    if (!server.stratServer(5555))
    {
        qDebug()<<"Error: "
               <<server.errorString();
        return 1;
    }

    qDebug()<<"Server started...";
    
    return a.exec();
}
