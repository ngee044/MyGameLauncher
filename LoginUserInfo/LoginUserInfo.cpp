#include <QDebug>
#include <QtCore/QCoreApplication>
#include <QNetworkAccessManager>

#include "LoginUserInfo.h"

LoginUserInfo::LoginUserInfo()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
}
