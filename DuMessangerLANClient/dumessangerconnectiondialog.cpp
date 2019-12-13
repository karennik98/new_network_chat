#include "dumessangerconnectiondialog.h"
#include "ui_dumessangerconnectiondialog.h"

namespace DurateCorporation {

DuMessangerConnectionDialog::DuMessangerConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DuMessangerConnectionDialog)
{
    ui->setupUi(this);
}

DuMessangerConnectionDialog::~DuMessangerConnectionDialog()
{
    delete ui;
}

void DuMessangerConnectionDialog::on_ok_clicked()
{
    mHostname = ui->hostname->text();
    mPort = ui->port->value();
    accept();
}

void DuMessangerConnectionDialog::on_cancle_clicked()
{
    reject();
}

} // end namspace DurateCorporation
