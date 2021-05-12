#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LauncherServer.h"

class LauncherServer : public QMainWindow
{
    Q_OBJECT

public:
    LauncherServer(QWidget *parent = Q_NULLPTR);
    ~LauncherServer();

    void connections();

public slots:
    void slotConnectServer();
    void slotDisConnectServer();

    void slotFtpRefresh();
    void slotSendMessageToClient();

protected:


private:
    Ui::LauncherServerClass ui;

};
