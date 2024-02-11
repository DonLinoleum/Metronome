#include "MainState.h"
#include "Handlers/ClickThread.h"
#include <QThread>
#include <QDir>
#include <iostream>

int MainState::getTempValue()
{
    return this->tempValue;
}

void MainState::setTempValue(int newValue)
{
    emit valueChanged(newValue);
    this->tempValue = newValue;
}

QString MainState::getPlayButtonIcon()
{
    return this->playButtonIcon;
}

void MainState::setPlayButtonIcon(QString value)
{
    if (MainState::isClickingNow)
        this->playButtonIcon = "images/play.png";
    else
       this->playButtonIcon = "images/pause.png";
    emit playButtonIconChanged();
}



void MainState::startOrStopClickHandle()
{
    QSoundEffect effect;
    effect.setSource(QUrl::fromLocalFile(QDir::currentPath() + "/../Metronome/sounds/click.wav"));
    effect.setVolume(1.00f);
    effect.play();
    this->setPlayButtonIcon("");
    MainState::isClickingNow = !MainState::isClickingNow;
    if (MainState::isClickingNow)
    {
        auto th = new ClickThread(this);
        th->start();
    }
}
