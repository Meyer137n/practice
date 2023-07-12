#ifndef PAYBOX_H
#define PAYBOX_H

#include "Place.h"
#include "cart.h".h"
#include <QObject>
#include <QWidget>

class Paybox : public Place
{
public:
    explicit Paybox(QObject *parent = nullptr);
    int cash=0;
    void calculation(Cart* cart);
    virtual int placetype();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PAYBOX_H
