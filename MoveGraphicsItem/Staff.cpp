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
    if(targetIndex>=storelist->count()-1)
    {
        targetIndex=0;
    }
    return storelist->at(targetIndex);
}

