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

	connect(client, &QTcpSocket::readyRead, this, &LauncherChat::slotClientFromToServer);
	connect(client, &QTcpSocket::disconnected, this, &LauncherChat::slotDisconnected);
}

void LauncherChat::slotClientFromToServer()
{
	qDebug() << __func__;
	QTcpSocket* client = dynamic_cast<QTcpSocket*>(this->sender());
	while (client->canReadLine()) //데이터 못읽을때까지 계속 읽는다
	{
		QString line = QString::fromUtf8(client->readLine());
		qDebug() << line;

	}
}

void LauncherChat::slotDisconnected()
{
	qDebug() << __func__;
	QTcpSocket* client = static_cast<QTcpSocket*>(this->sender());
	cliendts_.remove(client);

	QString user = users_id_[client];
	users_id_.remove(client);

	Q_FOREACH(auto c, cliendts_)
	{
		c->write(QString("%1 가 나갔습니다.").arg(user).toUtf8());
	}

}

void LauncherChat::slotSendUserInfo(QString user_id)
{
	Q_FOREACH(auto client,  cliendts_)
	{
		client->write(QString("%1 가 들어왔습니다.").arg(user_id).toUtf8());
	}
}
