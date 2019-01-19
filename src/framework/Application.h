#ifndef __H_APPLICATION_H__
#define __H_APPLICATION_H__

#include <QApplication>

class QSplashScreen;

class CApplication
	: public QApplication
{
	Q_OBJECT
public:
	explicit CApplication(int &argc, char **argv);
	virtual ~CApplication();

	void initialization();

	void init_communication();

	void showSplash();
	
	void closeSplash();
protected:
	void init();

private Q_SLOTS:
	void slotLoadMessage(int type, QString msg);
private:
	QSplashScreen* _splash_screen;

};


#endif // __H_APPLICATION_H___
