#ifndef DOOR_H
#define DOOR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "place.h"

class Door : public Place
{
public:
    Door();
    virtual int placetype();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // DOOR_H
