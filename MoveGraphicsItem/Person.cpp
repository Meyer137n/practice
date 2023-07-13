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

void Person::look(QList<Place*>* stores)
{
    this->storelist=stores;
}

void Person::reverse(int flag)
{
    invert=flag;
}

void Person::advance(int phase)
{
    int speed=2;

    if(invert==1)
    {
        if(!phase) {
            Place* target = this->findtarget();
            if(target==NULL)
            {
                return;
            }
            int xspeed = target->x() == x() ? 0 : target->x() > x() ? 1 : -1;
            int yspeed = target->y() == y() ? 0 : target->y() > y() ? 1 : -1;
            moveBy(xspeed*speed, yspeed*speed);

            foreach (QGraphicsItem* item, collidingItems())
            {
               Place* obj = qgraphicsitem_cast<Place*>(item);
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

void Person::do_work(Place *store)
{

}

Place *Person::findtarget()
{

}

void Person::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit click(this);
}

int Person::rowCount(const QModelIndex &parent) const
{
}

QVariant Person::data(const QModelIndex &index, int role) const
{
}
