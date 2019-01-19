#include "AsynchronousThread.h"

#include "IFacade.h"
#include "IResponsibility.h"

#include "PluginCfg.h"
#include "PluginInfo.h"

#include <QMutexLocker>


CAsynchronousThread* CAsynchronousThread::_instance = new CAsynchronousThread();


CAsynchronousThread* CAsynchronousThread::instance()
{
	return _instance;
}


void CAsynchronousThread::enqueue_request(IFacade* facade, QString type)
{
	if (!facade)
	{
		return;
	}
	QMutexLocker locker(&_mutex);
	StRequest request;
	request.facade = facade;
	request.type = type;
	_queue_request.enqueue(request);


}

bool CAsynchronousThread::getRun() const
{
	return _run;
}

void CAsynchronousThread::setRun(bool val)
{
	_run = val;
}

CAsynchronousThread::CAsynchronousThread(QObject* parent /*= nullptr*/)
	: QThread(parent)
	, _run(true)
{

}

CAsynchronousThread::~CAsynchronousThread()
{
	if (_run || this->isRunning())
	{
		_run = false;
		this->quit();
		this->wait();
	}
}

void CAsynchronousThread::run()
{
	QVector<CPluginInfo*> vectPlugins = CPluginCfg::instance()->getPluginsInfo();
	while (_run)
	{
		while (!_queue_request.isEmpty())
		{
			StRequest request = _queue_request.dequeue();

			for (CPluginInfo* pCfg : vectPlugins)
			{
				if (pCfg->getObject())
				{
					QMutexLocker locker(&_mutex);
					IResponsibility* pResponsibility = dynamic_cast<IResponsibility*>(pCfg->getObject());

					QVariant val;
					if (pResponsibility->request(request.type, val))
					{
						locker.unlock();
						emit response_msg(request.facade, request.type, val);
						break;
					}
				}
			}
		}
		sleep(10);
	}
}
