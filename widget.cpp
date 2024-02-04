#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent), effect(this)
{
    effect.setSource(QUrl::fromLocalFile("sounds/click.wav"));
    effect.setLoopCount(QSoundEffect::Infinite);
    effect.setVolume(1.00f);
}

Widget::~Widget()
{
}

void Widget::play()
{
    effect.play();
}
