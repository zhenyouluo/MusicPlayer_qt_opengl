#include "GLWidgetH/glwidget_mainsaver.h"
#include <mainwindow.h>

GLWidget_MainSaver::GLWidget_MainSaver(QWidget *parent):QGLWidget(parent)
{
    isDrawContur=false;
    isShowWindowTracks=false;
    nameTrack = "This is run string...";

    for(int i(0); i<12; i++)
        arrBlue[i]=0.0;

    red=1.0;
    green=1.0;
    blue=1.0;

    QTimer *timer = new QTimer(this);
    timer->setInterval(33);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start();
}
GLWidget_MainSaver::~GLWidget_MainSaver()
{
}

void GLWidget_MainSaver::setShowWindowTracks()
{
    isShowWindowTracks = true;
}

void GLWidget_MainSaver::setCloseWindowTracks()
{
    isShowWindowTracks = false;
}

void GLWidget_MainSaver::setTrack(QString track)
{
    //Преобразование имени трека(удаление полного пути)


    int erase = 0;
    for(int i = 0; i<track.size(); i++)
    {
        if(track[i]=='/')
        {
            erase=i;
        }
    }

    track.remove(0,erase+1);  //Очищаем от слешей

    setNameTrack(track);

    //Проверка длины имени
    if(track.size()>35)
    {
        track.remove(36,track.size()-1);
        track[36]='.';
        track[37]='.';
        track[38]='.';
    }

    tracks.push_back(track);
}



void GLWidget_MainSaver::playTrack(int index)
{
    for(int i(0); i<12; i++)
        arrBlue[i]=0.0;

    arrBlue[index]=0.4;
}
QString GLWidget_MainSaver::getPlayTrack()
{
    return nameTrack;
}

void GLWidget_MainSaver::setColorWidget(float red, float green, float blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void GLWidget_MainSaver::drawContur()
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
void GLWidget_MainSaver::drawSaver()
{




}


void GLWidget_MainSaver::showSaver()
{
    if(red < 1)
    {
        red+=0.01;
        green+=0.01;
        blue+=0.01;
    }

}
void GLWidget_MainSaver::closeSaver()
{
    if(red>0.0)
    {
        red-=0.05;
        green-=0.05;
        blue-=0.05;
    }

}



void GLWidget_MainSaver::initializeGL()
{

    glShadeModel(GL_SMOOTH);    // Разрешить плавное затенение
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // Черный фон
    glClearDepth(1.0f);         // Установка буфера глубины
    glEnable(GL_DEPTH_TEST);    // Разрешение теста глубины
    glDepthFunc(GL_LEQUAL);     // Тип теста глубины
    // Действительно хорошие вычисления перспективы
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void GLWidget_MainSaver::resizeGL(int width, int height)
{
    if( height == 0 )// Предотвращение деления на ноль
    {
        height = 1;
    }

    windowWidth = width;
    windowHeight = height;
    glClearColor(0.0,0.0,0.0,1.0f);// Очистка экрана в черный цвет

    glViewport( 0, 0, width, height );// Сброс текущей области вывода
    glMatrixMode( GL_PROJECTION );            // Выбор матрицы проекций
    glLoadIdentity();              // Сброс матрицы проекции
    gluOrtho2D(-width/2,width/2,-height/2,height/2);
    glMatrixMode( GL_MODELVIEW );            // Выбор матрицы вида модели
    glLoadIdentity();              // Сброс матрицы вида модели
}

void GLWidget_MainSaver::glWrite(float x, float y, int *font, char text[256], int kls) {
    int i;
    glRasterPos2f(x, y);
    for (i=0; i<kls; i++)
        glutBitmapCharacter(font, (int)text[i]);
}

void GLWidget_MainSaver::setNameTrack(QString name)
{
    nameTrack=name;
}

void GLWidget_MainSaver::drawWindowTracks()
{

    glDisable(GL_TEXTURE_2D);
    glColor3f(0.2,0.2,0.2);
    //вверх
    glBegin(GL_LINES);
    glVertex2i(-windowWidth/2+windowWidth*0.05,windowHeight/2);
    glVertex2i(windowWidth/2-windowWidth*0.05,windowHeight/2);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(-windowWidth/2+windowWidth*0.05,windowHeight/2-windowHeight*0.08);
    glVertex2i(windowWidth/2-windowWidth*0.05,windowHeight/2-windowHeight*0.08);
    glEnd();


    //лево
    glBegin(GL_LINES);
    glVertex2i(-windowWidth/2+windowWidth*0.05,windowHeight/2);
    glVertex2i(-windowWidth/2+windowWidth*0.05,-windowHeight/2);
    glEnd();
    //право
    glBegin(GL_LINES);
    glVertex2i(windowWidth/2-windowWidth*0.05,windowHeight/2);
    glVertex2i(windowWidth/2-windowWidth*0.05,-windowHeight/2);
    glEnd();
    //низ
    glBegin(GL_LINES);
    glVertex2i(-windowWidth/2+windowWidth*0.05,-windowHeight/2+1);
    glVertex2i(windowWidth/2-windowWidth*0.05,-windowHeight/2+1);
    glEnd();


    glColor3f(0.3,0.3,0.3);
    glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.06, (int*)GLUT_BITMAP_HELVETICA_18, (char*)"Tracks:", 7);
    //1 string
    glColor3f(0.3,0.3,0.3+arrBlue[0]);
    if(tracks.size()>0)
        glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.17, (int*)GLUT_BITMAP_HELVETICA_18, (char*)tracks[0].data(), tracks[0].size()*2);
    //2 string
    glColor3f(0.3,0.3,0.3+arrBlue[1]);
    if(tracks.size()>1)
        glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.24, (int*)GLUT_BITMAP_HELVETICA_18, (char*)tracks[1].data(), tracks[1].size()*2);
    //3 string
    glColor3f(0.3,0.3,0.3+arrBlue[2]);
    if(tracks.size()>2)
        glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.31, (int*)GLUT_BITMAP_HELVETICA_18, (char*)tracks[2].data(), tracks[2].size()*2);
    //4 string
    glColor3f(0.3,0.3,0.3+arrBlue[3]);
    if(tracks.size()>3)
        glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.38, (int*)GLUT_BITMAP_HELVETICA_18, (char*)tracks[3].data(), tracks[3].size()*2);
    //5 string
    glColor3f(0.3,0.3,0.3+arrBlue[4]);
    if(tracks.size()>4)
        glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.45, (int*)GLUT_BITMAP_HELVETICA_18, (char*)tracks[4].data(), tracks[4].size()*2);
    //6 string
    glColor3f(0.3,0.3,0.3+arrBlue[5]);
    if(tracks.size()>5)
        glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.52, (int*)GLUT_BITMAP_HELVETICA_18, (char*)tracks[5].data(), tracks[5].size()*2);
    //7 string
    glColor3f(0.3,0.3,0.3+arrBlue[6]);
    if(tracks.size()>6)
        glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.59, (int*)GLUT_BITMAP_HELVETICA_18, (char*)tracks[6].data(), tracks[6].size()*2);
    //8 string
    glColor3f(0.3,0.3,0.3+arrBlue[7]);
    if(tracks.size()>7)
        glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.66, (int*)GLUT_BITMAP_HELVETICA_18, (char*)tracks[7].data(), tracks[7].size()*2);
    //9 string
    glColor3f(0.3,0.3,0.3+arrBlue[8]);
    if(tracks.size()>8)
        glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.73, (int*)GLUT_BITMAP_HELVETICA_18, (char*)tracks[8].data(), tracks[8].size()*2);
    //10 string
    glColor3f(0.3,0.3,0.3+arrBlue[9]);
    if(tracks.size()>9)
        glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.80, (int*)GLUT_BITMAP_HELVETICA_18, (char*)tracks[9].data(), tracks[9].size()*2);
    //11 string
    glColor3f(0.3,0.3,0.3+arrBlue[10]);
    if(tracks.size()>10)
        glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.87, (int*)GLUT_BITMAP_HELVETICA_18, (char*)tracks[10].data(), tracks[10].size()*2);
    //12 string
    glColor3f(0.3,0.3,0.3+arrBlue[11]);
    if(tracks.size()>11)
        glWrite(-windowWidth/2+windowWidth*0.1, windowHeight/2-windowHeight*0.94, (int*)GLUT_BITMAP_HELVETICA_18, (char*)tracks[11].data(), tracks[11].size()*2);
}

void GLWidget_MainSaver::drawMainPicture()
{
    glEnable(GL_TEXTURE_2D);     // Разрешение наложение текстуры

    glColor3f(red,green,blue);
    static GLuint mainPicture = bindTexture(QImage("Textures/GLWidgetTextures/MainTextures/1.bmp"), GL_TEXTURE_2D, GL_RGBA);
    glBindTexture(GL_TEXTURE_2D, mainPicture);

    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0); glVertex2i(-windowWidth/2+5,windowHeight/2-5);
    glTexCoord2d(1.0, 1.0); glVertex2i(windowWidth/2-5,windowHeight/2-5);
    glTexCoord2d(1.0, 0.0); glVertex2i(windowWidth/2-5,-windowHeight/2+5);
    glTexCoord2d(0.0, 0.0); glVertex2i(-windowWidth/2+5,-windowHeight/2+5);
    glEnd();
}

void GLWidget_MainSaver::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if(isShowWindowTracks == true){ drawWindowTracks(); }
    else                          {  drawMainPicture(); }



//    red+=0.05;
//    green+=0.05;
//    blue+=0.05;
//    if(red>1.0)red=green=blue=0.0;


}

void GLWidget_MainSaver::mouseMoveEvent(QMouseEvent *mme)
{
    if(mme->x()){}
}


void GLWidget_MainSaver::mousePressEvent(QMouseEvent * mpe)
{
    if(mpe->x()){}
}

void GLWidget_MainSaver::keyPressEvent(QKeyEvent *kpe)
{
    if(kpe->key()){}
}

void GLWidget_MainSaver::enterEvent(QEvent * event)
{

    if(event->isAccepted()){}
    isDrawContur=true;
}

void GLWidget_MainSaver::leaveEvent(QEvent * event)
{
    if(event->isAccepted()){}
    isDrawContur=false;
}

bool GLWidget_MainSaver::getIsShowWindowTrack()
{
    return isShowWindowTracks;
}

