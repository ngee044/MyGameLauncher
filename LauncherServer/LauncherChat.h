#pragma once

#include <QObject>

class LauncherChat : public QObject
{
	Q_OBJECT

public:
	LauncherChat(QObject *parent);
	~LauncherChat();
};
