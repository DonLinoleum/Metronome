#ifndef CLICKBUTTONHANDLER_H
#define CLICKBUTTONHANDLER_H

#include <QObject>

class ClickButtonHandler : public QObject
{
    Q_OBJECT
public:
    ClickButtonHandler(QObject *parent = nullptr){}
    Q_INVOKABLE void changeTempo(unsigned value);
signals:
    void valueChanged(unsigned);
private:
    unsigned value{};
    bool isClick;
};

#endif // CLICKBUTTONHANDLER_H
