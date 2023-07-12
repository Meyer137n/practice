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
class Person : public QAbstractListModel, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Person();
    ~Person();

private:

    int invert=1;
    int marker=0;

public slots:
    void look(QList<Place*>*);
    void reverse();

protected:
    QList<Place*>* storelist=new QList<Place*>();
    virtual void advance(int phase);
    virtual void do_work(Place* store);
    virtual Place* findtarget();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void click(QAbstractListModel* model);

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
};


#endif // WIDGET_H
