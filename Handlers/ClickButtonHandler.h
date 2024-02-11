#ifndef CLICKBUTTONHANDLER_H
#define CLICKBUTTONHANDLER_H

#include <QObject>

class ClickButtonHandler : public QObject
{
    Q_OBJECT
public:
    ClickButtonHandler(QObject *parent = nullptr){}

signals:
    void valueChanged(unsigned);
};

#endif // CLICKBUTTONHANDLER_H
