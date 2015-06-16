#ifndef PLAYER_H
#define PLAYER_H

#include<QWidget>
#include<QString>
#include<QVector>
#include<QMediaPlayer>

class Player
{
public:
    Player();
    ~Player();
    QVector<QString> tracks;
    void addTrack(QString track);
    void startMusic();
    void pauseMusic();
    void stopMusic();
    void setMedia(QString);
    void nextTrack();
    void prevTrack();
    int  getPlayTrack();  //Вернуть номер трека, который играет
    void setVolume(int volume);
    float getLenTrack();
    float getPosition();
private:
    QMediaPlayer* player;
    int currentAddTrack; //Текущий трек, для добавления
    int currentTrack; //Текущий играющий трек
    bool firstStart;
    bool isPlay; //Плеер играет
    bool isPause;
    bool isStop;
};

#endif // PLAYER_H
