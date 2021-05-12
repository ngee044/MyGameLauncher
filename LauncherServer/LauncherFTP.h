#pragma once

#include <QObject>

class LauncherFTP : public QObject
{
	Q_OBJECT

public:
	LauncherFTP(QObject *parent);
	~LauncherFTP();
};
