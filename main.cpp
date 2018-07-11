#include "qtmvcwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtMVCWindow w;
    w.show();

    return a.exec();
}
