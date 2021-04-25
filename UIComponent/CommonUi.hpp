#pragma once
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QToolButton>
#include <QPushButton>
#include <QSizePolicy>
#include "uicomponent_global.h"
//TODO Common Ui Component

class UICOMPONENT_EXPORT GameSelectorButton : public QToolButton
{
	Q_OBJECT
public:
	GameSelectorButton() 
	{ 
		initLayout();
	}
	~GameSelectorButton() {}

	void initLayout() 
	{
		this->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
		this->setMinimumSize(125,75);
		this->setCursor(Qt::PointingHandCursor);
		this->setStyleSheet(
			"QToolButton:hover{ color:white; background-color: orange; }"
			"QToolButton{ color:black; background-color: gray; font-size: 23px; font-weight: bold; }"
			);
	}

protected:

private:


};

