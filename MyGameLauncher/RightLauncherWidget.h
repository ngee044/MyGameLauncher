#pragma once

#include <QWidget>
#include "ui_RightLauncherWidget.h"

class RightLauncherWidget : public QWidget
{
	Q_OBJECT

public:
	RightLauncherWidget(QWidget *parent = Q_NULLPTR);
	~RightLauncherWidget();

private:
	Ui::RightLauncherWidget ui;
};
