#ifndef DUMESSANGERSOCKET_H
#define DUMESSANGERSOCKET_H

#include <QTcpSocket>

namespace Chat{
class DuMessangerSocket : public QTcpSocket
{
    Q_OBJECT
public:
    DuMessangerSocket(qintptr handle, QObject* parent = nullptr);
signals:
    void DuReadyRead(DuMessangerSocket* soccket);
    void DuStateChanged(DuMessangerSocket* socket, qint32 el);
};
} // end namespace Chat

#endif // DUMESSANGERSOCKET_H
