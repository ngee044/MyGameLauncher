#include <QDebug>
#include <QtCore/QCoreApplication>
#include <QNetworkAccessManager>
#include <qsqlquerymodel.h>
#include "LoginUserInfo.h"

LoginUserInfo::LoginUserInfo()
{
	qDebug() << QSqlDatabase::drivers();
	db_ = QSqlDatabase::addDatabase("QMYSQL");
	db_.setHostName("userlogindb.cug9zbehw6m0.ap-northeast-2.rds.amazonaws.com");
	db_.setPort(3306);
	db_.setDatabaseName("LoginDB");
	db_.setUserName("admin");
	db_.setPassword("gkrtjr12");

}

// 0 pw error
// -1 id error
// 1 is login
int LoginUserInfo::Login(const QString& id, const QString& pw)
{
	if (db_.open())
	{
		const QString table_name = "LoginUserInfo";
		QSqlQuery query("SELECT * FROM " + table_name);
		int fieldNo1 = query.record().indexOf("ID");
		int fieldNo2 = query.record().indexOf("PW");
		while (query.next())
		{
#if 0
			qDebug() << query.value(fieldNo1).toString();
			qDebug() << query.value(fieldNo2).toString();
#endif
		}
	}
	else
	{
		qDebug() << "Error qmysql..... not connected";
	}

	const QString table_name = "LoginUserInfo";
	QSqlQuery query("SELECT * FROM " + table_name);
	int fieldNo1 = query.record().indexOf("ID");
	int fieldNo2 = query.record().indexOf("PW");
	while (query.next())
	{

		if (id == query.value(fieldNo1).toString())
		{
			if (pw == query.value(fieldNo2).toString())
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	db_.close();

	return -1;
}


