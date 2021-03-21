#include <QApplication>
#include <QDebug>
#include "MyGameLauncher.h"

MyGameLauncher::MyGameLauncher(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

}

void MyGameLauncher::connection()
{
	connect(ui.toolButton_hide, &QToolButton::clicked, this, [=]() {qDebug() << "hide"; });
	connect(ui.toolButton_resize, &QToolButton::clicked, this, [=]() { qDebug() << "resize"; });
	connect(ui.toolButton_exit, &QToolButton::clicked, this, [=]() {QApplication::exit(); });
}