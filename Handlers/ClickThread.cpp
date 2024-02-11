#include "ClickThread.h"
#include <QSoundEffect>
#include <QFileInfo>
#include <QDir>
#include "MainState/MainState.h"

void ClickThread::run()
{
    QSoundEffect effect;
    effect.setSource(QUrl::fromLocalFile(QDir::currentPath() + "/../Metronome/sounds/click.wav"));
    effect.setVolume(1.00f);

    if (effect.status() == 1)
    {
        MainState::isClickingNow = !MainState::isClickingNow;
        mainState->startOrStopClickHandle();
    }

    while (MainState::isClickingNow)
    {
        int tempInMilliseconds = 60 * 1000 / mainState->getTempValue();
        effect.play();
        QThread::msleep(tempInMilliseconds);
    }
}
