#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class QTcpSocket;

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    ChatWidget(QWidget *parent = nullptr);
    ~ChatWidget();

private slots:
    void on_send_clicked();

    void on_connect_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket* mSocket;
};

#endif // WIDGET_H
