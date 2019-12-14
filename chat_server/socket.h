#ifndef SOCKET_H
#define SOCKET_H

#include <QTcpSocket>

class Socket : public QTcpSocket
{
    Q_OBJECT
public:
    Socket(qintptr handle, QObject* parent = nullptr);
signals:
    void ReadyRead(Socket* soccket);
    void StateChanged(Socket* socket, qint32 el);
};

#endif // SOCKET_H
