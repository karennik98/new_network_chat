#include "server.h"
#include "socket.h"

#include <QDebug>
#include <QTextStream>

namespace ChatServer {

Server::Server(QObject* parent)
    : QTcpServer(parent)
{

}

bool Server::stratServer(quint16 port)
{
   return listen(QHostAddress::Any, port);
}

void Server::incomingConnection(qintptr handle)
{
    qDebug()<<"Client connected with handle: "<<handle;
    auto socket = new Socket(handle, this);
    m_Sockets<<socket;

    for(auto el : m_Sockets)
    {
        QTextStream stream(el);
        stream << "Server: Connected: "<<handle;
        el->flush();
    }

    connect(socket, &Socket::ReadyRead, [&](Socket* sock) {
        qDebug() << "ReadyRead";
        QTextStream stream(sock);
        auto text = stream.readAll();

        for(auto it : m_Sockets)
        {
            QTextStream sendStream(it);
            sendStream<<text;
            it->flush();
        }
    });

    connect(socket, &Socket::StateChanged, [&](Socket* sock, int state) {
        qDebug() << "StateChanged with handle:"
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

} // end namespace ChatServer
