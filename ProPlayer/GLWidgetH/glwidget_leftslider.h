#ifndef GLWIDGET_LEFTSLIDER_H
#define GLWIDGET_LEFTSLIDER_H

#include <QGLWidget>
#include <QTimer>
#include <QMouseEvent>
#include <QEvent>
#include <GL/glu.h>



class GLWidget_LeftSlider : public QGLWidget
{


public:
    GLWidget_LeftSlider(QWidget* parent = 0);
    bool returnFlagActiveButtonTracks();
    bool returnFlagActiveButtonAlbums();
    bool returnFlagActiveButtonGenres();
    bool returnFlagActiveButtonPlaylists();
    bool returnFlagPressButtonTracks();

private:

    void drawContur(); //Рисуем контур
    void drawButtons(); //Рисуем кнопки
    void setColorWidget(float red, float green, float blue);
    void showSlider(); //Показать слайдер
    void closeSlider();//Убрать слайдер

protected:

    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    virtual void mouseMoveEvent(QMouseEvent*pe);
    virtual void mousePressEvent(QMouseEvent *mpe);
    virtual void mouseReleaseEvent(QMouseEvent *mre);

private:

bool isDrawContur;
int windowWidth;
int windowHeight;

float red;
float green;
float blue;

bool isActiveButtonTracks;  //Активная ли кнока треков
bool isActiveButtonAlbums;  //Активная ли кнока
bool isActiveButtonGenres;  //Активная ли кнока
bool isActiveButtonPlaylists;  //Активная ли кнока

bool isPressButtonTracks;    //Нажата ли кнопка треков

};

#endif // GLWIDGET_LEFTSLIDER_H
