#ifndef DUMESSANGERCONNECTIONDIALOG_H
#define DUMESSANGERCONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class DuMessangerConnectionDialog;
}

namespace  DurateCorporation {

class DuMessangerConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DuMessangerConnectionDialog(QWidget *parent = nullptr);
    ~DuMessangerConnectionDialog();
    QString hostname() const;
    quint16 port() const;
private slots:
    void on_ok_clicked();

    void on_cancle_clicked();

private:
    Ui::DuMessangerConnectionDialog *ui;
    QString mHostname;
    quint16 mPort;
};

inline QString DuMessangerConnectionDialog::hostname() const
{
    return mHostname;
}

inline quint16 DuMessangerConnectionDialog::port() const
{
    return mPort;
}

} // end namspace DurateCorporation

#endif // DUMESSANGERCONNECTIONDIALOG_H
