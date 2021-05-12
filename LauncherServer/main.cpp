#include "LauncherServer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LauncherServer w;

    w.show();
    return a.exec();
}
