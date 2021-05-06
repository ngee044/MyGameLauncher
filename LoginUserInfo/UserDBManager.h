#pragma once

#include <QObject>
#include "../Common/singleton.h"
#include "LoginUserInfo.h"
#include "loginuserinfo_global.h"

class LOGINUSERINFO_EXPORT UserDBManager : public InSingleton<UserDBManager>
{
public:
	UserDBManager();
	~UserDBManager();
	UserDBManager(const UserDBManager&) = delete;
	const UserDBManager& operator = (const UserDBManager&) = delete;

	void initDB();
	int setUserLogin(const QString id, const QString pw);
	User getUserInfo(const QString& targetID);
	QString getUserColumnInfo(const QString targetID, const QString column);
	void createUserSignUp(const User& user_info);
	void updateUserColumnInfo(const QString& targetID, const QString column);
	void updateUserInfo(const User& user_info);

	QStringList getFriendList(QString targetID);
	int getFriendStatus(QString targetID);
	int getUserStatus(const QString& targetID);
protected:
	
private:
	LoginUserInfo* login_info_ = nullptr;
};
