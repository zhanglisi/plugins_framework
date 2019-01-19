#ifndef __H_MEDIATOR_H__
#define __H_MEDIATOR_H__

#include <QObject>

#include "IMediator.h"
#include <QMultiHash>


class CMediator
	: QObject
	, public IMediator
{
	Q_OBJECT
public:
	explicit CMediator(QObject* parent = nullptr);
	virtual ~CMediator();

	virtual bool subscribe(IFacade* facade, QString type) final;

	virtual bool publish(QString type, QVariant val) final;

	virtual bool request(IFacade* facade, QString type) final;

	virtual bool execute(QString command, QVariant& val) final;

private:
	void slot_response(IFacade* facade, QString type, QVariant val);

private:
	void init();

private:
	QMultiHash<IFacade*, QString> _hash_subscribe;

};


#endif // __H_MEDIATOR_H___
