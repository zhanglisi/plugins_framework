#include <QObject>

#include "Mediator.h"
#include "IFacade.h"

#include "IObserver.h"
#include "IResponsibility.h"
#include "ICommand.h"

#include "PluginCfg.h"
#include "PluginInfo.h"

#include "AsynchronousThread.h"



CMediator::CMediator(QObject* parent)
	: QObject(parent)
{
	init();
}

CMediator::~CMediator()
{

}

bool CMediator::subscribe(IFacade* facade, QString type)
{
	bool success = false;

	if (!_hash_subscribe.contains(facade, type))
	{
		_hash_subscribe.insert(facade, type);
		success = true;
	}

	return success;
}

bool CMediator::publish(QString type, QVariant val)
{
	bool success = false;

	auto iter = _hash_subscribe.constBegin();
	while (iter != _hash_subscribe.constEnd())
	{
		if (iter.value() == type)
		{
			IObserver* pObserver = dynamic_cast<IObserver*>(iter.key());

			success = pObserver->receive(type, val);
		}
		iter++;
	}

	return success;
}

bool CMediator::request(IFacade* facade, QString type)
{
	bool bRet = true;

	CAsynchronousThread::instance()->enqueue_request(facade, type);

// 	QVector<CPluginInfo*> vectPlugins = CPluginCfg::instance()->getPluginsInfo();
// 
// 	for (CPluginInfo* pCfg : vectPlugins)
// 	{
// 		if (pCfg->getObject())
// 		{
// 			IResponsibility* pResponsibility = dynamic_cast<IResponsibility*>(pCfg->getObject());
// 
// 			QVariant val;
// 			if (pResponsibility->request(type, val))
// 			{
// 				facade->response(type, val);
// 				bRet = true;
// 				break;
// 			}
// 		}
// 	}
	return bRet;
}

bool CMediator::execute(QString command, QVariant& val)
{
	bool bRet = false;
	QVector<CPluginInfo*> vectPlugins = CPluginCfg::instance()->getPluginsInfo();

	for (CPluginInfo* pCfg : vectPlugins)
	{
		if (pCfg->getObject())
		{
			ICommand* pCommand = dynamic_cast<ICommand*>(pCfg->getObject());

			if (pCommand->execute(command, val))
			{
				bRet = true;
				break;
			}
		}
	}
	return bRet;
}
bool CMediator::execute(QString command, void** val)
{
	
	return false;
}

void CMediator::slot_response(IFacade* facade, QString type, QVariant val)
{
	if (facade)
	{
		facade->response(type, val);
	}
}

void CMediator::init()
{
	connect(CAsynchronousThread::instance(), SIGNAL(response_msg(IFacade*, QString, QVariant)), this, SLOT(slot_response(IFacade*, QString, QVariant)));
}

