#include "GLWidgetH/glwidget_leftslider.h"

GLWidget_LeftSlider::GLWidget_LeftSlider(QWidget *parent):QGLWidget(parent)
{

    setMouseTracking(true);
    isDrawContur=false;
    isActiveButtonTracks=false;
    isActiveButtonAlbums=false;
    isActiveButtonGenres=false;
    isActiveButtonPlaylists=false;


    red=green=blue=1.0;

QTimer *timer = new QTimer(this);
    timer->setInterval(33);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start();


}

bool GLWidget_LeftSlider::returnFlagActiveButtonTracks()
{
    return isActiveButtonTracks;
}
bool GLWidget_LeftSlider::returnFlagActiveButtonAlbums()
{
    return isActiveButtonAlbums;
}
bool GLWidget_LeftSlider::returnFlagActiveButtonGenres()
{
    return isActiveButtonGenres;
}
bool GLWidget_LeftSlider::returnFlagActiveButtonPlaylists()
{
    return isActiveButtonPlaylists;
}
bool GLWidget_LeftSlider::returnFlagPressButtonTracks()
{
    return isPressButtonTracks;
}

void GLWidget_LeftSlider::setColorWidget(float red, float green, float blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void GLWidget_LeftSlider::drawContur()
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



void GLWidget_LeftSlider::drawButtons()
{
    glColor3f(red,green,blue);

    //ТРЕКИ
    if(isActiveButtonTracks==true){

        static GLuint btnTracksActive = bindTexture(QImage("Textures/GLWidgetTextures/LeftSlider/btnTracksActive.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnTracksActive);

    }

    else{
        static GLuint btnTracks = bindTexture(QImage("Textures/GLWidgetTextures/LeftSlider/btnTracks.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnTracks);
    }

    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5);
    glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2-5,windowHeight/2-5);
    glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2-5,windowHeight/2-5-windowHeight*0.15);
    glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5-windowHeight*0.15);
 glEnd();


    //АЛЬБОМЫ

    if(isActiveButtonAlbums==true){
        static GLuint btnAlbumsActive = bindTexture(QImage("Textures/GLWidgetTextures/LeftSlider/btnAlbumsActive.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnAlbumsActive);
    }
    else{
    static GLuint btnAlbums = bindTexture(QImage("Textures/GLWidgetTextures/LeftSlider/btnAlbums.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                glBindTexture(GL_TEXTURE_2D, btnAlbums);

    }
    glBegin(GL_QUADS);
        glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5-windowHeight*0.15);
        glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2-5,windowHeight/2-5-windowHeight*0.15);
        glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2-5,windowHeight/2-5-windowHeight*0.30);
        glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5-windowHeight*0.30);
    glEnd();


    //ЖАНРЫ
    if(isActiveButtonGenres==true){
        static GLuint btnGenreActive = bindTexture(QImage("Textures/GLWidgetTextures/LeftSlider/btnGenreActive.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnGenreActive);
    }
    else{
    static GLuint btnGenre = bindTexture(QImage("Textures/GLWidgetTextures/LeftSlider/btnGenre.bmp"), GL_TEXTURE_2D, GL_RGBA);
                               glBindTexture(GL_TEXTURE_2D, btnGenre);
    }

    glBegin(GL_QUADS);
       glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5-windowHeight*0.30);
       glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2-5,windowHeight/2-5-windowHeight*0.30);
       glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2-5,windowHeight/2-5-windowHeight*0.45);
       glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5-windowHeight*0.45);
    glEnd();



    //Плейлисты
    if(isActiveButtonPlaylists==true){
        static GLuint btnPlaylistsActive = bindTexture(QImage("Textures/GLWidgetTextures/LeftSlider/btnPlaylistsActive.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnPlaylistsActive);
    }
    else{
        static GLuint btnPlaylists = bindTexture(QImage("Textures/GLWidgetTextures/LeftSlider/btnPlaylists.bmp"), GL_TEXTURE_2D, GL_RGBA);
                                    glBindTexture(GL_TEXTURE_2D, btnPlaylists);
    }
        glBegin(GL_QUADS);
           glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5-windowHeight*0.45);
           glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2-5,windowHeight/2-5-windowHeight*0.45);
           glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2-5,windowHeight/2-5-windowHeight*0.60);
           glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5-windowHeight*0.60);
        glEnd();



}


void GLWidget_LeftSlider::showSlider()
{
    if(red < 1)
    {
        red+=0.05;
        green+=0.05;
        blue+=0.05;
    }

}
void GLWidget_LeftSlider::closeSlider()
{
    if(red>0.0)
    {
    red-=0.01;
    green-=0.01;
    blue-=0.01;
    }

}


void GLWidget_LeftSlider::initializeGL()
{
    glEnable(GL_TEXTURE_2D);     // Разрешение наложение текстуры
    glShadeModel( GL_SMOOTH );// Разрешить плавное цветовое сглаживание
    glClearDepth( 1.0f );// Разрешить очистку буфера глубины
    glEnable( GL_DEPTH_TEST );// Разрешить тест глубины
    glDepthFunc( GL_LEQUAL ); // Тип теста глубины
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );// Улучшение в вычислении перспективы
}

void GLWidget_LeftSlider::resizeGL(int width, int height)
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


void GLWidget_LeftSlider::paintGL()
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


    drawButtons();

}

void GLWidget_LeftSlider::enterEvent(QEvent * event)
{
    if(event->isAccepted()){}

    isDrawContur=true;
}

void GLWidget_LeftSlider::leaveEvent(QEvent * event)
{
    if(event->isAccepted()){}

    isDrawContur=false;
}

void GLWidget_LeftSlider::mouseMoveEvent(QMouseEvent *pe)
{
    if(pe->x()> windowWidth*0.30 && pe->x() < windowWidth*0.65 && pe->y() < windowHeight*0.14 && pe->y() > windowHeight*0.05)
    {
    isActiveButtonTracks=true;
    }
    else
    {
    isActiveButtonTracks=false;
    }

    if(pe->x()> windowWidth*0.30 && pe->x() < windowWidth*0.65 && pe->y() < windowHeight*0.29 && pe->y() > windowHeight*0.20)
    {
    isActiveButtonAlbums=true;
    }
    else
    {
    isActiveButtonAlbums=false;
    }

    if(pe->x()> windowWidth*0.30 && pe->x() < windowWidth*0.65 && pe->y() < windowHeight*0.44 && pe->y() > windowHeight*0.35)
    {
    isActiveButtonGenres =true;
    }
    else
    {
    isActiveButtonGenres=false;
    }

    if(pe->x()> windowWidth*0.30 && pe->x() < windowWidth*0.65 && pe->y() < windowHeight*0.59 && pe->y() > windowHeight*0.50)
    {
    isActiveButtonPlaylists =true;
    }
    else
    {
    isActiveButtonPlaylists=false;
    }

}

void GLWidget_LeftSlider::mousePressEvent(QMouseEvent *mpe)
{
    if(mpe->button()==Qt::LeftButton && isActiveButtonTracks && isPressButtonTracks)
    {
        isPressButtonTracks = false;
    }
    else
    {
        if(mpe->button()==Qt::LeftButton && isActiveButtonTracks)
        {
            isPressButtonTracks = true;
        }
    }
}

void GLWidget_LeftSlider::mouseReleaseEvent(QMouseEvent *mre)
{
    if(mre->x()){}

}
