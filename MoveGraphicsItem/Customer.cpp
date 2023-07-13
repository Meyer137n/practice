#include "Customer.h"
#define CIRCLE_SIZE 40

Customer::Customer(ProductInfo* info)
{
    this->info=info;
    srand(time(NULL));
    int kolvo = rand() % 8 + 1;
    int value;
    for (int i = 1; i <= kolvo; i++)
    {
        do {
            value = rand()%8+1;
        } while (list->count(value)>0);
        list->write(value);
    }
    setBrush(Qt::green);
    setRect(0,0,CIRCLE_SIZE,CIRCLE_SIZE);

}

Place* Customer::findtarget()
{
    if(this->list->isempty())
    {
        if(this->cart->isempty())
        {
            for(int i=0;i<this->storelist->count();i++)
            {
                if(this->storelist->at(i)->placetype()==3)
                {
                    return this->storelist->at(i);
                }
            }
        }
        else
        {
            for(int i=0;i<this->storelist->count();i++)
            {
                if(this->storelist->at(i)->placetype()==2)
                {
                    return this->storelist->at(i);
                }
            }
        }
    }
    else
    {
        for(int i=0;i<this->storelist->count();i++)
        {
            Place* place= this->storelist->at(i);
            if(place->placetype()==1)
            {
                Store* store = qgraphicsitem_cast<Store*>(place);
                if(store->hasGoods(this->list->read()))
                {
                    return place;
                }
            }
        }
    }
    return NULL;
}

void Customer::do_work(Place *place)
{
    if(place->placetype()==1)
    {
        Store* store = qgraphicsitem_cast<Store*>(place);
        int a=list->read();
        int amount = store->getGoods(a,list->count(a));
        cart->putGoods(a,amount);
        list->strikeout(a);

    }
    else if(place->placetype()==2)
    {
        Paybox* paybox = qgraphicsitem_cast<Paybox*>(place);
        paybox->calculation(this->cart);
    }
    else if(place->placetype()==3)
    {
        delete this;
        return;
    }
    QModelIndex topleft=createIndex(0,0);
    QModelIndex bottomright=createIndex(list->count() + cart->count()+2,0);
    emit dataChanged(topleft,bottomright);
}

int Customer::rowCount(const QModelIndex &parent) const
{
    return list->count() + cart->count()+3;
}


QVariant Customer::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    switch (role) {
    case Qt::DisplayRole:
        if (index.row() == 0) {
            return "Список покупок:";
        }
        else if (index.row() <= this->list->count()){
            int id = list->readAt(index.row() - 1);
            return this->info->get(id).name;
        }
        else if(index.row()==this->list->count()+1)
        {
            return "";
        }
        else if(index.row()==this->list->count()+2)
        {
            return "Корзина:";
        }
        else
        {
            int id = cart->getAt(index.row()-this->list->count()-3)->id;
            return this->info->get(id).name+" " +QString::number(this->info->get(id).price);
        }
        return QVariant();

    default:
        return QVariant();
    }
}
