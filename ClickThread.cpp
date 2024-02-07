#include "ClickThread.h"
#include <QSoundEffect>
#include <QFileInfo>
#include <QDir>
#include "isClickingState.h"
#include "ClickButtonHandler.h"

void ClickThread::run()
{
    QSoundEffect effect;
    effect.setSource(QUrl::fromLocalFile(QDir::currentPath() + "/../Metronome/sounds/click.wav"));
    effect.setVolume(1.00f);
    int tempInMilliseconds = 60 * 1000 / this->temp;

    if (effect.status() == 1)
    {
        isClickingState::isClickingNow = !isClickingState::isClickingNow;
        (new ClickButtonHandler)->changeTempo(this->temp);
    }

    while (isClickingState::isClickingNow)
    {
        effect.play();
        QThread::msleep(tempInMilliseconds);
    }
}
