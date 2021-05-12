#include <QDebug>
#include "UserDBManager.h"

UserDBManager::UserDBManager()
{
	initDB();
}

UserDBManager::~UserDBManager()
{
}

void UserDBManager::initDB()
{
	if (login_info_ == nullptr)
	{
		login_info_ = new LoginUserInfo();
	}
}

int UserDBManager::setUserLogin(const QString id, const QString pw)
{
	if (login_info_ == nullptr)
	{
		initDB();
	}

	return login_info_->Login(id, pw);
}

void UserDBManager::testFoo()
{
	auto i = login_info_->getRowCount();
}

void UserDBManager::createUserSignUp(const User& user_info)
{
	login_info_->createUserSignUp(user_info);
}

void UserDBManager::updateUserColumnInfo(const QString& targetID, const QString column)
{
	login_info_->updateUserColumnInfo(targetID, column);
}

void UserDBManager::updateUserInfo(const User& user_info)
{
	login_info_->updateUserInfo(user_info);
}

User UserDBManager::getUserInfo(const QString& targetID)
{
	return login_info_->getUserInfo(targetID);
}

QString UserDBManager::getUserColumnInfo(const QString targetID, const QString column)
{
	return login_info_->getUserInfo(targetID, column);
}

int UserDBManager::getUserStatus(const QString& targetID)
{
	return login_info_->getUserInfo(targetID, ColumnName::status).toInt();
}

QStringList UserDBManager::getFriendList(QString targetID)
{
	auto list = login_info_->getUserFriendList(targetID);
	return QStringList(list.split(","));
}

int UserDBManager::getFriendStatus(QString targetID)
{
	// 0 no connect
	// 1 connect
	// 2 play

	return 0;
}
