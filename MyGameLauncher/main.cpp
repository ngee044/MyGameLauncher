#include <QtWidgets/QApplication>
#include "LoginPage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginPage w;
    w.show();
    return a.exec();
}
