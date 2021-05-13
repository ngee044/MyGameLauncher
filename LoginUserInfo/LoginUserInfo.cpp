#include <QDebug>
#include <QtCore/QCoreApplication>
#include <QNetworkAccessManager>
#include <qsqlquerymodel.h>
#include <Windows.h>
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
	db_.setConnectOptions("MYSQL_OPT_RECONNECT = 1; MYSQL_OPT_CONNECT_TIMEOUT = 600;");
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
			return false;
		}
	}
	return true;
}

int LoginUserInfo::getRowCount()
{
	if (!db_.open())
	{
		qDebug() << "do not open db" << __func__ << __LINE__;
		return -1;
	}

	QSqlQuery query("SELECT * FROM " + ColumnName::table_name_);
	auto cnt = query.size();
	db_.close();

	return cnt;
}

bool LoginUserInfo::createUserSignUp(User user)
{
	qDebug() << __func__;
	if (!db_.open())
	{
		qDebug() << "do not open db" << __func__ << __LINE__;
		return false;
	}

	if (checkIdDuplicate(user.Id_))
	{
		QString qstr = ("INSERT INTO LoginUserInfo (USER_TAG_NUMBER, ID, PW, VIP_LEVEL, CREATE_DATE, VISIT_DATE, GAMES, FRIEND, STATUS) "
			"VALUES (:USER_TAG_NUMBER, :ID, :PW, :VIP_LEVEL, :CREATE_DATE, :VISIT_DATE, :GAMES, :FRIEND, :STATUS)");

		QSqlQuery query;
		if (query.prepare(qstr))
		{
			qDebug() << __LINE__ << "true";
			query.bindValue(":USER_TAG_NUMBER", static_cast<int>(getRowCount() + 1));
			query.bindValue(":ID", user.Id_);
			query.bindValue(":PW", user.pw_);
			query.bindValue(":VIP_LEVEL", user.vip_level_);
			query.bindValue(":CREATE_DATE", user.create_date_);
			query.bindValue(":VISIT_DATE", " ");
			query.bindValue(":GAMES", " ");
			query.bindValue(":FRIEND", " ");
			query.bindValue(":STATUS", user.status_);
		}
		
		if (query.exec())
		{
			qDebug() << "true";
			qDebug() << "create account";
		}
		else
		{
			qDebug() << "false";
			qDebug() << "SQL Statement Error : " << query.lastError().text();
		}
		db_.close();
		return true;
	}
	qDebug() << "Id duple....";
	db_.close();
	return false;
}

void LoginUserInfo::updateUserColumnInfo(const QString& targetID, const QString column)
{
}

void LoginUserInfo::updateUserInfo(User userInfo)
{
#if 1
	qDebug() << __func__;
	if (!db_.open())
	{
		qDebug() << "do not open db" << __func__ << __LINE__;
		return;
	}

	if (checkIdDuplicate(userInfo.Id_) == false) //계정이 있는지 확인 있으면 false를 리턴
	{
		QString games = userInfo.has_games_.join(",");
		QString frineds = userInfo.friend_list_.join(",");
	//	QString qstr = QString("UPDATE LoginUserInfo SET (PW = %1, VIP_LEVEL = %2, VISIT_DATE = %3, GAMES = %4, FRIEND = %5, STATUS = %6) "
	//				           "WHERE (ID = %7)").arg(userInfo.pw_, QString::number(userInfo.vip_level_), userInfo.visit_date_, games, frineds, QString::number(userInfo.status_), userInfo.Id_);
		//QString qstr = ();
		//qDebug() << qstr;
		
		QSqlQuery query;
		qDebug() << "update query = " << query.exec("UPDATE LoginUserInfo SET PW = 2222 WHERE ID = nukle");
		qDebug() << query.lastError().text();
#if 0
		if (query.prepare(qstr))
		{
			query.bindValue(":USER_TAG_NUMBER", static_cast<int>(getRowCount() + 1));
			query.bindValue(":ID", userInfo.Id_);
			query.bindValue(":PW", userInfo.pw_);
			query.bindValue(":VIP_LEVEL", userInfo.vip_level_);
			query.bindValue(":CREATE_DATE", userInfo.create_date_);
			query.bindValue(":VISIT_DATE", " ");
			query.bindValue(":GAMES", " ");
			query.bindValue(":FRIEND", " ");
			query.bindValue(":STATUS", userInfo.status_);
		}

		if (query.exec())
		{
			qDebug() << "true";
			qDebug() << "create account";
		}
		else
		{
			qDebug() << "false";
			qDebug() << "SQL Statement Error : " << query.lastError().text();
		}
#endif
	}
	db_.close();
#endif

	/*db_.open();
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
		if (userInfo.Id_ == query.value(fieldNo1).toString())
		{
			qDebug() << "1 = " << query.value(fieldNo7).toString();
			qDebug() << "2 = " << query.value(fieldNo7);
			query.value(fieldNo7) = QVariant(123);
			qDebug() << "3 = " << query.value(fieldNo7);
			break;
		}
	}
	db_.close();*/
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

