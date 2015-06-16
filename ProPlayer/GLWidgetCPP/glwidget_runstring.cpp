#include "GLWidgetH/glwidget_runstring.h"

GLWidget_RunString::GLWidget_RunString(QWidget *parent):QGLWidget(parent)
{

    runString = "This is run string...";

    red=1.0;
    green=1.0;
    blue=1.0;

    coordPointString = 0;

    isDrawContur=false;
QTimer *timer = new QTimer(this);
    timer->setInterval(33);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start();


}

void GLWidget_RunString::setRunString(QString str)
{
    runString = str;
}

QString GLWidget_RunString::getRunString()
{
    return runString;
}

void GLWidget_RunString::setColorWidget(float red, float green, float blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}


void GLWidget_RunString::drawContur()
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


void GLWidget_RunString::drawString()
{

    glColor3f(red,green,blue);
    glWrite(-windowWidth/2+5+coordPointString, 0, (int*)GLUT_BITMAP_HELVETICA_10, (char*)runString.data(), runString.size()*2);

    /*
    //Строка
    static GLuint runString = bindTexture(QImage("Textures/GLWidgetTextures/RunString/RunString.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                glBindTexture(GL_TEXTURE_2D, runString);

    glColor3f(red,green,blue);

    glBegin(GL_QUADS);
       glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5+coordPointString,windowHeight/2-5);
       glTexCoord2d(1.0, 1.0); glVertex2i(-windowWidth/2+5+windowWidth*0.2+coordPointString,windowHeight/2-5);
       glTexCoord2d(1.0, 0.0); glVertex2i(-windowWidth/2+5+windowWidth*0.2+coordPointString,-windowHeight/2+5);
       glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+5+coordPointString,-windowHeight/2+5);
    glEnd();

*/

}


void GLWidget_RunString::showRunString()
{
    if(red < 1)
    {
        red+=0.05;
        green+=0.05;
        blue+=0.05;
    }

}
void GLWidget_RunString::closeRunString()
{
    if(red>0.0)
    {
    red-=0.005;
    green-=0.005;
    blue-=0.005;
    }

}

void GLWidget_RunString::moveString()
{
    if(coordPointString < windowWidth)
    {
    coordPointString+=1;
    }
    else
    {
    coordPointString=0;
    }
}

void GLWidget_RunString::glWrite(float x, float y, int *font, char text[256], int kls) {
    int i;
    glRasterPos2f(x, y);
    for (i=0; i<kls; i++)
        glutBitmapCharacter(font, (int)text[i]);
}


void GLWidget_RunString::initializeGL()
{
    glEnable(GL_TEXTURE_2D);     // Разрешение наложение текстуры
    glShadeModel( GL_SMOOTH );// Разрешить плавное цветовое сглаживание
    glClearDepth( 1.0f );// Разрешить очистку буфера глубины
    glEnable( GL_DEPTH_TEST );// Разрешить тест глубины
    glDepthFunc( GL_LEQUAL ); // Тип теста глубины
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );// Улучшение в вычислении перспективы
}

void GLWidget_RunString::resizeGL(int width, int height)
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


void GLWidget_RunString::paintGL()
{

    glClearColor(0.0,0.0,0.0,0.0f);// Очистка экрана в черный цвет
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if(isDrawContur == true)
    {
   //drawContur();
   showRunString();
    }
    else
    {
        closeRunString();
    }


    drawString();
    moveString();

}
void GLWidget_RunString::enterEvent(QEvent * event)
{
    if(event->isAccepted()){}
    isDrawContur=true;
}

void GLWidget_RunString::leaveEvent(QEvent * event)
{
    if(event->isAccepted()){}
    isDrawContur=false;
}
