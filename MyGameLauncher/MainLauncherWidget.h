#pragma once

#include <QWidget>
#include "ui_MainLauncherWidget.h"

class MainLauncherWidget : public QWidget
{
	Q_OBJECT

public:
	MainLauncherWidget(QWidget *parent = Q_NULLPTR);
	~MainLauncherWidget();

private:
	Ui::MainLauncherWidget ui;
};
