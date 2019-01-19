#include "PluginInfo.h"

CPluginInfo::CPluginInfo()
	: _loader(nullptr)
	, _object(nullptr)
{

}

CPluginInfo::~CPluginInfo()
{

}

QString CPluginInfo::getName() const
{
	return _name;
}

void CPluginInfo::setName(QString val)
{
	_name = val;
}

QString CPluginInfo::getPath() const
{
	return _path;
}

void CPluginInfo::setPath(QString val)
{
	_path = val;
}

QString CPluginInfo::getDescribe() const
{
	return _describe;
}

void CPluginInfo::setDescribe(QString val)
{
	_describe = val;
}

QString CPluginInfo::getVision() const
{
	return _vision;
}

void CPluginInfo::setVision(QString val)
{
	_vision = val;
}

QPluginLoader* CPluginInfo::getLoader() const
{
	return _loader;
}

void CPluginInfo::setLoader(QPluginLoader* val)
{
	_loader = val;
}

bool CPluginInfo::getLoad() const
{
	return _load;
}

void CPluginInfo::setLoad(bool val)
{
	_load = val;
}

QObject* CPluginInfo::getObject() const
{
	return _object;
}

void CPluginInfo::setObject(QObject* val)
{
	_object = val;
}
