#include "doclickthread.h"
#include <chrono>
#include <QSoundEffect>
#include <iostream>

void doClickThread::run()
{
    QSoundEffect effect;
    effect.setSource(QUrl::fromLocalFile("F:/click.wav"));
    effect.setVolume(1.00f);
    int tempIsMilliseconds = 60 * 1000 / this->temp;
    for (int i{};i< 5; i++)
    {
        effect.play();
        std::cout << tempIsMilliseconds << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(tempIsMilliseconds));
    }
}
