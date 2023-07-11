#ifndef PERSON_H
#define PERSON_H

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
#include <Store.h>
#include <Goods.h>

using namespace std;


//circle class
class Person :public QObject, public QGraphicsEllipseItem
{

public:
    Person();
    ~Person();

private:

    int invert=1;
    int marker=0;

public slots:
    void look(QList<Store*>*);
    void reverse();

protected:
    QList<Store*>* storelist=new QList<Store*>();
    virtual void advance(int phase);
    virtual void do_work(Store* store);
    virtual Store* findtarget();

};


#endif // WIDGET_H
