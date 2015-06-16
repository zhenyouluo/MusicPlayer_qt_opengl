#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMouseTracking(true);
musicPlayer = new Player;
posX=100;
posY=100;

icon.addFile("Textures/Icon/icon.bmp");
setMainWidget();
setGLWidgets();

QTimer *timer = new QTimer(this);
    timer->setInterval(33);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkFlagsWidgets()));
    timer->start();
}

void MainWindow::setMainWidget()
{
    mainWidth = 500;mainHeight = 500; //размер стандартного окна
    //mainWidth = 600;mainHeight =600;    //
    //mainWidth = 720;mainHeight =720;    //Плеер HD

    this->resize(mainWidth,mainHeight);
    this->setFixedSize(mainWidth,mainHeight);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowIcon(icon);
    this->setWindowIconText("ProPlayer. Beta version 1.0");
}

void MainWindow::setGLWidgets()
{


    mainSaver = new GLWidget_MainSaver;
    mainSaver->move(mainWidth*0.1,mainHeight*0.2);
    mainSaver->resize(mainWidth*0.8,mainHeight*0.6+1);
    this->layout()->addWidget(mainSaver);

    mainMenu = new GLWidget_MainMenu;
    mainMenu->move(0,0);
    mainMenu->resize(mainWidth,mainHeight*0.2);
    this->layout()->addWidget(mainMenu);

    leftSlider = new GLWidget_LeftSlider;
    leftSlider->move(0,mainHeight*0.2);
    leftSlider->resize(mainWidth*0.1,mainHeight*0.6+1);
    this->layout()->addWidget(leftSlider);

    rightSlider = new GLWidget_RightSlider;
    rightSlider->move(mainWidth*0.9,mainHeight*0.2);
    rightSlider->resize(mainWidth*0.1,mainHeight*0.6+1);
    this->layout()->addWidget(rightSlider);

    runString = new GLWidget_RunString;
    runString->move(0,mainHeight*0.8);
    runString->resize(mainWidth,mainHeight*0.06);
    this->layout()->addWidget(runString);

    track = new GLWidget_Track;
    track->move(0,mainHeight*0.86);
    track->resize(mainWidth,mainHeight*0.04+1);
    this->layout()->addWidget(track);


    player = new GLWidget_Player;
    player->move(0,mainHeight*0.9);
    player->resize(mainWidth,mainHeight*0.1);
    this->layout()->addWidget(player);
}

void MainWindow::checkFlagsWidgets()
{
    this->move(mainMenu->getPosX(),mainMenu->getPosY());

    //Установка бегущей строки
    if(player->returnStartMusic()==true)
    runString->setRunString(mainSaver->getPlayTrack());

    //Установка громкости
    musicPlayer->setVolume(player->getVolume());

    if(rightSlider->returnAddTrack()==true)
    {
      musicPlayer->addTrack(rightSlider->track);
      mainSaver->setTrack(rightSlider->track);
      rightSlider->setAddTrack();
    }

    //Установка позиции трека
    track->setPositionTrack(musicPlayer->getPosition());

    if(player->returnStartMusic() == true){musicPlayer->startMusic(); mainSaver->playTrack(musicPlayer->getPlayTrack());track->setLenTrack(musicPlayer->getLenTrack());}
    if(player->returnPauseMusic() == true){musicPlayer->pauseMusic();}
    if(player->returnNextMusic() == true){musicPlayer->nextTrack(); player->setNextMusic(); mainSaver->playTrack(musicPlayer->getPlayTrack());}
    if(player->returnPrevMusic() == true){musicPlayer->prevTrack(); player->setPrevMusic(); mainSaver->playTrack(musicPlayer->getPlayTrack());}

    if(leftSlider->returnFlagActiveButtonTracks() == true) {  mainMenu->setNumHelp(2);}
    if(leftSlider->returnFlagActiveButtonAlbums() == true) {  mainMenu->setNumHelp(3);}
    if(leftSlider->returnFlagActiveButtonGenres() == true) {  mainMenu->setNumHelp(4);}
    if(leftSlider->returnFlagActiveButtonPlaylists() == true) {  mainMenu->setNumHelp(5);}
    if(rightSlider->returnFlagActiveButtonTracks() == true) {  mainMenu->setNumHelp(6);}
    if(rightSlider->returnFlagActiveButtonSettings() == true){ mainMenu->setNumHelp(7);}

    if(leftSlider->returnFlagActiveButtonTracks() == false
            && leftSlider->returnFlagActiveButtonAlbums() == false
            && leftSlider->returnFlagActiveButtonGenres() == false
            && leftSlider->returnFlagActiveButtonPlaylists() == false
            && rightSlider->returnFlagActiveButtonTracks() == false
            && rightSlider->returnFlagActiveButtonSettings() == false)
    {mainMenu->setNumHelp(1);}

    if(leftSlider->returnFlagPressButtonTracks() == true) {  mainSaver->setShowWindowTracks();}
    if(leftSlider->returnFlagPressButtonTracks() == false) {  mainSaver->setCloseWindowTracks();}



    if(mainMenu->returnFlagPressButtonExit() == true){this->close();}
}

void MainWindow::mouseMoveEvent(QMouseEvent *mme)
{


}

void MainWindow::enterEvent(QEvent * event)
{


}

void MainWindow::keyPressEvent(QKeyEvent *kpe)
{
    switch(kpe->key())
    {
        case Qt::Key_Escape : close(); break;

    }
}



MainWindow::~MainWindow()
{
    delete mainSaver;
    delete mainMenu;
    delete leftSlider;
    delete rightSlider;
    delete runString;
    delete track;
    delete player;
    delete musicPlayer;
}
