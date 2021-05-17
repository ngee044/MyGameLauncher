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
	QTcpSocket* client = new QTcpSocket(this); //Ŭ�󸮾�Ʈ ���� ����
	client->setSocketDescriptor(socketfd); //

	cliendts_.insert(client); //Ŭ���̾�Ʈ ���տ� ���� ���� Ŭ���̾�Ʈ �߰�

	connect(client, &QTcpSocket::readyRead, this, &LauncherChat::slotClientFromToServer);
	connect(client, &QTcpSocket::disconnected, this, &LauncherChat::slotDisconnected);
}

void LauncherChat::slotClientFromToServer()
{
	qDebug() << __func__;
	QTcpSocket* client = dynamic_cast<QTcpSocket*>(this->sender());
	while (client->canReadLine()) //������ ������������ ��� �д´�
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
		c->write(QString("%1 �� �������ϴ�.").arg(user).toUtf8());
	}

}

void LauncherChat::slotSendUserInfo(QString user_id)
{
	Q_FOREACH(auto client,  cliendts_)
	{
		client->write(QString("%1 �� ���Խ��ϴ�.").arg(user_id).toUtf8());
	}
}
