#ifndef __H_ICOMMAND_H__
#define __H_ICOMMAND_H__

class ICommand
{
public:
	/*
	 * Method:    execute
	 * Access:    virtual public 
	 * Returns:   bool
	 * Parameter: QString command
	 */
	virtual bool execute(QString command, QVariant& val) = 0;
	
	virtual bool execute(QString command, void** val) = 0;

};


#endif // __H_ICOMMAND_H__
