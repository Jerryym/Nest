#include "NestApp.h"
#include <iostream>

int main(int argc, char* argv[])
{
	NestApp::Application app(argc, argv);
	return app.exec();
}
