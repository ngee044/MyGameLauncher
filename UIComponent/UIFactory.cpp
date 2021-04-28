#include <memory>
#include "UIFactory.h"

MyMessageBox* UIFactory::showMsgBox(QString title, QString msg, MyMessageBox::MsgButtonType type)
{
	return new MyMessageBox(title, msg, type);
}
