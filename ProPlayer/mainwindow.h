#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QTimer>
#include <QPoint>
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLayout>
#include <QIcon>

#include "GLWidgetH/glwidget_mainsaver.h"
#include "GLWidgetH/glwidget_mainmenu.h"
#include "GLWidgetH/glwidget_leftslider.h"
#include "GLWidgetH/glwidget_rightslider.h"
#include "GLWidgetH/glwidget_runstring.h"
#include "GLWidgetH/glwidget_track.h"
#include "GLWidgetH/glwidget_player.h"
#include "PlayerH/player.h"



class MainWindow : public QMainWindow
{

    Q_OBJECT

typedef unsigned int uint;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setMainWidget();   //Настраивает главное окно
    void setGLWidgets();   //Настраивает все виджеты OpenGL

private slots:
    void checkFlagsWidgets(); //Проверяет настройки всех виджетов

protected:

    void mouseMoveEvent(QMouseEvent *);
    void enterEvent(QEvent *);
    void keyPressEvent(QKeyEvent *);

private:
    GLWidget_MainSaver* mainSaver;
    GLWidget_MainMenu* mainMenu;
    GLWidget_LeftSlider* leftSlider;
    GLWidget_RightSlider* rightSlider;
    GLWidget_RunString* runString;
    GLWidget_Track* track;
    GLWidget_Player* player;

    Player* musicPlayer;
    QIcon icon;

    float mainWidth;
    float mainHeight;
    int posX;
    int posY;



};

#endif // MAINWINDOW_H
