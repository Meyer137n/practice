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

class staff :public QObject, public QGraphicsEllipseItem
{
public:
    staff();
    ~staff();
    virtual void advance(int phase);

private:
    int yspeed=2;
    int numbers[9];
    int flag;
    int flag2=0;
    int invert=1;
};

#endif // STAFF_H
