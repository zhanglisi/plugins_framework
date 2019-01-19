#ifndef __H_IFACADE_H__
#define __H_IFACADE_H__

#include <QString>

#include "IObserver.h"
#include "IResponsibility.h"
#include "ICommand.h"

class IMediator;

class IFacade
	: public IObserver
	, public IResponsibility
	, public ICommand
{
public:
	/*
	 * Method:    getName
	 * Access:    virtual public 
	 * Returns:   QT_NAMESPACE::QString
	 * Qualifier:
	 */
	virtual QString getName() = 0;
	/*
	 * Method:    getVersion
	 * Access:    virtual public 
	 * Returns:   QT_NAMESPACE::QString
	 * Qualifier:
	 */
	virtual QString getVersion() = 0;
	/*
	 * Method:    initialize
	 * Access:    virtual public 
	 * Returns:   void
	 * Qualifier:
	 * Parameter: IMediator * mediator
	 */
	virtual void initialize(IMediator* mediator) = 0;



};


#endif // __H_IFACADE_H___
