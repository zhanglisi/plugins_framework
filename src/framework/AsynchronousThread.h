#ifndef __H_ASYNCHRONOUSTHREAD_H__
#define __H_ASYNCHRONOUSTHREAD_H__

#include <QThread>
#include <QQueue>
#include <QMutex>
#include <QVariant>

class IFacade;

class CAsynchronousThread
	: public QThread
{
	Q_OBJECT
public:
	static CAsynchronousThread* instance();

	void enqueue_request(IFacade* facade, QString type);

	bool getRun() const;
	void setRun(bool val);

	struct StRequest 
	{
		IFacade* facade;
		QString type;
		StRequest()
		{
			facade = nullptr;
		}
	};


public:
	explicit CAsynchronousThread(QObject* parent = nullptr);

	virtual ~CAsynchronousThread();


Q_SIGNALS:

	void response_msg(IFacade* facade, QString type, QVariant val);

protected:
	virtual void run() final;

private:
	static CAsynchronousThread* _instance;

	QQueue<StRequest> _queue_request;

	QMutex _mutex;

	bool _run;
};



#endif // __H_ASYNCHRONOUSTHREAD_H___
