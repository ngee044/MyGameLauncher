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
}

void LauncherChat::slotClientFromToServer()
{
	QTcpSocket* client = dynamic_cast<QTcpSocket*>(this->sender());
	while (client->canReadLine()) //������ ������������ ��� �д´�
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
