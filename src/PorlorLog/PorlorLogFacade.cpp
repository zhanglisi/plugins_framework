#include "PorlorLogFacade.h"
#include "IMediator.h"

CPorlorLogFacade::CPorlorLogFacade(QObject *parent /*= nullptr*/)
	: QGenericPlugin(parent)
{

}

CPorlorLogFacade::~CPorlorLogFacade()
{

}

QString CPorlorLogFacade::getName()
{
	return "PorlorLog";
}

QString CPorlorLogFacade::getVersion()
{
	return "v1.0.0";
}

void CPorlorLogFacade::initialize(IMediator* mediator)
{
	if (mediator)
	{
		mediator->subscribe(this, "LOG");
		mediator->subscribe(this, "WARNING");
		mediator->subscribe(this, "ERROR");
	}

	_mediator = mediator;
}

QObject* CPorlorLogFacade::create(const QString& name, const QString &spec)
{

	return nullptr;
}



bool CPorlorLogFacade::publish(QString type, QVariant val)
{
	if (_mediator)
	{
		return _mediator->publish(type, val);
	}

	return false;
}

bool CPorlorLogFacade::receive(QString type, QVariant val)
{




	return false;
}

bool CPorlorLogFacade::request(QString type, QVariant& val)
{

	return false;
}

bool CPorlorLogFacade::response(QString type, QVariant val)
{

	return false;
}

bool CPorlorLogFacade::execute(QString command, QVariant& val)
{

	return false;
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(PorlorLog, CPorlorLogFacade)
#endif // QT_VERSION < 0x050000
