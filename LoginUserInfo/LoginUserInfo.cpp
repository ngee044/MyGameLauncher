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

//중복 검사
bool LoginUserInfo::checkIdDuplicate(const QString& id)
{
	QSqlQuery query("SELECT * FROM " + ColumnName::table_name_);
	int fieldNo1 = query.record().indexOf(ColumnName::user_id_);

	while (query.next())
	{
		if (id == query.value(fieldNo1).toString())
		{
			return true;
		}
	}
	return false;
}

int LoginUserInfo::getRowCount(const QString& table_name, const QString& data_column)
{
	QSqlQuery query("SELECT COUNT(" + data_column + ") as cnt FROM " + table_name);
	return query.size();
}

bool LoginUserInfo::createUserSignUp(User user)
{
	if (checkIdDuplicate(user.Id_))
	{
		QString qstr = ("INSERT INTO %1 (%2, %3, %4, %5, %6, %7, %8, %9, %10)"
			"VALUES (:tag, :id, :pw, :vip_level, :create_date, :visit_date, :has_games, :friend_list, :status)");
		QSqlQuery query;
		query.prepare(qstr.arg(ColumnName::user_tag_num_, ColumnName::table_name_, ColumnName::user_id_, ColumnName::user_pw_,
			ColumnName::vip_level_, ColumnName::create_date_, ColumnName::visit_date_, ColumnName::has_games_,
			ColumnName::friend_list, ColumnName::status));
		qDebug() <<"query str = " << query.lastQuery();
		auto t = getRowCount(ColumnName::table_name_, ColumnName::user_tag_num_);
		qDebug() << "tag num = " << t;
		query.bindValue(":tag", t);
		query.bindValue(":id", user.Id_);
		query.bindValue(":pw", user.pw_);
		query.bindValue(":vip_level", user.vip_level_);
		query.bindValue(":create_date", user.create_date_);
		query.bindValue(":visit_date", user.visit_date_);
		query.bindValue(":has_games", user.has_games_);
		query.bindValue(":friend_list", user.friend_list_);
		query.bindValue(":status", user.status_);

		return true;
	}
	else
	{
		return false;
	}
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

	//indexOf에 column name을 입력
	int index = query.record().indexOf(ColumnName::user_id_);
	int fieldNo = query.record().indexOf(column);
	while (query.next())
	{
		if (targetID == query.value(index).toString())
		{
			return query.value(fieldNo).toString();
		}
	}
	qDebug() << "unknown ID";
	return "unknown ID";
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

