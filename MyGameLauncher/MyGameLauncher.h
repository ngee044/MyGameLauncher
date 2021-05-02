#pragma once

#include <QtWidgets/QMainWindow>
#include "AccountManager.h"
#include "ChatWidget.h"
#include <QPair>
#include "ui_MyGameLauncher.h"

class TitleBar;
class GameSelectorButton;
class FriendListWidgetItem;

class MyGameLauncher : public QMainWindow
{
    Q_OBJECT

public:
    MyGameLauncher(QWidget *parent = Q_NULLPTR);
	~MyGameLauncher();
	void setAccountInfo(const QString& id, const QString& vip);
	void setFriendList(QVector<QPair<QString, int>> id_list);
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
	USER user_info_;
	
	GameSelectorButton* mobile_game_bt_ = nullptr;
	GameSelectorButton* pc_game_bt_ = nullptr;

	QString download_ftp_url_ = "";
	QString download_path_ = "";

	QVector<FriendListWidgetItem*> v_friend_list_item_;
};
