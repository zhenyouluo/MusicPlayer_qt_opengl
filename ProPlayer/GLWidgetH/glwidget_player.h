#ifndef GLWIDGET_PLAYER_H
#define GLWIDGET_PLAYER_H
#include <QGLWidget>
#include <QTimer>
#include <QEvent>
#include <QString>
#include <QMediaPlayer>
#include <QMouseEvent>
#include <GL/glu.h>
#include <glut.h>
#include "PlayerH/player.h"

class GLWidget_Player : public QGLWidget
{
public:
    GLWidget_Player(QWidget* parent = 0);
    bool returnStartMusic();
    bool returnPauseMusic();
    bool returnNextMusic();
    bool returnPrevMusic();

    void setNextMusic();
    void setPrevMusic();
    int  getVolume();


private:
    void drawContur();
    void setColorWidget(float red, float green, float blue);
    void drawButtons(); //Рисуем кнопки
    void showPlayer(); //Показать слайдер
    void closePlayer();//Убрать слайдер
    void drawVolume(); //Рисуем регулятор громкости
    void drawTextVolume(); //Рисуем число уровня громкости
    void glWrite(float x, float y, int *font, char text[256], int kls);

protected:

    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    virtual void mouseMoveEvent(QMouseEvent*pe);
    virtual void mousePressEvent(QMouseEvent* mpe);
    virtual void mouseReleaseEvent(QMouseEvent* mre);

private:
Player player;
int windowWidth;
int windowHeight;
bool isDrawContur;

float red;
float green;
float blue;

bool isActiveButtonStart;
bool isButtonPause;
bool isActiveButtonPause;
bool isActiveButtonNext;
bool isActiveButtonPrev;
bool isActiveButtonVolume;
bool isButtonVolume;

//Кнопки плеера
bool startMusic;
bool pauseMusic;
bool stopMusic;
bool nextMusic;
bool prevMusic;

//Положение ползунка громкости
int volume;          //Громкость
float coordVolume;   //Координаты начала ползунка

};

#endif // GLWIDGET_PLAYER_H
