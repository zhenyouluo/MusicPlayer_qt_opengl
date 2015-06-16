#include "GLWidgetH/glwidget_track.h"

GLWidget_Track::GLWidget_Track(QWidget *parent):QGLWidget(parent)
{
    setMouseTracking(true);
    coordSlider = 0;//465 - max
    lengthTrack = 0;
    msInPixel = 0;
    shiftUnit = 0;
    positionTrack = 0;
    isActiveSlider = false;
    isButtonSlider = false;
    red=green=blue=1.0;
    isDrawContur=false;

    QTimer *timer = new QTimer(this);
    timer->setInterval(33);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start();



}

void GLWidget_Track::setLenTrack(float length)
{
    this->lengthTrack = length;
    msInPixel = lengthTrack/float(465);
}

void GLWidget_Track::setPositionTrack(float positionTrack)
{
    this->positionTrack = positionTrack;
}


void GLWidget_Track::setColorWidget(float red, float green, float blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void GLWidget_Track::drawContur()
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


void GLWidget_Track::drawStrip()
{
    glColor3f(red,green,blue);
    //strip
    static GLuint strip = bindTexture(QImage("Textures/GLWidgetTextures/Track/Strip.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                glBindTexture(GL_TEXTURE_2D, strip);

    glBegin(GL_QUADS);
       glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5,windowHeight/2*0.1);
       glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2-5,windowHeight/2*0.1);
       glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2-5,-windowHeight/2*0.1);
       glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+5,-windowHeight/2*0.1);
    glEnd();

}


void GLWidget_Track::drawSlider()
{
    glColor3f(red,green,blue);

    //strip

    if(isActiveSlider==true)
    {
        static GLuint sliderActive = bindTexture(QImage("Textures/GLWidgetTextures/Track/SliderActive.bmp"), GL_TEXTURE_2D, GL_RGBA);
            glBindTexture(GL_TEXTURE_2D, sliderActive);
    }
    else
    {
        static GLuint slider = bindTexture(QImage("Textures/GLWidgetTextures/Track/Slider.bmp"), GL_TEXTURE_2D, GL_RGBA);
            glBindTexture(GL_TEXTURE_2D, slider);
    }


    glBegin(GL_QUADS);
       glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5+coordSlider,windowHeight/2-5);
       glTexCoord2d(1.0, 1.0); glVertex2i(-windowWidth/2+5+windowWidth*0.05+coordSlider,windowHeight/2-5);
       glTexCoord2d(1.0, 0.0); glVertex2i(-windowWidth/2+5+windowWidth*0.05+coordSlider,-windowHeight/2+5);
       glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+5+coordSlider,-windowHeight/2+5);
    glEnd();

}


void GLWidget_Track::showTrack()
{
    if(red < 1)
    {
        red+=0.05;
        green+=0.05;
        blue+=0.05;
    }

}
void GLWidget_Track::closeTrack()
{
    if(red>0.0)
    {
    red-=0.005;
    green-=0.005;
    blue-=0.005;
    }

}

void GLWidget_Track::initializeGL()
{
    glEnable(GL_TEXTURE_2D);     // Разрешение наложение текстуры
    glShadeModel( GL_SMOOTH );// Разрешить плавное цветовое сглаживание
    glClearDepth( 1.0f );// Разрешить очистку буфера глубины
    glEnable( GL_DEPTH_TEST );// Разрешить тест глубины
    glDepthFunc( GL_LEQUAL ); // Тип теста глубины
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );// Улучшение в вычислении перспективы
}

void GLWidget_Track::resizeGL(int width, int height)
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


void GLWidget_Track::paintGL()
{

    glClearColor(0.0,0.0,0.0,0.0f);// Очистка экрана в черный цвет
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //Условия для ползунка
    if(coordSlider>465)
    {
        coordSlider=465;
    }
    if(coordSlider<0)
    {
        coordSlider=0;
    }

    if(isDrawContur == true)
    {
   //drawContur();
   showTrack();
    }
    else
    {
        closeTrack();
    }


    if(msInPixel!=0)
    coordSlider = positionTrack / msInPixel;

    drawStrip();
    drawSlider();

    if(isActiveSlider)
    drawNums();




}
void GLWidget_Track::enterEvent(QEvent * event)
{
    if(event->isAccepted()){}
    isDrawContur=true;
}

void GLWidget_Track::leaveEvent(QEvent * event)
{
    if(event->isAccepted()){}
    isDrawContur=false;
}


void GLWidget_Track::mouseMoveEvent(QMouseEvent *pe)
{
    if(pe->x()> windowWidth*0.01+coordSlider && pe->x() < windowWidth*0.05+5+coordSlider && pe->y() < windowHeight*0.95 && pe->y() > windowHeight*0.05)
    {
    isActiveSlider=true;
    }
    else
    {
    isActiveSlider=false;
    }

    //Движение ползунка
    if(isButtonSlider==true)
    {


        if(coordSlider<=465 && coordSlider>=0)
            coordSlider=pe->x()-20;
    }

}

void GLWidget_Track::mousePressEvent(QMouseEvent *mpe)
{

    //Нажать кнопку ползунка
    if(mpe->button() == Qt::LeftButton && isActiveSlider == true)
    {
        isButtonSlider=true;
    }
    else
    {
        isButtonSlider=false;
    }
}

void GLWidget_Track::mouseReleaseEvent(QMouseEvent *mre)
{

    if(mre->x()){}
    if(isButtonSlider==true)
    {
        isButtonSlider=false;

    }
}

void GLWidget_Track::second()
{
     coordSlider+=shiftUnit;
}


void GLWidget_Track::glWrite(float x, float y, int *font, char text[256], int kls) {
    int i;
    glRasterPos2f(x, y);
    for (i=0; i<kls; i++)
        glutBitmapCharacter(font, (int)text[i]);
}


void GLWidget_Track::drawNums()
{

    int pos = positionTrack;
    pos/=1000;
    QString str=QString::number(pos);
    glColor3f(0.0,0.0,0.0);
        glWrite(-windowWidth/2+coordSlider+8, -3, (int*)GLUT_BITMAP_HELVETICA_10, (char*)str.data(), str.size()*2);
}
