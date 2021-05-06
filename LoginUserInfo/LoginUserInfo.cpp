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
	if (!db_.open())
	{
		qDebug() << "error db connected..........";
		return -1;
	}
	QSqlQuery query("SELECT * FROM " + ColumnName::table_name_);
	int fieldNo1 = query.record().indexOf("ID");
	int fieldNo2 = query.record().indexOf("PW");
	static int a = 0;
	static int b = 0;
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

void LoginUserInfo::createUserSignUp(User user)
{

}

void LoginUserInfo::updateUserColumnInfo(const QString& targetID, const QString column)
{

}

void LoginUserInfo::updateUserInfo(User userInfo)
{

}

QString LoginUserInfo::getUserFriendList(QString targetID)
{
	QSqlQuery query("SELECT * FROM " + ColumnName::table_name_);
	int fieldNo1 = query.record().indexOf(ColumnName::user_id_);
	int fieldNo2 = query.record().indexOf(ColumnName::friend_list);
	while (query.next())
	{
		if (targetID == query.value(fieldNo1).toString())
		{
			auto str = query.value(fieldNo2).toString();
			return str;
		}
	}
	return "";
}

QString LoginUserInfo::getUserInfo(const QString& targetID, const QString column)
{
	QSqlQuery query("SELECT * FROM " + ColumnName::table_name_);
	
	int index = query.record().indexOf(targetID);
	int fieldNo = query.record().indexOf(column);
	while (query.next())
	{
		if (targetID == query.value(index).toString())
		{
			return query.value(fieldNo).toString();
		}
	}
}

User LoginUserInfo::getUserInfo(const QString& targetID)
{
	User user;
	user.Id_ = targetID;
	
	QSqlQuery query("SELECT * FROM " + ColumnName::table_name_);
	int fieldNo1 = query.record().indexOf(ColumnName::user_id_);
	int fieldNo2 = query.record().indexOf(ColumnName::friend_list);
	int fieldNo3 = query.record().indexOf(ColumnName::vip_level_);
	int fieldNo4 = query.record().indexOf(ColumnName::visit_date_);
	int fieldNo5 = query.record().indexOf(ColumnName::has_games_);
	int fieldNo6 = query.record().indexOf(ColumnName::create_date_);
	int fieldNo7 = query.record().indexOf(ColumnName::status);

	while (query.next())
	{
		if (targetID == query.value(fieldNo1).toString())
		{
			user.friend_list_ = query.value(fieldNo2).toString().split(",");
			user.vip_level_ = query.value(fieldNo3).toInt();
			user.visit_date_ = query.value(fieldNo4).toString();
			user.has_games_ = query.value(fieldNo6).toString().split(",");
			user.create_date_ = query.value(fieldNo6).toString();
			user.status_ = query.value(fieldNo7).toInt();
		}
	}
	return user;
}

