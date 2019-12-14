#include "chatwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    ChatWidget w;
    w.show();
    return a.exec();
}
