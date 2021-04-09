#include <iostream>
#include <QtWidgets/QApplication>

#include "LoginPage.h"
#include "MyGameLauncher.h"
#include "../AWS_IO/aws_io.h"

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
	AWS_IO aws_io;
	return 0;

    QApplication a(argc, argv);
#if 0
    LoginPage w;
    w.show();
#else
	MyGameLauncher launcher;
	launcher.show();
#endif
    return a.exec();
}
