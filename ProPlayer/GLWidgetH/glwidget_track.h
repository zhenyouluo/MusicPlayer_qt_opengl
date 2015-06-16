#ifndef GLWIDGET_TRACK_H
#define GLWIDGET_TRACK_H

#include <QGLWidget>
#include <QTimer>
#include <QEvent>
#include <QMouseEvent>
#include <GL/glu.h>
#include <glut.h>

class GLWidget_Track : public QGLWidget
{
public:
    GLWidget_Track(QWidget* parent = 0);
    void setLenTrack(float length);
    void setPositionTrack(float positionTrack);

private:
    void drawContur();
    void setColorWidget(float red, float green, float blue);
    void drawStrip(); //Рисуем полоску
    void drawSlider(); //Рисуем ползунок
    void showTrack();
    void closeTrack();
    void glWrite(float x, float y, int *font, char text[256], int kls);
    void drawNums();

protected:

    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    virtual void mouseMoveEvent(QMouseEvent*pe);
    virtual void mousePressEvent(QMouseEvent* mpe);
    virtual void mouseReleaseEvent(QMouseEvent* mre);

private slots:
    void second();


private:
int windowWidth;
int windowHeight;
bool isDrawContur;

float red;
float green;
float blue;

bool isActiveSlider;
bool isButtonSlider;


//Положение ползунка
float coordSlider;    //Координаты начала ползунка
float lengthTrack;
float msInPixel;   //Милисекунд в пикселе
float shiftUnit;
float positionTrack;
};

#endif // GLWIDGET_TRACK_H
