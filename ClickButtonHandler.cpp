#include "ClickButtonHandler.h"
#include <QSoundEffect>
#include "ClickThread.h"
#include <QThread>

void ClickButtonHandler::changeTempo(unsigned value)
{
    auto th = new ClickThread(value);
    th->start();
}






