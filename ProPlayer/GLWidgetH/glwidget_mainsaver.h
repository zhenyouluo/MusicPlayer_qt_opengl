#ifndef GLWIDGET_MAINSAVER_H
#define GLWIDGET_MAINSAVER_H
#include <QGLWidget>
#include <QPainter>
#include <QFont>
#include <QColor>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QEvent>
#include <QTimer>
#include <QVector>
#include <QString>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glaux.h>
#include <stdarg.h>
#include <stdio.h>
#include <cmath>
#include <glut.h>
class GLWidget_MainSaver : public QGLWidget
{


public:
    GLWidget_MainSaver(QWidget* parent = 0);
    ~GLWidget_MainSaver();
    void setShowWindowTracks();
    void setCloseWindowTracks();
    bool getIsShowWindowTrack();

    void setTrack(QString track); // Добавление трека
    //void delTrack(int index);     // Удаление трека
    void playTrack(int index);
    QString getPlayTrack();   //Какой трек проигрывается


private:
    void drawContur();
    void setColorWidget(float red, float green, float blue);
    void drawSaver(); //Рисуем
    void showSaver(); //Показать
    void closeSaver();//Убрать
    void glWrite(float x, float y, int *font, char text[256], int kls);
    void setNameTrack(QString name);
    void drawWindowTracks();      //Рисует окно с треками
    void drawMainPicture();


protected:

    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private:
QVector<QString> tracks;

QString nameTrack;
bool isDrawContur;
int windowWidth;
int windowHeight;

float red;
float green;
float blue;

bool isShowWindowTracks;

float arrBlue[12];

};
#endif // GLWIDGET_MAINSAVER_H
