#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(QString("       微信跳一跳       超级无敌好用版      v0.0.1"));
    w.show();

    return a.exec();
}
