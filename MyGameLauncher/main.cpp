#include <iostream>
#include <QtWidgets/QApplication>

#include "../LoginUserInfo/LoginUserInfo.h"
#include "LoginPage.h"
#include "MyGameLauncher.h"

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>

class MyCustomHttpClientFactory
{

};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginUserInfo info;

    return 0;
#if 0
    LoginPage w;
    w.show();
#else
	MyGameLauncher launcher;
	launcher.show();
#endif
    return a.exec();
}
