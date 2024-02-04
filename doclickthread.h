#ifndef DOCLICKTHREAD_H
#define DOCLICKTHREAD_H
#include <QThread>
#include <QSoundEffect>

class doClickThread : public QThread
{
    Q_OBJECT
public:
    doClickThread(unsigned temp){this->temp = temp;}
protected:
    void run();
private:
    unsigned temp;
};

#endif // DOCLICKTHREAD_H
