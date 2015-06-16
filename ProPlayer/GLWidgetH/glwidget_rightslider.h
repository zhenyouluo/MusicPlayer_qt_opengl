#ifndef GLWIDGET_RIGHTSLIDER_H
#define GLWIDGET_RIGHTSLIDER_H
#include <QGLWidget>
#include <QTimer>
#include <QVector>
#include <QString>
#include <QFileDialog>
#include <QEvent>
#include <QMouseEvent>
#include <GL/glu.h>
class GLWidget_RightSlider : public QGLWidget
{
public:
    GLWidget_RightSlider(QWidget* parent = 0);
    QString track;  //Добавленный трек
    bool returnAddTrack();
    void setAddTrack();

    bool returnFlagActiveButtonTracks();
    bool returnFlagActiveButtonSettings();


private:
    void drawContur();
    void setColorWidget(float red, float green, float blue);
    void drawButtons(); //Рисуем кнопки
    void showSlider(); //Показать слайдер
    void closeSlider();//Убрать слайдер

protected:

    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    virtual void mouseMoveEvent(QMouseEvent *pe);
    virtual void mousePressEvent(QMouseEvent* pe);

private:

int windowWidth;
int windowHeight;
bool isDrawContur;

float red;
float green;
float blue;

bool isActiveButtonAddTracks;
bool isActiveButtonSettings;
bool addTrack; //Был ли добавлен трек

};
#endif // GLWIDGET_RIGHTSLIDER_H
