#include <iostream>
#include <QtWidgets/QApplication>
#include <aws/core/Aws.h>

#include "LoginPage.h"

class MyCustomHttpClientFactory
{

};

int main(int argc, char *argv[])
{
#if 0
	Aws::SDKOptions options;
	options.httpOptions.httpClientFactory_create_fn = []() {
		return Aws::MakeShared<MyCustomHttpClientFactory>(
			"ALLOC_TAG", arg1);
	};
	Aws::InitAPI(options);
	{
		std::cout << "hello world!";
		// make your sdk calls here
	}
	Aws::ShutdownAPI(options);
	return 0;
#endif

    QApplication a(argc, argv);
    LoginPage w;
    w.show();
    return a.exec();
}
