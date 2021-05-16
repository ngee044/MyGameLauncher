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
	void slotClientFromToServer(); //Ŭ��κ��� �޽��� ����
	void slotDisconnected(); //Ŭ�� ���� ���涧
	void slotSendUserInfo(); //���� ���� ���� �˸�

protected:
	void incomingConnection(int socketfd); //ó�� ������ ������ ������ �õ��Ҷ� 

private:
	int user_amount_; //user number
	QSet<QTcpSocket*> cliendts_;
	QMap<QTcpSocket*, QString> users_id; 
};
