#include "dumessangerserver.h"
#include "dumessangersocket.h"

#include <QDebug>
#include <QTextStream>

namespace Chat{
DuMessangerServer::DuMessangerServer(QObject* parent)
    : QTcpServer(parent)
{

}

bool DuMessangerServer::stratServer(quint16 port)
{
   return listen(QHostAddress::Any, port);
}

void DuMessangerServer::incomingConnection(qintptr handle)
{
    qDebug()<<"Client connected with handle: "<<handle;
    auto socket = new DuMessangerSocket(handle, this);
    m_Sockets<<socket;

    for(auto el : m_Sockets)
    {
        QTextStream stream(el);
        stream << "Server: Connected: "<<handle;
        el->flush();
    }

    connect(socket, &DuMessangerSocket::DuReadyRead, [&](DuMessangerSocket* sock) {
        qDebug() << "DuReadyRead";
        QTextStream stream(sock);
        auto text = stream.readAll();

        for(auto it : m_Sockets)
        {
            QTextStream sendStream(it);
            sendStream<<text;
            it->flush();
        }
    });

    connect(socket, &DuMessangerSocket::DuStateChanged, [&](DuMessangerSocket* sock, int state) {
        qDebug() << "DuStateChanged with handle:"
                 <<sock->socketDescriptor();
        if(state == QTcpSocket::UnconnectedState)
        {
            qDebug()<<"Unconnected state with handle:"
                   <<sock->socketDescriptor();
            m_Sockets.removeOne(sock);
            for(auto it : m_Sockets)
            {
                QTextStream stream(it);
                stream << "Server: clinet unconnect "
                       <<sock->socketDescriptor()
                       <<" is desconnected ...";
                it->flush();
            }
        }
    });
}

} // end namespace Chat
