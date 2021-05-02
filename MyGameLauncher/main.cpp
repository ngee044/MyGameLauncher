#include <iostream>
#include <QtWidgets/QApplication>

#include "../LoginUserInfo/LoginUserManager.h"
#include "LoginPage.h"
#
#include "MyGameLauncher.h"

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>

class MyCustomHttpClientFactory
{

};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if 0
    LoginUserManager::Instance();

    LoginPage w;
    w.show();
#else
	MyGameLauncher launcher;
	launcher.show();
#endif
    return a.exec();
}
