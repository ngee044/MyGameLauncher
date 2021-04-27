#include "LoginUserManager.h"

LoginUserManager::LoginUserManager()
{
	initDB();
}

LoginUserManager::~LoginUserManager()
{
}

void LoginUserManager::initDB()
{
	if (login_info_ == nullptr)
	{
		login_info_ = new LoginUserInfo();
	}
}

int LoginUserManager::setUserLogin(const QString id, const QString pw)
{
	if (login_info_ == nullptr)
	{
		initDB();
	}

	return login_info_->Login(id, pw);
}

void LoginUserManager::createUser(const User& user_info)
{
}

void LoginUserManager::updateUserInfo(const User& user_info)
{
}
