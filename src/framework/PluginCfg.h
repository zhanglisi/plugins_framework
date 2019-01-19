#ifndef __H_PLUGINCFG_H__
#define __H_PLUGINCFG_H__

#include <QVector>

class CPluginInfo;

class CPluginCfg
{
public:
	static CPluginCfg* instance();

	virtual ~CPluginCfg();

	QVector<CPluginInfo*> getPluginsInfo() const;


	void initialization();

	
protected:
	explicit CPluginCfg();

	void init();

private:
	static CPluginCfg* _plugin_cfg;

private:
	QVector<CPluginInfo*> _plugins_info;

};


#endif // __H_PLUGINCFG_H___
