#pragma once
#include <QString>

//#define _kor(str)  QString::fromLocal8Bit(str)
static QString _kor(const char* str)
{
	auto result = QString::fromLocal8Bit(str);
	return result;
}