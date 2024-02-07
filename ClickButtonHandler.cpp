#include "ClickButtonHandler.h"
#include <QSoundEffect>
#include "ClickThread.h"
#include <QThread>
#include "isClickingState.h"
#include <QDir>

void ClickButtonHandler::changeTempo(unsigned value)
{
    emit valueChanged(value);
    QSoundEffect effect;
    effect.setSource(QUrl::fromLocalFile(QDir::currentPath() + "/../Metronome/sounds/click.wav"));
    effect.setVolume(1.00f);
    effect.play();
    isClickingState::isClickingNow = !isClickingState::isClickingNow;
    if (isClickingState::isClickingNow)
    {
        auto th = new ClickThread(value);
        th->start();
    }
}






