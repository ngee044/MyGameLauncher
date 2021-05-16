#include <QDebug>
#include "LauncherChat.h"

LauncherChat::LauncherChat(QObject *parent)
	: QObject(parent)
{
}

LauncherChat::~LauncherChat()
{
}

void LauncherChat::incomingConnection(int socketfd)
{
	QTcpSocket* client = new QTcpSocket(this); //클라리언트 소켓 새성
	client->setSocketDescriptor(socketfd); //

	cliendts_.insert(client); //클라이언트 집합에 새로 들어온 클라이언트 추가
}

void LauncherChat::slotClientFromToServer()
{
	QTcpSocket* client = dynamic_cast<QTcpSocket*>(this->sender());
	while (client->canReadLine()) //데이터 못읽을때까지 계속 읽는다
	{
		QString line = QString::fromUtf8(client->readLine());
		qDebug() << line;

	}
}

void LauncherChat::slotDisconnected()
{
}

void LauncherChat::slotSendUserInfo()
{
}
