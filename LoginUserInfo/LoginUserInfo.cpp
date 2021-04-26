#include <QDebug>
#include <QtCore/QCoreApplication>
#include <QNetworkAccessManager>

#include "LoginUserInfo.h"

LoginUserInfo::LoginUserInfo()
{
	qDebug() << QSqlDatabase::drivers();
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

	qDebug() << db.open();

	db.
}
