#ifndef CLICKTHREAD_H
#define CLICKTHREAD_H
#include <QThread>
#include <QSoundEffect>

class ClickThread : public QThread
{
    Q_OBJECT
public:
    ClickThread(unsigned temp){this->temp = temp;}
protected:
    void run();
private:
    unsigned temp;
};

#endif // CLICKTHREAD_H
