#ifndef STORE_H
#define STORE_H

#include "place.h"
#include "productinfo.h"
#include <Goods.h>
#include <QString>

class Store : public Place
{

public:
    Store(ProductInfo* info);
    ~Store();

    int getGoods(int id, int amount);
    int putGoods(int id, int amount);
    void putGoods(QList<Goods*>* goods);
    void refreshGoods(int amount);
    bool hasGoods(int id);
    virtual int placetype();

public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
private:
    QList<Goods*>* goodslist =new QList<Goods*>();
    ProductInfo* info;
    void update();

};

#endif // STORE_H
