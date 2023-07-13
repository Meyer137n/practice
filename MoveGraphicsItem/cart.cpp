#include "cart.h"

Cart::Cart()
{

}

void Cart::putGoods(int id, int amount)
{
    for(int i=0;i<this->goodslist->count();i++)
    {
        Goods* goods= this->goodslist->at(i);
        if(goods->id==id)
        {
            goods->amount+=amount;
            return;
        }
    }
    Goods* goods= new Goods(id,amount);
    this->goodslist->append(goods);
}

void Cart::clear()
{
    this->goodslist->clear();
}

int Cart::count()
{
    return goodslist->count();
}

Goods* Cart::getAt(int index)
{
    return goodslist->at(index);
}

bool Cart::isempty()
{
    return goodslist->count()==0;
}
