#pragma once
#include "uicomponent_global.h"
#include "CommonUi.hpp"
#include "UIComponent.h"

//TODO Ui Factory Class
//static 메서드 함수로 정의하여 구현 예정

class UICOMPONENT_EXPORT UIFactory
{
public:
	static MyMessageBox* showMsgBox(QString title, QString msg, MyMessageBox::MsgButtonType type = MyMessageBox::ONE);
	static FriendListWidgetItem* createFriendListItem(QString id, FriendListWidgetItem::FriendStatus status = FriendListWidgetItem::NOCONNECT);
};

