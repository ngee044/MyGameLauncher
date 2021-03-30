#pragma once
#include <singleton.h>
#include "redisdbio_global.h"

class REDISDBIO_EXPORT DBManager : public InSingleton<DBManager>
{
public:
	DBManager();
	~DBManager();

protected:

private:

};

