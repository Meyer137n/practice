#ifndef CIRCLES_H
#define CIRCLES_H

#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>

#include <QTimer>
#include <QString>

#include <QStandardItemModel>
#include <iostream>
#include <QKeyEvent>
#include <moveitem.h>


using namespace std;


//circle class
class Circles :public QObject, public QGraphicsEllipseItem
{

public:
    Circles(int xspread);
    ~Circles();
    virtual void advance(int phase);

private:
    int speed=3;
    int kolvo=0;
    int numbers[9];
    int flag=0;
    int invert=1;

    int memx[4];
    int memy[4];
    int marker=0;
    ////QList<MoveItem*> moveItems;

public slots:
    void look(int *xcor, int *ycor);
    void reverse();

};


#endif // WIDGET_H
