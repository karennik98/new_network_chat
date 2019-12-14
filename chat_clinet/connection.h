#ifndef CONNECTION_H
#define CONNECTION_H

#include<QString>
#include <QTcpSocket>

class Connection : public QObject
{
    Q_OBJECT
public:
    Connection() = default;
    Connection(QString hostname, quint16 port)
        : mHostname(hostname)
        , mPort(port)
    {

    }
    QString getHostname() const                       { return mHostname; }
    quint16 getPort() const                           { return mPort;     }
    /*const*/ QTcpSocket& getConnectionSocket() const { return *mSocket;  }

    void setHostname(QString hostname);
    void setPort(quint16 port);
private:
    QString mHostname;
    quint16 mPort;
    QTcpSocket* mSocket;
};

#endif // CONNECTION_H
