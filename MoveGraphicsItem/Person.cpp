#include "Person.h"

using namespace std;

#define CIRCLE_SIZE 40


Person::Person() : QGraphicsEllipseItem(0)
{


    setBrush(Qt::green);
    setRect(0,0,CIRCLE_SIZE,CIRCLE_SIZE);
    //setPos(rand()%(xspread-CIRCLE_SIZE),0);
    setPos(350,0);
}

Person::~Person()
{



}

void Person::look(QList<Store*>* stores)
{
    this->storelist=stores;

   if(invert==-1)
    delete this;

}

void Person::reverse()
{
    invert*=-1;
}

void Person::advance(int phase)
{
    int speed=3;

    if(invert==1)
    {
        if(!phase) {
            Store* target = this->findtarget();
            if(target==NULL)
            {
                return;
            }
            int xspeed = target->x() == x() ? 0 : target->x() > x() ? 1 : -1;
            int yspeed = target->y() == y() ? 0 : target->y() > y() ? 1 : -1;
            moveBy(xspeed*speed, yspeed*speed);

            foreach (QGraphicsItem* item, collidingItems())
            {
               Store* obj = qgraphicsitem_cast<Store*>(item);
               if(obj)
               {
                   if(obj->id==target->id)
                   {
                       do_work(target);
                   }
               }

            }
        }
    }
}

void Person::do_work(Store *store)
{

}

Store *Person::findtarget()
{

}


