#ifndef CLICKTHREAD_H
#define CLICKTHREAD_H
#include <QThread>
#include <QSoundEffect>
#include "MainState/MainState.h"

class ClickThread : public QThread
{
    Q_OBJECT
public:
    ClickThread(MainState* mainState){this->mainState = mainState;}
protected:
    void run();
private:
    MainState* mainState;
};

#endif // CLICKTHREAD_H
