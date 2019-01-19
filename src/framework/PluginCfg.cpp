#include <QSettings>
#include "PluginCfg.h"
#include "PluginInfo.h"


CPluginCfg* CPluginCfg::_plugin_cfg = new CPluginCfg();

CPluginCfg* CPluginCfg::instance()
{
	return _plugin_cfg;
}

CPluginCfg::~CPluginCfg()
{
	for (CPluginInfo* plugin : _plugins_info)
	{
		delete plugin;
		plugin = nullptr;
	}
	_plugins_info.clear();
}

QVector<CPluginInfo*> CPluginCfg::getPluginsInfo() const
{
	return _plugins_info;
}

void CPluginCfg::initialization()
{
	init();
}

CPluginCfg::CPluginCfg()
{
	
}

void CPluginCfg::init()
{
	QSettings settings("../config/plugins.cfg", QSettings::IniFormat);

	QStringList groups = settings.childGroups();

	for (QString group : groups)
	{
		CPluginInfo* plugin = new CPluginInfo();

		plugin->setName(settings.value(group + "/name").toString());
		plugin->setPath(settings.value(group + "/path").toString());
		plugin->setDescribe(settings.value(group + "/desc").toString());
		plugin->setVision(settings.value(group + "/vision").toString());
		plugin->setLoad(settings.value(group + "/load").toInt());

		_plugins_info << plugin;
	}
}

