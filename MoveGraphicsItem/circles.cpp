#include "circles.h"

using namespace std;

#define CIRCLE_SIZE 40


Circles::Circles(int xspread) : QGraphicsEllipseItem(0)
{
    bool flag;
        int numbers[8];
        srand(time(NULL));
        kolvo = rand() % 8 + 1;

        for (int i = 1; i <= kolvo; i++)
        {
            do {
                flag = 0;
                numbers[i-1] = rand()%8+1;
                for (int j = 1; j < i && flag!=1; j++)
                {
                    if(numbers[i-1]==numbers[j-1])
                    {
                        flag = 1;
                    }
                }
            } while (flag == 1);
        }
        numbers[kolvo]=9;
        cout << "\n"<<kolvo;
        cout << "\n";
        for (int n = 0; n <= kolvo; n++)
        {
            cout << " " << numbers[n];
        }
        cout << "\n";

    setBrush(Qt::green);
    setRect(0,0,CIRCLE_SIZE,CIRCLE_SIZE);
    //setPos(rand()%(xspread-CIRCLE_SIZE),0);
    setPos(350,0);
}

Circles::~Circles()
{
    cout<<"\n\nDestuctor";
    for (int i = 0; i<2 ; i++)
    {
        cout<<"\n";
            cout << " " << memx[i]<< " " << memy[i];
    }

}

void Circles::look(int *xcor, int *ycor)
{
    for (int i = 0; i<2 ; i++)
    {
            memx[i]=*(xcor + i);
            memy[i]=*(ycor + i);
    }
    cout<<"\n\nCircleMemory";
   for (int i = 0; i<2 ; i++)
   {
       cout<<"\n";
       cout << " " << memx[i] << " " << memy[i];
   }
   if(invert==-1)
    delete this;

}

void Circles::reverse()
{
    invert*=-1;
}

void Circles::advance(int phase)
{
    marker;
    if(invert==1)
    {
        if(phase) {
            if (marker == 2)
            {
                return;
            }

            int xspeed = memx[marker] == x() ? 0 : memx[marker] > x() ? 1 : -1;
            int yspeed = memy[marker] == y() ? 0 : memy[marker] > y() ? 1 : -1;
            moveBy(xspeed*speed, yspeed*speed);

            QList<QGraphicsItem*> list = scene()->collidingItems(this);
            if(!list.isEmpty())
            {
                MoveItem* moveitem = qgraphicsitem_cast<MoveItem*>(list[0]);
                if(moveitem != NULL)
                {
                    // moveitem->hello();
                    cout <<"\n"+ moveitem->id;
                    marker = moveitem->id + 1;
                }
            }
        }
    }
}

