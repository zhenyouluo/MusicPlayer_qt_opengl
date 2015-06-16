#include "GLWidgetH/glwidget_rightslider.h"

GLWidget_RightSlider::GLWidget_RightSlider(QWidget *parent):QGLWidget(parent)
{

    setMouseTracking(true);
    isActiveButtonAddTracks=false;
    isActiveButtonSettings=false;
    addTrack = false;

    track = "0";

    red=green=blue=1.0;

    isDrawContur=false;
    QTimer *timer = new QTimer(this);
    timer->setInterval(33);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start();


}

void GLWidget_RightSlider::setColorWidget(float red, float green, float blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void GLWidget_RightSlider::drawContur()
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


void GLWidget_RightSlider::drawButtons()
{
    glColor3f(red,green,blue);

    //Добавить ТРЕКИ

    if(isActiveButtonAddTracks==true)
    {
        static GLuint btnAddTracksActive = bindTexture(QImage("Textures/GLWidgetTextures/RightSlider/btnAddTracksActive.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnAddTracksActive);
    }
    else
    {
        static GLuint btnAddTracks = bindTexture(QImage("Textures/GLWidgetTextures/RightSlider/btnAddTracks.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnAddTracks);
    }





    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5);
    glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2-5,windowHeight/2-5);
    glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2-5,windowHeight/2-5-windowHeight*0.15);
    glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5-windowHeight*0.15);
    glEnd();

    //Settings


    if(isActiveButtonSettings==true)
    {
        static GLuint btnSettingsActive = bindTexture(QImage("Textures/GLWidgetTextures/RightSlider/btnSettingsActive.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnSettingsActive);
    }
    else
    {
        static GLuint btnSettings = bindTexture(QImage("Textures/GLWidgetTextures/RightSlider/btnSettings.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnSettings);

    }
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5-windowHeight*0.75);
    glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2-5,windowHeight/2-5-windowHeight*0.75);
    glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2-5,windowHeight/2-5-windowHeight*0.90);
    glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5-windowHeight*0.90);
    glEnd();

}


void GLWidget_RightSlider::showSlider()
{
    if(red < 1)
    {
        red+=0.05;
        green+=0.05;
        blue+=0.05;
    }

}
void GLWidget_RightSlider::closeSlider()
{
    if(red>0.0)
    {
        red-=0.01;
        green-=0.01;
        blue-=0.01;
    }

}

void GLWidget_RightSlider::initializeGL()
{
    glEnable(GL_TEXTURE_2D);     // Разрешение наложение текстуры
    glShadeModel( GL_SMOOTH );// Разрешить плавное цветовое сглаживание
    glClearDepth( 1.0f );// Разрешить очистку буфера глубины
    glEnable( GL_DEPTH_TEST );// Разрешить тест глубины
    glDepthFunc( GL_LEQUAL ); // Тип теста глубины
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );// Улучшение в вычислении перспективы
}

void GLWidget_RightSlider::resizeGL(int width, int height)
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


void GLWidget_RightSlider::paintGL()
{

    glClearColor(0.0,0.0,0.0,0.0f);// Очистка экрана в черный цвет
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if(isDrawContur == true)
    {
        //drawContur();
        showSlider();
    }
    else
    {
        closeSlider();
    }


    drawButtons();

}
void GLWidget_RightSlider::enterEvent(QEvent * event)
{
    if(event->isAccepted()){}
    isDrawContur=true;
}

void GLWidget_RightSlider::leaveEvent(QEvent * event)
{
    if(event->isAccepted()){}
    isDrawContur=false;
}

void GLWidget_RightSlider::mouseMoveEvent(QMouseEvent *pe)
{
    if(pe->x()> windowWidth*0.25 && pe->x() < windowWidth*0.65 && pe->y() < windowHeight*0.14  && pe->y() > windowHeight*0.03)
    {
        isActiveButtonAddTracks=true;
    }
    else
    {
        isActiveButtonAddTracks=false;
    }


    if(pe->x()> windowWidth*0.20 && pe->x() < windowWidth*0.80 && pe->y() < windowHeight*0.89  && pe->y() > windowHeight*0.78)
    {
        isActiveButtonSettings=true;
    }
    else
    {
        isActiveButtonSettings=false;
    }

}


void GLWidget_RightSlider::mousePressEvent(QMouseEvent *pe)
{
    if(pe->button() == Qt::LeftButton && pe->x()> windowWidth*0.25 && pe->x() < windowWidth*0.65 && pe->y() < windowHeight*0.14  && pe->y() > windowHeight*0.03)
    {
        QFileDialog* fileDialog = new QFileDialog;
        track =  fileDialog->getOpenFileName(0,"AddTracks","","*.mp3");

        if(track.isEmpty() == true)
        {

        }
        else
        {
            addTrack = true;
        }
        delete fileDialog;
    }

}


bool GLWidget_RightSlider::returnAddTrack()
{
    return addTrack;
}

void GLWidget_RightSlider::setAddTrack()
{
    addTrack  = false;
}


bool GLWidget_RightSlider::returnFlagActiveButtonTracks()
{
    return isActiveButtonAddTracks;
}

bool GLWidget_RightSlider::returnFlagActiveButtonSettings()
{
    return isActiveButtonSettings;
}
