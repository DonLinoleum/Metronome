#ifndef CLICK_H
#define CLICK_H

#include <QObject>
#include <QSoundEffect>
#include <iostream>

class Click : public QObject
{
    Q_OBJECT
public:
    Click(QObject *parent = nullptr){}
    Q_INVOKABLE void changeTempo(unsigned value);
signals:
    void valueChanged(unsigned);
private:
    unsigned value{};
    QSoundEffect effect;
    bool isClick;
};

#endif // CLICK_H
