#include <QPluginLoader>

#include "PluginMgr.h"
#include "PluginCfg.h"
#include "PluginInfo.h"

CPluginMgr* CPluginMgr::_plugin_mgr = new CPluginMgr();

CPluginMgr::CPluginMgr(QObject* parent/* = nullptr*/)
	: QObject(parent)
{
	
}

CPluginMgr* CPluginMgr::instance()
{
	return _plugin_mgr;
}

CPluginMgr::~CPluginMgr()
{

}

void CPluginMgr::initialization()
{
	init();
}

void CPluginMgr::init()
{

	CPluginCfg::instance()->initialization();

	QVector<CPluginInfo*> pluginInfos = CPluginCfg::instance()->getPluginsInfo();


	for (CPluginInfo* info : pluginInfos)
	{
		if (!info->getLoad())
		{
			continue;
		}
		QString loader_path;
#ifndef X11
		loader_path = info->getPath() + "/" + info->getName() + ".dll";
#else
		loader_path = info->getPath() + "/"  + info->getName() + ".so";
#endif // !X11
		QPluginLoader* loader = new QPluginLoader();
		loader->setFileName(loader_path);

		info->setLoader(loader);

		QString strInfo;
		MsgLevel eLevel;
		if (loader->load())
		{
			info->setObject(loader->instance());
			eLevel = Infomation;
			strInfo = "load " + loader->fileName() + " success.";
		}
		else
		{
			eLevel = Error;
			strInfo = info->getName() + ":" + loader->errorString();
		}

		emit loadMessage(eLevel, strInfo);
	}

}

