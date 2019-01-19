#ifndef __H_PORLORLOGFACADE_H__
#define __H_PORLORLOGFACADE_H__

#include <QGenericPlugin>
#include "IFacade.h"



class IMediator;

class CPorlorLogFacade
	: public QGenericPlugin
	, public IFacade

{
	Q_OBJECT

#if QT_VERSION >= 0x050000
	Q_PLUGIN_METADATA(IID "{F10E679F-BD03-4F7C-AD40-8DC3B5155B5D}")
#endif // QT_VERSION >= 0x050000

public:
	explicit CPorlorLogFacade(QObject *parent = nullptr);

	virtual ~CPorlorLogFacade();
	// facade
	virtual QString getName() final;

	virtual QString getVersion() final;

	virtual void initialize(IMediator* mediator) final;

	virtual QObject* create(const QString& name, const QString &spec) final;


	// observer
	virtual bool publish(QString type, QVariant val) final;

	virtual bool receive(QString type, QVariant val) final;

	// responsibility
	virtual bool request(QString type, QVariant& val) final;
	virtual bool response(QString type, QVariant val) final;

	// command
	virtual bool execute(QString command, QVariant& val) final;
protected:
	IMediator* _mediator;
};



#endif // __H_PORLORLOGFACADE_H___
