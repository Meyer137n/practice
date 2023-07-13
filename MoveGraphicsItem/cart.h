#ifndef CART_H
#define CART_H
#include "Goods.h"


class Cart
{
public:
    Cart();
    void putGoods(int id, int amount);
    void clear();
    QList<Goods*>* goodslist = new QList<Goods*>();
    int count();
    Goods *getAt(int index);
    bool isempty();
};

#endif // CART_H
