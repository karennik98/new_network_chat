#ifndef DUMESSANGERSERVER_H
#define DUMESSANGERSERVER_H

#include <QTcpServer>
#include <QList>

namespace Chat {
class DuMessangerSocket;

class DuMessangerServer : public QTcpServer
{
public:
    DuMessangerServer(QObject* parent = nullptr);
    bool stratServer(quint16 port);
protected:
    void incomingConnection(qintptr handle) override;
private:
    QList<DuMessangerSocket* > m_Sockets;
};
} // end namespace Chat

#endif // DUMESSANGERSERVER_H
