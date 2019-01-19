#ifndef __H_IOBSERVER_H__
#define __H_IOBSERVER_H__

#include <QString>
#include <QVariant>


class IObserver
{
public:

	/*
	* Method:    Publish Message
	* Access:    virtual public
	* Returns:   bool
	* Parameter: QString type
	* Parameter: QVariant val
	*/
	virtual bool publish(QString type, QVariant val) = 0;

	/*
	 * Method:    receive
	 * Access:    virtual public 
	 * Returns:   bool
	 * Parameter: QString type
	 * Parameter: QVariant val
	 */
	virtual bool receive(QString type, QVariant val) = 0;


};

#endif // __H_IOBSERVER_H___
