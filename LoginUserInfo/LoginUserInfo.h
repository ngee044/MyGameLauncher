#pragma once
#include <QString>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "loginuserinfo_global.h"

namespace ColumnName
{
	const QString table_name_ = "LoginUserInfo";

	const QString user_tag_num_ = "USER_TAG_NUMBER";
	const QString user_id_ = "ID";
	const QString user_pw_ = "PW";
	const QString vip_level_ = "VIP_LEVEL";
	const QString create_date_ = "CREATE_DATE";
	const QString visit_date_ = "VISIT_DATE";
	const QString has_games_ = "GAMES";
	const QString friend_list = "FRIEND";
	const QString status = "STATUS";
}

struct User
{
	QString Id_;
	QString pw_;
	int vip_level_ = 1;
	QString create_date_;
	QString visit_date_;
	QStringList has_games_;
	QStringList friend_list_;
	int status_;
};

class LOGINUSERINFO_EXPORT LoginUserInfo
{
public:
	LoginUserInfo();

	int Login(const QString& id, const QString& pw);
	bool checkIdDuplicate(const QString& id);
	int getRowCount(const QString& table_name, const QString& data_column);
	bool createUserSignUp(User user);
	void updateUserColumnInfo(const QString& targetID, const QString column);
	QString getUserFriendList(QString tragetID);
	QString getUserInfo(const QString& targetID, const QString column);
	User getUserInfo(const QString& targetID);
	void updateUserInfo(User userInfo);


private:
	QSqlDatabase db_;
};
