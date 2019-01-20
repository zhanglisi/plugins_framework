#include <QSplashScreen>
#include "Application.h"
#include "PluginMgr.h"
#include "AsynchronousThread.h"
#include "Mediator.h"

CApplication::CApplication(int &argc, char **argv)
	: QApplication(argc, argv)
	, _splash_screen(nullptr)
	, _mediator(nullptr)
{
	init();
}

CApplication::~CApplication()
{
	if (_splash_screen)
	{
		delete _splash_screen;
		_splash_screen = nullptr;
	}
}

void CApplication::initialization()
{
	connect(CPluginMgr::instance(), SIGNAL(loadMessage(int, QString)), this, SLOT(slotLoadMessage(int, QString)));


	CPluginMgr::instance()->initialization(_mediator);


	

}

void CApplication::init_communication()
{


	CAsynchronousThread::instance()->start();
}

void CApplication::showSplash()
{
	_splash_screen->show();
}

void CApplication::closeSplash()
{
	// end
	_splash_screen->close();
}

void CApplication::init()
{
	_mediator = new CMediator(this);
	_splash_screen = new QSplashScreen(QPixmap(":/resources/splash.jpg"));
}

void CApplication::slotLoadMessage(int type, QString msg)
{
	switch (type)
	{
	case CPluginMgr::Infomation:
	{
		_splash_screen->showMessage(msg, Qt::AlignLeft | Qt::AlignBottom, Qt::white);
	}
	break;
	case CPluginMgr::Warning:
	{
		_splash_screen->showMessage(msg, Qt::AlignLeft | Qt::AlignBottom, Qt::yellow);
	}
	break;
	case CPluginMgr::Error:
	{
		_splash_screen->showMessage(msg, Qt::AlignLeft | Qt::AlignBottom, Qt::red);
	}
	break;
	default:
	{
		_splash_screen->showMessage(msg, Qt::AlignLeft | Qt::AlignBottom, Qt::black);
	}
	break;
	}


}
