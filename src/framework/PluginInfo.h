#ifndef __H_PLUGININFO_H__
#define __H_PLUGININFO_H__

#include <QString>

class QPluginLoader;
class QObject;

class CPluginInfo
{
public:
	explicit CPluginInfo();
	virtual ~CPluginInfo();

	QString getName() const;
	void setName(QString val);

	QString getPath() const;
	void setPath(QString val);

	QString getDescribe() const;
	void setDescribe(QString val);

	QString getVision() const;
	void setVision(QString val);

	QPluginLoader* getLoader() const;
	void setLoader(QPluginLoader* val);

	bool getLoad() const;
	void setLoad(bool val);

	QObject* getObject() const;
	void setObject(QObject* val);
private:

	QString _name;
	QString _path;
	QString _describe;
	QString _vision;
	bool _load;
	QPluginLoader* _loader;
	QObject* _object;

};

#endif // __H_PLUGININFO_H___
