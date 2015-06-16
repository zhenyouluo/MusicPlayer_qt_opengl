#include "GLWidgetH/glwidget_mainmenu.h"

GLWidget_MainMenu::GLWidget_MainMenu(QWidget *parent):QGLWidget(parent)
{
    setMouseTracking(true);
    isDrawContur=false;
    numHelp = 1;
    red=green=blue=0.0;
    isActiveButtonExit = false;
    isPressButtonExit = false;
    isGrab = false;
    isActiveGrab = false;
    posX=posY=100;

QTimer *timer = new QTimer(this);
    timer->setInterval(33);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start();
}

void GLWidget_MainMenu::setColorWidget(float red, float green, float blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}


void GLWidget_MainMenu::setNumHelp(int num)
{
    numHelp=num;
}

bool GLWidget_MainMenu::returnFlagPressButtonExit()
{
    return isPressButtonExit;
}

int GLWidget_MainMenu::getPosX()
{
    return posX;
}

int GLWidget_MainMenu::getPosY()
{
    return posY;
}

void GLWidget_MainMenu::drawContur()
{
    static GLuint line = bindTexture(QImage("Textures/GLWidgetTextures/MainTextures/line.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                glBindTexture(GL_TEXTURE_2D, line);
    //рисуем рамку.

    //вверх
    glBegin(GL_QUADS);
       glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5,windowHeight/2);
       glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2-5,windowHeight/2);
       glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2-5,windowHeight/2-5);
       glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5);
    glEnd();

    //низ
    glBegin(GL_QUADS);
       glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5,-windowHeight/2);
       glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2-5,-windowHeight/2);
       glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2-5,-windowHeight/2+5);
       glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+5,-windowHeight/2+5);
    glEnd();

    //левая
    glBegin(GL_QUADS);
       glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5);
       glTexCoord2d(1.0, 1.0); glVertex2i(-windowWidth/2+5,-windowHeight/2+5);
       glTexCoord2d(1.0, 0.0); glVertex2i(-windowWidth/2,-windowHeight/2+5);
       glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2,windowHeight/2-5);
    glEnd();

    //правая
    glBegin(GL_QUADS);
       glTexCoord2d(0.0, 1.0); glVertex2i(windowWidth/2,windowHeight/2-5);
       glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2,-windowHeight/2+5);
       glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2-5,-windowHeight/2+5);
       glTexCoord2d(0.0, 0.0); glVertex2i(windowWidth/2-5,windowHeight/2-5);
    glEnd();
}

void GLWidget_MainMenu::drawHelp()
{
    glColor3f(1,1,1);

    switch(numHelp)
    {
    case 1:
    {
    static GLuint proPlayer = bindTexture(QImage("Textures/GLWidgetTextures/MainMenu/ProPlayer.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                glBindTexture(GL_TEXTURE_2D, proPlayer);
    }
    break;
    case 2:
    {
    static GLuint tracks = bindTexture(QImage("Textures/GLWidgetTextures/MainMenu/Tracks.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                glBindTexture(GL_TEXTURE_2D, tracks);
    }
    break;
    case 3:
    {
    static GLuint Albums = bindTexture(QImage("Textures/GLWidgetTextures/MainMenu/Albums.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                glBindTexture(GL_TEXTURE_2D, Albums);
    }
    break;
    case 4:
    {
    static GLuint Genres = bindTexture(QImage("Textures/GLWidgetTextures/MainMenu/Genres.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                glBindTexture(GL_TEXTURE_2D, Genres);
    }
    break;
    case 5:
    {
    static GLuint Playlists = bindTexture(QImage("Textures/GLWidgetTextures/MainMenu/Playlists.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                glBindTexture(GL_TEXTURE_2D, Playlists);
    }
    break;
    case 6:
    {
    static GLuint AddTracks = bindTexture(QImage("Textures/GLWidgetTextures/MainMenu/AddTracks.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                glBindTexture(GL_TEXTURE_2D, AddTracks);
    }
    break;
    case 7:
    {
    static GLuint Settings = bindTexture(QImage("Textures/GLWidgetTextures/MainMenu/Settings.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                glBindTexture(GL_TEXTURE_2D, Settings);
    }
    break;
    }

    glBegin(GL_QUADS);
       glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2,windowHeight/2);
       glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2,windowHeight/2);
       glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2,-windowHeight/2);
       glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2,-windowHeight/2);
    glEnd();



}

void GLWidget_MainMenu::drawArchitecture()
{

    glColor3f(red,green,blue);

    if(isActiveButtonExit == false)
    {
    static GLuint exit1 = bindTexture(QImage("Textures/GLWidgetTextures/MainMenu/exit1.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                glBindTexture(GL_TEXTURE_2D, exit1);
    }
    else
    {
        static GLuint exit2 = bindTexture(QImage("Textures/GLWidgetTextures/MainMenu/exit2.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                    glBindTexture(GL_TEXTURE_2D, exit2);
    }




    glBegin(GL_QUADS);
       glTexCoord2d(0.0, 1.0); glVertex2i(windowWidth/2-28,windowHeight/2-3);
       glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2-3,windowHeight/2-3);
       glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2-3,windowHeight/2-28);
       glTexCoord2d(0.0, 0.0); glVertex2i(windowWidth/2-28,windowHeight/2-28);
    glEnd();

    if(isActiveGrab == false)
    {
        static GLuint btnGrab = bindTexture(QImage("Textures/GLWidgetTextures/MainMenu/grab1.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                    glBindTexture(GL_TEXTURE_2D, btnGrab);

    }
    else
    {
        static GLuint btnGrabActive = bindTexture(QImage("Textures/GLWidgetTextures/MainMenu/grab2.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                    glBindTexture(GL_TEXTURE_2D, btnGrabActive);

    }


    glBegin(GL_QUADS);
       glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+3,windowHeight/2-3);
       glTexCoord2d(1.0, 1.0); glVertex2i(-windowWidth/2+53,windowHeight/2-3);
       glTexCoord2d(1.0, 0.0); glVertex2i(-windowWidth/2+53,windowHeight/2-53);
       glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+3,windowHeight/2-53);
    glEnd();
}

void GLWidget_MainMenu::initializeGL()
{
    glEnable(GL_TEXTURE_2D);     // Разрешение наложение текстуры
    glShadeModel( GL_SMOOTH );// Разрешить плавное цветовое сглаживание
    glClearDepth( 1.0f );// Разрешить очистку буфера глубины
    glEnable( GL_DEPTH_TEST );// Разрешить тест глубины
    glDepthFunc( GL_LEQUAL ); // Тип теста глубины
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );// Улучшение в вычислении перспективы
}

void GLWidget_MainMenu::resizeGL(int width, int height)
{
    if( height == 0 )// Предотвращение деления на ноль
    {
        height = 1;
    }

    windowWidth = width;
    windowHeight = height;

    glViewport( 0, 0, width, height );// Сброс текущей области вывода
    glMatrixMode( GL_PROJECTION );            // Выбор матрицы проекций
    glLoadIdentity();              // Сброс матрицы проекции
    gluOrtho2D(-width/2,width/2,-height/2,height/2);
    glMatrixMode( GL_MODELVIEW );            // Выбор матрицы вида модели
    glLoadIdentity();              // Сброс матрицы вида модели
}


void GLWidget_MainMenu::paintGL()
{

    glClearColor(0.0,0.0,0.0,0.0f);// Очистка экрана в черный цвет
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();



    if(isDrawContur == true)
    {
    showSlider();
    }
    else
    {
    closeSlider();
    }

    drawHelp();
    drawArchitecture();
}

void GLWidget_MainMenu::showSlider()
{
    if(red < 1)
    {
        red+=0.05;
        green+=0.05;
        blue+=0.05;
    }

}
void GLWidget_MainMenu::closeSlider()
{
    if(red>0.0)
    {
    red-=0.1;
    green-=0.1;
    blue-=0.1;
    }

}


void GLWidget_MainMenu::enterEvent(QEvent * event)
{
    if(event->isAccepted()){}

    isDrawContur=true;
}

void GLWidget_MainMenu::leaveEvent(QEvent * event)
{

    if(event->isAccepted()){}

    isDrawContur=false;
}

void GLWidget_MainMenu::mouseMoveEvent(QMouseEvent *pe)
{

    if(pe->x()> windowWidth*0.95 && pe->x() < windowWidth*0.99 && pe->y() < windowHeight*0.27 && pe->y() > windowHeight*0.01)
    {
    isActiveButtonExit=true;
    }
    else
    {
    isActiveButtonExit=false;
    }

    if(pe->x()> windowWidth*0.01 && pe->x() < windowWidth*0.10 && pe->y() < windowHeight*0.40 && pe->y() > windowHeight*0.01)
    {
    isActiveGrab = true;

    }
    else
    {
    isActiveGrab = false;
    }

    if(isGrab==true)
    {
        posX=pe->globalX()-20;
        posY=pe->globalY()-20;
    }

}

void GLWidget_MainMenu::mousePressEvent(QMouseEvent *mpe)
{
    if(mpe->button()==Qt::LeftButton && isActiveButtonExit && isPressButtonExit)
    {
        isPressButtonExit = false;
    }
    else
    {
        if(mpe->button()==Qt::LeftButton && isActiveButtonExit)
        {
            isPressButtonExit = true;
        }
    }

    if(isActiveGrab && mpe->button()==Qt::LeftButton)
    {
        isGrab=true;

    }


}

void GLWidget_MainMenu::mouseReleaseEvent(QMouseEvent *mre)
{

    if(isGrab==true)
    {
        isGrab=false;
    }
}
