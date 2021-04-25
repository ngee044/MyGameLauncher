#pragma once
#include <QString>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "loginuserinfo_global.h"

class User
{
	QString Id_;
	QString pw_;
	int vip_level_ = 1;
	QString create_date_;
	QString visit_date_;
};

class LOGINUSERINFO_EXPORT LoginUserInfo
{
public:
    LoginUserInfo();
	
};
