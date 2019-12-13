#include "dumessangersocket.h"

namespace Chat {
DuMessangerSocket::DuMessangerSocket(qintptr handle, QObject* parent)
    : QTcpSocket(parent)
{
    setSocketDescriptor(handle);
    connect(this, &DuMessangerSocket::readyRead, [&]() {
        emit DuReadyRead(this);
    });

    connect(this, &DuMessangerSocket::stateChanged, [&](qint32 el) {
       emit DuStateChanged(this, el);
    });
}

} // namespace Chat
