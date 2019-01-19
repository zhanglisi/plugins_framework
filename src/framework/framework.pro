#-------------------------------------------------
#
# Project created by QtCreator 2018-10-7T10:24:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Launcher

TEMPLATE = app

DESTDIR = ../../bin


INCLUDEPATH += \
	./ \
	../include \
	../include/common \
	

HEADERS += \
	PluginMgr.h \
	PluginCfg.h \
	PluginInfo.h \
	Application.h \
	Mediator.h \
	AsynchronousThread.h \
	
	

SOURCES += \
	main.cpp \
	PluginMgr.cpp \
	PluginCfg.cpp \
	PluginInfo.cpp \
	Application.cpp \
	Mediator.cpp \
	AsynchronousThread.cpp \
	




FORMS += 


#资源文件
RESOURCES += resources.qrc



#contains(QT_ARCH, i386){
#	DESTDIR = ../../bin/x86
#}
#else{
#	DESTDIR = ../../bin/x64
#}

#DEFINES += X11


LIBS += 


CONFIG(debug, debug|release){
	TARGET = $$join(TARGET,,,d)
}
else{
	
}

CONFIG(debug, debug|release){
	UI_DIR = debug
	OBJECTS_DIR = debug
	MOC_DIR = debug
	RCC_DIR = debug
}
else{
	UI_DIR = release
	OBJECTS_DIR = release
	MOC_DIR = release
	RCC_DIR = release
}

