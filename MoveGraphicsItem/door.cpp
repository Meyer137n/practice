#include "door.h"

Door::Door()
{

}

int Door::placetype()
{
    return 3;
}

QRectF Door::boundingRect() const
{
    return QRectF (-30,-30,60,200);
}

void Door::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::black);
    painter->setBrush(Qt::darkGray);

    painter->drawRect(-30,-30,60,200);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}
