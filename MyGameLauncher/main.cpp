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
	LoginUserInfo info;
	return -1;
	QApplication a(argc, argv);
	qDebug() << "hello world!";
	return 0;
#if 1
#else
    QApplication a(argc, argv);
    LoginPage w;
    w.show();
	//MyGameLauncher launcher;
	//launcher.show();
#endif
    return a.exec();
}
