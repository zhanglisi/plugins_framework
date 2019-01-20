#ifndef __H_PLUGINMGR_H__
#define __H_PLUGINMGR_H__

#include <QObject>

class IMediator;


class CPluginMgr
	: public QObject
{
	Q_OBJECT
public:
	static CPluginMgr* instance();

	virtual ~CPluginMgr();

	void initialization(IMediator* mediator);

public:
	enum MsgLevel
	{
		None,
		Infomation,
		Warning,
		Error,
	};

Q_SIGNALS:

	void loadMessage(int type, QString msg);

protected:
	explicit CPluginMgr(QObject* parent = nullptr);

	void init();

private:
	static CPluginMgr* _plugin_mgr;

	IMediator* _mediator;
};


#endif // __H_PLUGINMGR_H___
