#include "PlayerH/player.h"

Player::Player()
{
    player = new QMediaPlayer;
    firstStart = false;
    isPlay = false;
    isPause = false;
    isStop = false;
    currentTrack = 0;
    currentAddTrack = 0;
    tracks.push_back("NONE");
    player->setMedia(QUrl::fromLocalFile(tracks[0]));
    player->setVolume(100);
}


void Player::addTrack(QString track)
{
    tracks[currentAddTrack]=track;
    tracks.push_back("NONE");
    setMedia(track);
    currentAddTrack+=1;

    if(isPlay == true)
        currentTrack=tracks.size()-2;

}

void Player::startMusic()
{

    player->play();
    isPlay = true;
    isPause = false;
    isStop = false;
}

void Player::pauseMusic()
{
    player->pause();
    isPlay = false;
    isPause = false;
    isStop = false;
}
void Player::stopMusic()
{
    player->stop();
    isStop = true;
    isPause = false;
    isPlay = false;
}

void Player::setMedia(QString track)
{
    player->setMedia(QUrl::fromLocalFile(track));
}

void Player::nextTrack()
{
    if(tracks[0] == "NONE")
    {

    }
    else
    {

        if(tracks[currentTrack+1] == "NONE")
        {
            player->setMedia(QUrl::fromLocalFile(tracks[0]));
            currentTrack=0;
        }
        else
        {
            player->setMedia(QUrl::fromLocalFile(tracks[currentTrack+1]));
            currentTrack+=1;

        }

    }
}

void Player::prevTrack()
{
    if(tracks[0] == "NONE")
    {

    }
    else
    {

        if(currentTrack == 0)
        {
            int size = tracks.size();
            player->setMedia(QUrl::fromLocalFile(tracks[size-2]));
            currentTrack = size-2;
        }
        else
        {
            player->setMedia(QUrl::fromLocalFile(tracks[currentTrack-1]));
            currentTrack-=1;

        }

    }
}


int Player::getPlayTrack()
{
    return currentTrack;
}



void Player::setVolume(int volume)
{
    player->setVolume(volume);
}

float Player::getLenTrack()
{
    float duration = player->duration();
    return duration;
}

float Player::getPosition()
{
    float position = player->position();
    return position;
}

Player::~Player()
{
    delete player;
}
