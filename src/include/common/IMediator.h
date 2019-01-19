#ifndef __H_IMEDIATOR_H__
#define __H_IMEDIATOR_H__

#include <QString>
#include <QVariant>

class IFacade;

class IMediator
{
public:
	/*
	* Method:    Subscribe to messages
	* Access:    virtual public
	* Returns:   bool
	* Parameter: QString type
	*/
	virtual bool subscribe(IFacade* facade, QString type) = 0;
	/*
	 * Method:    publish
	 * Access:    virtual public 
	 * Returns:   bool
	 * Parameter: QString type
	 * Parameter: QVariant val
	 */
	virtual bool publish(QString type, QVariant val) = 0;
	/*
	* Method:    Request message
	* Access:    virtual public
	* Returns:   bool
	* Parameter: QString type
	*/
	virtual bool request(IFacade* facade, QString type) = 0;
	/*
	 * Method:    execute
	 * Access:    virtual public 
	 * Returns:   bool
	 * Parameter: QString command
	 * Parameter: QVariant & val
	 */
	virtual bool execute(QString command, QVariant& val) = 0;

};


#endif // __H_IMEDIATOR_H__
