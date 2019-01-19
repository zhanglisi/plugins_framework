#-------------------------------------------------
#
# Project created by QtCreator 2018-10-7T10:24:50
#
#-------------------------------------------------

QT += core gui


TARGET = PorlorLog


TEMPLATE = lib


CONFIG += plugin

DESTDIR = ../../bin


DEFINES += QT_DEPRECATED_WARNINGS \
			POLORLOG_LIB \


INCLUDEPATH += \
	./ \
	../include \
	../include/common \
	
	

SOURCES += PorlorLogFacade.cpp



HEADERS += PorlorLogFacade.h



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

