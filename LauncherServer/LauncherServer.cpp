#include <QDebug>
#include <QPushButton>
#include "LauncherServer.h"

LauncherServer::LauncherServer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

LauncherServer::~LauncherServer()
{
}

void LauncherServer::connections()
{
    connect(ui.bt_connect_, &QPushButton::clicked, this, &LauncherServer::slotConnectServer);
    connect(ui.bt_disconnect_, &QPushButton::clicked, this, &LauncherServer::slotDisConnectServer);
    connect(ui.bt_ftp_refresh_, &QPushButton::clicked, this, &LauncherServer::slotFtpRefresh);
    connect(ui.bt_send_message_, &QPushButton::clicked, this, &LauncherServer::slotSendMessageToClient);
}

void LauncherServer::slotConnectServer()
{

}

void LauncherServer::slotDisConnectServer()
{

}

void LauncherServer::slotFtpRefresh()
{

}

void LauncherServer::slotSendMessageToClient()
{

}

