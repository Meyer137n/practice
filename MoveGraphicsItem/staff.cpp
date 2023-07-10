#include "staff.h"

using namespace std;

#define CIRCLE_SIZE 50

staff::staff()
{
    QColor color = QColor(rand()%255,rand()%255,rand()%255) ;
    setBrush(color);
    setRect(0,0,CIRCLE_SIZE,CIRCLE_SIZE);
    //setPos(rand()%(xspread-CIRCLE_SIZE),0);
    setPos(50,30);
}

staff::~staff()
{

}

void staff::advance(int phase)
{
    if(invert==1)
    {
    if(flag2==0)
    {
        if(phase)
        {
            moveBy(0,yspeed);
        }
        if(this->y()==550)
        {
            flag2=1;
        }
    }
    else{
        if(phase)
        {
            moveBy(0,-yspeed);
        }
        if(this->y()==0)
        {
            flag2=0;
        }
    }
    }
}
