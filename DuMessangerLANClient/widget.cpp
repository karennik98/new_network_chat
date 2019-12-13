#include "widget.h"
#include "ui_widget.h"
#include "dumessangerconnectiondialog.h"
#include <QTcpSocket>
#include <QTextStream>

namespace DurateCorporation {

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);

    connect(mSocket, &QTcpSocket::readyRead, [&]()
    {
        QTextStream stream(mSocket);
        auto text = stream.readAll();
        ui->textEdit->append(text);
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_send_clicked()
{
    QTextStream stream(mSocket);
    stream << ui->nikName->text() << ": " << ui->message->text();
    mSocket->flush();
    ui->message->clear();
}

void Widget::on_connect_clicked()
{
    DuMessangerConnectionDialog dialog(this);
    if(dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    mSocket->connectToHost(dialog.hostname(), dialog.port());
}

} // end namespace DurateCorporation
