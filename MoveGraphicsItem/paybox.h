#ifndef PAYBOX_H
#define PAYBOX_H

#include "Place.h"
#include "cart.h"
#include "productinfo.h"
#include <QObject>
#include <QWidget>

class Paybox : public Place
{
public:
    Paybox(ProductInfo*);
    double cash=0;
    void calculation(Cart* cart);
    virtual int placetype();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QList<double>* transactions = new QList<double>();
    ProductInfo* info;

public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
};

#endif // PAYBOX_H
