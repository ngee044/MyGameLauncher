#pragma once
#include <QString>
#include <qobject.h>
#include <QtCore>
#include <qvector.h>
#include <QPixmap>

struct MyGame
{
	quint64 play_time_hour_ = 0;
};

struct Account
{
	QString id_;
	QString pw_;

	QString nick_name_;
	QPixmap icon_image_;
	QVector<MyGame> v_games_list_;
	
} typedef USER;

class AccountManager
{
public:
	AccountManager();
	~AccountManager();

	void createUser();
	bool checkPassword();
	bool checkId();

private:
	USER user_;
};

