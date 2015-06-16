#ifndef GLWIDGET_MAINMENU_H
#define GLWIDGET_MAINMENU_H
#include <QGLWidget>
#include <QTimer>
#include <QEvent>
#include <QMouseEvent>
#include <GL/glu.h>
class GLWidget_MainMenu : public QGLWidget
{
public:
    GLWidget_MainMenu(QWidget* parent = 0);
    void setNumHelp(int num);
    bool returnFlagPressButtonExit();
    int getPosX();
    int getPosY();


private:
    void drawContur();
    void drawHelp();
    void setColorWidget(float red, float green, float blue);
    void showSlider(); //Показать слайдер
    void closeSlider();//Убрать слайдер
    void drawArchitecture();

protected:

    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    virtual void mouseMoveEvent(QMouseEvent *pe);
    virtual void mousePressEvent(QMouseEvent* mpe);
    virtual void mouseReleaseEvent(QMouseEvent *mre);

private:
bool isDrawContur;
int windowWidth;
int windowHeight;


float red;
float green;
float blue;

unsigned int numHelp;

bool isActiveButtonExit;
bool isPressButtonExit;
bool isGrab;
bool isActiveGrab;

int posX;
int posY;



};

#endif // GLWIDGET_MAINMENU_H
