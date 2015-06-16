#include "GLWidgetH/glwidget_player.h"

GLWidget_Player::GLWidget_Player(QWidget *parent):QGLWidget(parent)
{
    setMouseTracking(true);

    volume = 0;
    coordVolume = 25;

    isActiveButtonStart = false;
    isActiveButtonNext = false;
    isActiveButtonPrev = false;
    isButtonPause = false;
    isButtonVolume = false;
    isActiveButtonPause = false;
    isActiveButtonVolume = false;
    startMusic = false;
    pauseMusic = false;
    stopMusic = false;
    nextMusic = false;
    prevMusic = false;

    red=green=blue=1.0;

    isDrawContur=false;
    QTimer *timer = new QTimer(this);
    timer->setInterval(33);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer->start();
}

void GLWidget_Player::setColorWidget(float red, float green, float blue)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
}

void GLWidget_Player::drawContur()
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

void GLWidget_Player::drawButtons()
{
    glColor3f(red,green,blue);


    if(isActiveButtonStart==true)
    {
        static GLuint btnStartActive = bindTexture(QImage("Textures/GLWidgetTextures/Player/btnStartActive.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnStartActive);
    }
    else
    {
        static GLuint btnStart = bindTexture(QImage("Textures/GLWidgetTextures/Player/btnStart.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnStart);
    }
    //Пуск

    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0); glVertex2i(0-windowWidth*0.05,windowHeight/2-5);
    glTexCoord2d(1.0, 1.0); glVertex2i(0+windowWidth*0.05,windowHeight/2-5);
    glTexCoord2d(1.0, 0.0); glVertex2i(0+windowWidth*0.05,-windowHeight/2+5);
    glTexCoord2d(0.0, 0.0); glVertex2i(0-windowWidth*0.05,-windowHeight/2+5);
    glEnd();

    //Next
    if(isActiveButtonNext==true)
    {
        static GLuint btnNextActive = bindTexture(QImage("Textures/GLWidgetTextures/Player/btnNextActive.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnNextActive);
    }
    else
    {
        static GLuint btnNext = bindTexture(QImage("Textures/GLWidgetTextures/Player/btnNext.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnNext);
    }
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0); glVertex2i(0+windowWidth*0.05,windowHeight/2-5);
    glTexCoord2d(1.0, 1.0); glVertex2i(0+windowWidth*0.15,windowHeight/2-5);
    glTexCoord2d(1.0, 0.0); glVertex2i(0+windowWidth*0.15,-windowHeight/2+5);
    glTexCoord2d(0.0, 0.0); glVertex2i(0+windowWidth*0.05,-windowHeight/2+5);
    glEnd();

    //Prev
    if(isActiveButtonPrev==true)
    {
        static GLuint btnPrevActive = bindTexture(QImage("Textures/GLWidgetTextures/Player/btnPrevActive.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnPrevActive);
    }
    else
    {
        static GLuint btnPrev = bindTexture(QImage("Textures/GLWidgetTextures/Player/btnPrev.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnPrev);
    }
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0); glVertex2i(0-windowWidth*0.15,windowHeight/2-5);
    glTexCoord2d(1.0, 1.0); glVertex2i(0-windowWidth*0.05,windowHeight/2-5);
    glTexCoord2d(1.0, 0.0); glVertex2i(0-windowWidth*0.05,-windowHeight/2+5);
    glTexCoord2d(0.0, 0.0); glVertex2i(0-windowWidth*0.15,-windowHeight/2+5);
    glEnd();





    if(isButtonPause == true)
    {
        if(isActiveButtonPause==true)
        {
            static GLuint pauseActive = bindTexture(QImage("Textures/GLWidgetTextures/Player/PauseActive.bmp"), GL_TEXTURE_2D, GL_RGBA);
            glBindTexture(GL_TEXTURE_2D, pauseActive);
        }
        else
        {
            static GLuint pause = bindTexture(QImage("Textures/GLWidgetTextures/Player/Pause.bmp"), GL_TEXTURE_2D, GL_RGBA);
            glBindTexture(GL_TEXTURE_2D, pause);
        }
        glBegin(GL_QUADS);
        glTexCoord2d(0.0, 1.0); glVertex2i(0-windowWidth*0.05,windowHeight/2-5);
        glTexCoord2d(1.0, 1.0); glVertex2i(0+windowWidth*0.05,windowHeight/2-5);
        glTexCoord2d(1.0, 0.0); glVertex2i(0+windowWidth*0.05,-windowHeight/2+5);
        glTexCoord2d(0.0, 0.0); glVertex2i(0-windowWidth*0.05,-windowHeight/2+5);
        glEnd();
    }
}


void GLWidget_Player::drawVolume()
{
    glColor3f(red,green,blue);

    static GLuint sliderVolume = bindTexture(QImage("Textures/GLWidgetTextures/Player/sliderVolume.bmp"), GL_TEXTURE_2D, GL_RGBA);
    glBindTexture(GL_TEXTURE_2D, sliderVolume);

    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0); glVertex2i(0+windowWidth*0.20,windowHeight/2-windowHeight/2+5);
    glTexCoord2d(1.0, 1.0); glVertex2i(0+windowWidth*0.47,windowHeight/2-windowHeight/2+5);
    glTexCoord2d(1.0, 0.0); glVertex2i(0+windowWidth*0.47,-windowHeight/2+windowHeight/2-5);
    glTexCoord2d(0.0, 0.0); glVertex2i(0+windowWidth*0.20,-windowHeight/2+windowHeight/2-5);
    glEnd();

    if(isActiveButtonVolume==true)
    {
        static GLuint btnVolumeActive = bindTexture(QImage("Textures/GLWidgetTextures/Player/btnVolumeActive.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnVolumeActive);
    }
    else
    {
        static GLuint btnVolume = bindTexture(QImage("Textures/GLWidgetTextures/Player/btnVolume.bmp"), GL_TEXTURE_2D, GL_RGBA);
        glBindTexture(GL_TEXTURE_2D, btnVolume);
    }
    glBegin(GL_QUADS);
    glTexCoord2d(0.0, 1.0); glVertex2i(0+windowWidth*0.20+coordVolume,windowHeight/2-windowHeight/2+5);
    glTexCoord2d(1.0, 1.0); glVertex2i(0+windowWidth*0.24+coordVolume,windowHeight/2-windowHeight/2+5);
    glTexCoord2d(1.0, 0.0); glVertex2i(0+windowWidth*0.24+coordVolume,-windowHeight/2+windowHeight/2-5);
    glTexCoord2d(0.0, 0.0); glVertex2i(0+windowWidth*0.20+coordVolume,-windowHeight/2+windowHeight/2-5);
    glEnd();


}

void GLWidget_Player::glWrite(float x, float y, int *font, char text[256], int kls) {
    int i;
    glRasterPos2f(x, y);
    for (i=0; i<kls; i++)
        glutBitmapCharacter(font, (int)text[i]);
}


void GLWidget_Player::drawTextVolume()
{
    volume =coordVolume;
    QString str=QString::number(volume);
    glColor3f(red,green,blue);
    if(isActiveButtonVolume==true)
        glWrite(0+windowWidth*0.20+coordVolume+2, windowHeight/2-windowHeight/2+7, (int*)GLUT_BITMAP_HELVETICA_12, (char*)str.data(), str.size()*2);

}

void GLWidget_Player::showPlayer()
{
    if(red < 1)
    {
        red+=0.05;
        green+=0.05;
        blue+=0.05;
    }

}
void GLWidget_Player::closePlayer()
{
    if(red>0.0)
    {
        red-=0.005;
        green-=0.005;
        blue-=0.005;
    }

}

void GLWidget_Player::initializeGL()
{
    glEnable(GL_TEXTURE_2D);     // Разрешение наложение текстуры
    glShadeModel( GL_SMOOTH );// Разрешить плавное цветовое сглаживание
    glClearDepth( 1.0f );// Разрешить очистку буфера глубины
    glEnable( GL_DEPTH_TEST );// Разрешить тест глубины
    glDepthFunc( GL_LEQUAL ); // Тип теста глубины
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );// Улучшение в вычислении перспективы
}

void GLWidget_Player::resizeGL(int width, int height)
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


void GLWidget_Player::paintGL()
{


    glClearColor(0.0,0.0,0.0,0.0f);// Очистка экрана в черный цвет
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //Условия для ползунка громкости
    if(coordVolume>120)
    {
        coordVolume=120;
    }
    if(coordVolume<0)
    {
        coordVolume=0;
    }


    //Условия наведения курсора на виджет
    if(isDrawContur == true)
    {
        //drawContur();
        showPlayer();
    }
    else
    {
        closePlayer();
    }


    drawButtons();
    drawVolume();
    drawTextVolume();

}
void GLWidget_Player::enterEvent(QEvent * event)
{

    if(event->isAccepted()){}
    isDrawContur=true;
}

void GLWidget_Player::leaveEvent(QEvent * event)
{

    if(event->isAccepted()){}
    isDrawContur=false;
}

void GLWidget_Player::mouseMoveEvent(QMouseEvent *pe)
{

    if(isButtonPause == false && pe->x()> windowWidth*0.45 && pe->x() < windowWidth*0.55 && pe->y() < windowHeight*0.95 && pe->y() > windowHeight*0.01)
    {
        isActiveButtonStart=true;
    }
    else
    {
        isActiveButtonStart=false;
    }


    if(pe->x()> windowWidth*0.55 && pe->x() < windowWidth*0.65 && pe->y() < windowHeight*0.95 && pe->y() > windowHeight*0.01)
    {
        isActiveButtonNext=true;
    }
    else
    {
        isActiveButtonNext=false;
    }

    if(pe->x()> windowWidth*0.35 && pe->x() < windowWidth*0.45 && pe->y() < windowHeight*0.95 && pe->y() > windowHeight*0.01)
    {
        isActiveButtonPrev=true;
    }
    else
    {
        isActiveButtonPrev=false;
    }

    if(isButtonPause == true && isActiveButtonStart == false && pe->x()> windowWidth*0.45 && pe->x() < windowWidth*0.55 && pe->y() < windowHeight*0.95 && pe->y() > windowHeight*0.01)
    {
        isActiveButtonPause=true;
    }
    else
    {
        isActiveButtonPause=false;
    }

    if(pe->x()> windowWidth*0.70+coordVolume && pe->x() < windowWidth*0.74+coordVolume && pe->y() < windowHeight*0.60 && pe->y() > windowHeight*0.40)
    {
        isActiveButtonVolume=true;
    }
    else
    {
        isActiveButtonVolume=false;
    }




    //Движение ползунка громкости
    if(isButtonVolume==true)
    {


        if(coordVolume<=120 && coordVolume>=0)
            coordVolume=pe->x()-windowWidth*0.72;
    }






}

void GLWidget_Player::mouseReleaseEvent(QMouseEvent *mre)
{
    if(mre->x()){}

    if(isButtonVolume==true)
    {
        isButtonVolume=false;

    }
}

void GLWidget_Player::mousePressEvent(QMouseEvent *mpe)
{


    //Нажать кнопку старт
    if(mpe->button() == Qt::LeftButton && isActiveButtonStart == true && isActiveButtonPause == false)
    {
        startMusic = true;
        pauseMusic = false;
        isButtonPause = true;
        isActiveButtonStart = false;
    }
    else
    {

        //Нажать кнопку паузы
        if(mpe->button() == Qt::LeftButton && isActiveButtonPause == true && isActiveButtonStart == false)
        {
            pauseMusic = true;
            startMusic = false;
            isButtonPause = false;
            isActiveButtonStart = true;
        }
    }



    //Нажать кнопку, следующий трек

    if( mpe->button() == Qt::LeftButton && isActiveButtonNext == true)
    {
        nextMusic=true;
    }
    else
    {

    }

    if( mpe->button() == Qt::LeftButton && isActiveButtonPrev == true)
    {
        prevMusic=true;
    }
    else
    {

    }


    //Нажать кнопку ползунка громкости
    if(mpe->button() == Qt::LeftButton && isActiveButtonVolume == true)
    {
        isButtonVolume=true;
    }
    else
    {
        isButtonVolume=false;
    }

}


bool GLWidget_Player::returnStartMusic()
{
    return startMusic;
}

bool GLWidget_Player::returnPauseMusic()
{
    return pauseMusic;
}

bool GLWidget_Player::returnNextMusic()
{
    return nextMusic;
}

bool GLWidget_Player::returnPrevMusic()
{
    return prevMusic;
}

void GLWidget_Player::setNextMusic()
{
    nextMusic = false;
}

void GLWidget_Player::setPrevMusic()
{
    prevMusic = false;
}

int GLWidget_Player::getVolume()
{
    return volume;
}

