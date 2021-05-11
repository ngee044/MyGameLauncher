#pragma once

#include <QtWidgets/QMainWindow>
#include "ChatWidget.h"
#include <QPair>
#include "../LoginUserInfo/UserDBManager.h"
#include "ui_MyGameLauncher.h"

class ChatWidget;
class TitleBar;
class GameSelectorButton;
class FriendListWidgetItem;

struct UserFriend
{
	QString id_;
	int status_;
};

class MyGameLauncher : public QMainWindow
{
    Q_OBJECT

public:
    MyGameLauncher(QWidget *parent = Q_NULLPTR);
	~MyGameLauncher();
	void setAccountInfo(const User& userinfo);
	void setFriendList(QVector<UserFriend> id_list);
	void updateFriendList();
	void clearFriendList();

protected:
	void connection();
	void initLayout();
	virtual void resizeEvent(QResizeEvent * event) override;


public slots:
	void slotDownButton();
	void slotDeleteButton();
	void slotSetDirButton();
	void slotGameSelectButton(GameSelectorButton* sender);

private:
    Ui::MyGameLauncherClass ui;

	TitleBar* titlebar_ = nullptr;
	
	GameSelectorButton* mobile_game_bt_ = nullptr;
	GameSelectorButton* pc_game_bt_ = nullptr;

	QString download_ftp_url_ = "";
	QString download_path_ = "";

	QVector<FriendListWidgetItem*> v_friend_list_item_;
};
