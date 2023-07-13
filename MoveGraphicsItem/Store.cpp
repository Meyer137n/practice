#include "Store.h"
#include "iostream"

using namespace std;

Store::Store(ProductInfo* info) : Place()
{
    this->info=info;
}

Store::~Store()
{

}

int Store::getGoods(int id, int amount)
{

    for(int i=0;i<this->goodslist->count();i++)
    {
        Goods* goods= this->goodslist->at(i);
        if(goods->id==id)
        {
            if(goods->amount>=amount)
            {
                goods->amount-=amount;
                this->update(goodslist->count()+1);
                return amount;
            }
            else
            {
                int buf=goods->amount;
                goods->amount=0;
                this->update(goodslist->count()+1);
                return buf;
            }
        }
    }
}

int Store::putGoods(int id, int amount)
{
    for(int i=0;i<this->goodslist->count();i++)
    {
        Goods* goods= this->goodslist->at(i);
        if(goods->id==id)
        {
            goods->amount+=amount;
            return goods->amount;
        }
    }
    Goods* goods= new Goods(id,amount);
    this->goodslist->append(goods);
    this->update(goodslist->count()+1);
    return amount;
}

void Store::putGoods(QList<Goods *> *goods)
{
    for(int i=0;i<goods->count();i++)
    {
        Goods* g= goods->at(i);
        this->putGoods(g->id,g->amount);
    }
}

void Store::refreshGoods(int amount)
{
    for(int i=0;i<this->goodslist->count();i++)
    {
        Goods* goods = this->goodslist->at(i);
        goods->amount=amount;
    }
    this->update(goodslist->count()+1);
}

bool Store::hasGoods(int id)
{
    for(int i=0;i<this->goodslist->count();i++)
    {
        Goods* goods= this->goodslist->at(i);
        if(goods->id==id)
        {
            return true;
        }
    }
    return false;
}

int Store::placetype()
{
    return 1;
}

int Store::rowCount(const QModelIndex &parent) const
{
    return goodslist->count()+1;
}

QVariant Store::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    switch (role) {
    case Qt::DisplayRole:
        if (index.row() == 0) {
            return "Товары:";
        }
        else {
            Goods* goods = goodslist->at(index.row() - 1);
            Product product = this->info->get(goods->id);
            return product.name + " " + QString::number(goods->amount);
        }

    default:
        return QVariant();
    }
}


