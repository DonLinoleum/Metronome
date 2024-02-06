#include "ClickThread.h"
#include <chrono>
#include <QSoundEffect>
#include <QFileInfo>
#include <QDir>

void ClickThread::run()
{
    QSoundEffect effect;
    effect.setSource(QUrl::fromLocalFile(QDir::currentPath() + "/../Metronome/sounds/click.wav"));
    effect.setVolume(1.00f);
    int tempInMilliseconds = 60 * 1000 / this->temp;
    for (int i{};i< 5; i++)
    {
        effect.play();
        std::this_thread::sleep_for(std::chrono::milliseconds(tempInMilliseconds));
    }
}
