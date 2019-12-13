#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class ConnectionDialog;
}

namespace ChatClient {

class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = nullptr);
    ~ConnectionDialog();
    QString hostname() const;
    quint16 port() const;
private slots:
    void on_ok_clicked();

    void on_cancle_clicked();

private:
    Ui::ConnectionDialog *ui;
    QString mHostname;
    quint16 mPort;
};

inline QString ConnectionDialog::hostname() const
{
    return mHostname;
}

inline quint16 ConnectionDialog::port() const
{
    return mPort;
}

} // end namspace ChatClient

#endif // CONNECTIONDIALOG_H
