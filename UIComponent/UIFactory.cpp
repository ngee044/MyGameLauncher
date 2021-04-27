#include "UIFactory.h"

MyMessageBox* UIFactory::showMsgBox(QString title, QString msg, MyMessageBox::MsgButtonType type)
{
	MyMessageBox* msgBox = new MyMessageBox(title, msg, type);

	return msgBox;
}
