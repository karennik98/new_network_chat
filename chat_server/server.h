#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QList>
    
class Socket;

class Server : public QTcpServer
{
public:
    Server(QObject* parent = nullptr);
    bool stratServer(quint16 port);
protected:
    void incomingConnection(qintptr handle) override;
private:
    QList<Socket* > m_Sockets;
};

#endif // SERVER_H
