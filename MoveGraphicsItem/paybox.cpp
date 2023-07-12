#include "paybox.h"

Paybox::Paybox(QObject *parent)
    : Place{parent}
{

}

void Paybox::calculation(Cart *cart)
{

}

int Paybox::placetype()
{
    return 2;
}

QRectF Paybox::boundingRect() const
{
    return QRectF (-30,-30,120,70);
}

void Paybox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::black);

    QColor color = QColor(220,220,0);
    painter->setBrush(color);

    painter->drawRect(-30,-30,120,70);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}
