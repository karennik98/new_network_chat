#include "chatwidget.h"
#include "ui_widget.h"
#include "connectiondialog.h"
#include <QTcpSocket>
#include <QTextStream>

ChatWidget::ChatWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //mSocket = new QTcpSocket(this);
    mConnection = new Connection();

    connect(mConnection->getConnectionSocket(), &QTcpSocket::readyRead, [&]()
    {
        QTextStream stream(mConnection->getConnectionSocket());
        auto text = stream.readAll();
        ui->textEdit->append(text);
    });
}

ChatWidget::~ChatWidget()
{
    delete ui;
}


void ChatWidget::on_send_clicked()
{
    QTextStream stream(mSocket);
    stream << ui->nikName->text() << ": " << ui->message->text();
    mSocket->flush();
    ui->message->clear();
}

void ChatWidget::on_connect_clicked()
{
    ConnectionDialog dialog(this);
    if(dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    mSocket->connectToHost(dialog.hostname(), dialog.port());
}

