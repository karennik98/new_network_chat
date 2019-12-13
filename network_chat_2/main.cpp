#include <QCoreApplication>
#include "dumessangerserver.h"


using namespace Chat;

//#include <QApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DuMessangerServer server;
    if (!server.stratServer(5555))
    {
        qDebug()<<"Error: "
               <<server.errorString();
        return 1;
    }

    qDebug()<<"Server started...";

//    MainWindow w;
//    w.show();
    return a.exec();
}
