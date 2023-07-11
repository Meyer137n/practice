#include "Staff.h"

using namespace std;

#define CIRCLE_SIZE 50

Staff::Staff()
{
    setBrush(Qt::blue);
    setRect(0,0,CIRCLE_SIZE,CIRCLE_SIZE);
    //setPos(rand()%(xspread-CIRCLE_SIZE),0);
}

Staff::~Staff()
{

}

void Staff::do_work(Store *store)
{
    store->refreshGoods(10);
    targetIndex++;
}

Store *Staff::findtarget()
{
    if(targetIndex>=storelist->count())
    {
        targetIndex=0;
    }
    return storelist->at(targetIndex);
}

