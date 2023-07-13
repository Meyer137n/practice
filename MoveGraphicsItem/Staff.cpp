#include "Staff.h"

using namespace std;

#define CIRCLE_SIZE 40

Staff::Staff()
{
    setBrush(Qt::blue);
    setRect(0,0,CIRCLE_SIZE,CIRCLE_SIZE);
    //setPos(rand()%(xspread-CIRCLE_SIZE),0);
}

Staff::~Staff()
{

}

void Staff::do_work(Place *place)
{
    Store* store = qgraphicsitem_cast<Store*>(place);
    store->refreshGoods(10);
    targetIndex++;
}

Place *Staff::findtarget()
{
    if(storelist->count()==0)
    {
        return NULL;
    }
    if(targetIndex>=storelist->count())
    {
        targetIndex=0;
    }
    return storelist->at(targetIndex);
}

void Staff::look(QList<Place*>* stores)
{
    this->storelist->clear();
    for(int i=0;i<stores->count();i++)
    {
        if(stores->at(i)->placetype()==1)
        {
            storelist->append(stores->at(i));
        }
    }
}
