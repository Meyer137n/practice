#ifndef STAFF_H
#define STAFF_H

#include <QMainWindow>
#include <QObject>
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
#include <Person.h>

class Staff :public Person
{
public:
    Staff();
    ~Staff();

private:
     virtual void do_work(Place *store);
     virtual Place* findtarget();
    int targetIndex=0;
};

#endif // STAFF_H
