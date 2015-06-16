#-------------------------------------------------
#
# Project created by QtCreator 2014-12-02T17:45:33
#
#-------------------------------------------------

QT       += core gui opengl multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProPlayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    GLWidgetCPP/glwidget_leftslider.cpp \
    GLWidgetCPP/glwidget_mainmenu.cpp \
    GLWidgetCPP/glwidget_mainsaver.cpp \
    GLWidgetCPP/glwidget_player.cpp \
    GLWidgetCPP/glwidget_rightslider.cpp \
    GLWidgetCPP/glwidget_runstring.cpp \
    GLWidgetCPP/glwidget_track.cpp \
    PlayerCPP/player.cpp

HEADERS  += mainwindow.h \
    GLWidgetH/glwidget_leftslider.h \
    GLWidgetH/glwidget_mainmenu.h \
    GLWidgetH/glwidget_mainsaver.h \
    GLWidgetH/glwidget_player.h \
    GLWidgetH/glwidget_rightslider.h \
    GLWidgetH/glwidget_runstring.h \
    GLWidgetH/glwidget_track.h \
    PlayerH/player.h

LIBS += glut32.lib
