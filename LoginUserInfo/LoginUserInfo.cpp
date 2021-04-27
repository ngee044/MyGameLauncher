#include <QDebug>
#include <QtCore/QCoreApplication>
#include <QNetworkAccessManager>
#include <QSetting>
#include "LoginUserInfo.h"

LoginUserInfo::LoginUserInfo()
{
	QSetting setting("configure.ini", QSettings::IniFormat);
	setting.beginGroup("database");
	
	QString name = setting.value("name").toString();
	QString hostname = setting.value("hostname").toString();
	QString pw = setting.value("password").toString();
	int port = setting.value("port").toInt();

	qDebug() << QSqlDatabase::drivers();
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	//todo db setting
	
	if(db.open())
	{
            qDebug() << "connected...aws rds mysql db";
	}
	else
	{
            qDebug() << "not load db server";
	}
}


