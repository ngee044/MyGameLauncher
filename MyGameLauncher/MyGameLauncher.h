#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MyGameLauncher.h"

class MyGameLauncher : public QMainWindow
{
    Q_OBJECT

public:
    MyGameLauncher(QWidget *parent = Q_NULLPTR);

private:
    Ui::MyGameLauncherClass ui;
};
