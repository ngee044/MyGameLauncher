#include "AppManager.h"

AppManager::AppManager()
{
}

AppManager::~AppManager()
{
}

QString AppManager::getCurrentDate()
{
	auto date = QDate::currentDate();
	QString date_str;
	date_str.sprintf("%04d-%02d-%02d", date.year(), date.month(), date.day());

	return date_str;
}
