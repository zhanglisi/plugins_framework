#include "Application.h"

int main(int argc, char* argv[])
{
	CApplication myApp(argc, argv);
	
	myApp.showSplash();
	// 初始化对象
	myApp.initialization();
	// 初始化通信
	myApp.init_communication();

	myApp.closeSplash();

	myApp.exec();
}