#ifndef CART_H
#define CART_H
#include "Goods.h"


class Cart
{
public:
    Cart();
    void putGoods(int id, int amount);
    QList<Goods*>* checkout();
    QList<Goods*>* goodslist = new QList<Goods*>();
    int count();
    Goods *getAt(int index);
};

#endif // CART_H
