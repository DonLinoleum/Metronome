#ifndef MAINSTATE_H
#define MAINSTATE_H
#include <QObject>

class MainState : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int tempValue READ getTempValue WRITE setTempValue NOTIFY valueChanged)
    Q_PROPERTY(QString playButtonIcon READ getPlayButtonIcon WRITE setPlayButtonIcon
                   NOTIFY playButtonIconChanged)
public:
    MainState(QObject *parent = nullptr){}
    static inline bool isClickingNow{false};
    Q_INVOKABLE void startOrStopClickHandle();

    Q_INVOKABLE int getTempValue();
    Q_INVOKABLE void setTempValue(int newValue);

    Q_INVOKABLE QString getPlayButtonIcon();
    Q_INVOKABLE void setPlayButtonIcon(QString value);
signals:
    void valueChanged(int);
    void playButtonIconChanged();
private:
    int tempValue{120};
    QString playButtonIcon{"images/play.png"};
};

#endif // MAINSTATE_H
