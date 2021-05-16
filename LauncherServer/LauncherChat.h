#pragma once

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSet>

class LauncherChat : public QObject
{
	Q_OBJECT

public:
	LauncherChat(QObject *parent);
	~LauncherChat();

public slots:
	void slotClientFromToServer(); //클라로부터 메시지 전달
	void slotDisconnected(); //클라 접속 끊길때
	void slotSendUserInfo(); //새로 들어온 유저 알림

protected:
	void incomingConnection(int socketfd); //처음 유저가 서버에 접속을 시도할때 

private:
	int user_amount_; //user number
	QSet<QTcpSocket*> cliendts_;
	QMap<QTcpSocket*, QString> users_id; 
};
