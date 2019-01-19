#ifndef __H_IRESPONSIBILITY_H__
#define __H_IRESPONSIBILITY_H__

#include <QVariant>

class IResponsibility
{
public:
	/*
	* Method:    Request message
	* Access:    virtual public
	* Returns:   bool
	* Parameter: QString type
	*/
	virtual bool request(QString type, QVariant& val) = 0;
	/*
	* Method:    Response message
	* Access:    virtual public
	* Returns:   bool
	* Parameter: QString type
	* Parameter: const QVariant & val
	*/
	virtual bool response(QString type, QVariant val) = 0;

};


#endif // __H_IRESPONSIBILITY_H___
