#include "click.h"
#include <QSoundEffect>
#include "doclickthread.h"
#include <QThread>

void Click::changeTempo(unsigned value)
{

    auto th = new doClickThread(value);
    th->start();
}






