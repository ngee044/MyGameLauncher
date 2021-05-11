#pragma once
#include "../Common/singleton.h"
#include "MyGameLauncher.h"
#include "LoginPage.h"
#include "ChatWidget.h"

class AppManager : public InSingleton<AppManager>
{
public:
	AppManager();
	~AppManager();

	void setMyUser(User info) { my_user_ = info; }
	User getMyUser() { return my_user_; }

protected:

private:
	User my_user_;

};

