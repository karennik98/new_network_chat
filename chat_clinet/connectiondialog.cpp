#include "connectiondialog.h"
#include "ui_connectiondialog.h"

namespace ChatClient {

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::on_ok_clicked()
{
    mHostname = ui->hostname->text();
    mPort = ui->port->value();
    accept();
}

void ConnectionDialog::on_cancle_clicked()
{
    reject();
}

} // end namspace ChatClient
