#pragma once

#include <QObject>
#include "../Common/singleton.h"
#include "LoginUserInfo.h"
#include "loginuserinfo_global.h"

class LOGINUSERINFO_EXPORT LoginUserManager : public InSingleton<LoginUserManager>
{
public:
	LoginUserManager();
	~LoginUserManager();

	void initDB();
	int setUserLogin(const QString id, const QString pw);
	
	void createUser(const User& user_info);
	void updateUserInfo(const User& user_info);

protected:
	
private:
	LoginUserInfo* login_info_ = nullptr;
};
