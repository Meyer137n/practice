#include "Customer.h"
#define CIRCLE_SIZE 40

Customer::Customer()
{
    bool flag;
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

Store* Customer::findtarget()
{
    if(this->list->isempty())
    {
        return NULL;
    }
    for(int i=0;i<this->storelist->count();i++)
    {
        Store* store= this->storelist->at(i);
        if(store->hasGoods(this->list->read()))
        {
            return store;
        }
    }
    return NULL;
}

void Customer::do_work(Store *store)
{
    int a=list->read();
    store->getGoods(a,list->count(a));
    list->strikeout(a);
}
