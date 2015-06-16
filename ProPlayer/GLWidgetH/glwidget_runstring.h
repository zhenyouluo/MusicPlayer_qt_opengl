#ifndef GLWIDGET_RUNSTRING_H
#define GLWIDGET_RUNSTRING_H
#include <QGLWidget>
#include <QTimer>
#include <QString>
#include <QEvent>
#include <GL/glu.h>
#include <glut.h>
class GLWidget_RunString : public QGLWidget
{
public:
    GLWidget_RunString(QWidget* parent = 0);
    void setRunString(QString str);
    QString getRunString();


private:
    void drawContur();
    void setColorWidget(float red, float green, float blue);
    void drawString(); //Рисуем строку
    void showRunString(); //Показать
    void closeRunString();//Убрать
    void moveString();//Движение строки
    void glWrite(float x, float y, int *font, char text[256], int kls);

protected:

    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private:

QString runString; //Бегущая строка
int windowWidth;
int windowHeight;
bool isDrawContur;


float red;
float green;
float blue;

int coordPointString;  //Координаты начала строки

};

#endif // GLWIDGET_RUNSTRING_H
