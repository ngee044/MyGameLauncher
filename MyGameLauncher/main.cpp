#include <iostream>
#include <QtWidgets/QApplication>

#include "../LoginUserInfo/UserDBManager.h"
#include "LoginPage.h"
#include "MyGameLauncher.h"

#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QDate>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if 1
    UserDBManager::Instance();

    LoginPage w;
    w.show();
#else
	MyGameLauncher launcher;
	launcher.show();
#endif
    return a.exec();
}
