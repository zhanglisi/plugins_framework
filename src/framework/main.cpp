#include "Application.h"

int main(int argc, char* argv[])
{
	CApplication myApp(argc, argv);
	
	myApp.showSplash();
	// ��ʼ������
	myApp.initialization();
	// ��ʼ��ͨ��
	myApp.init_communication();

	myApp.closeSplash();

	myApp.exec();
}