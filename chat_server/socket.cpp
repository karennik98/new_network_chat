#include "socket.h"

namespace ChatServer {

Socket::Socket(qintptr handle, QObject* parent)
    : QTcpSocket(parent)
{
    setSocketDescriptor(handle);
    connect(this, &Socket::readyRead, [&]() {
        emit ReadyRead(this);
    });

    connect(this, &Socket::stateChanged, [&](qint32 el) {
       emit StateChanged(this, el);
    });
}

} // namespace ChatServer
