#ifndef STORE_H
#define STORE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <Goods.h>

class Store : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit Store(QObject *parent = 0);
    ~Store();
    int check=1;
    static int count;
    int id;
    void hello();
    virtual int type() const;
    enum{Type=UserType+1};
    int getGoods(int id, int amount);
    int putGoods(int id, int amount);
    void putGoods(QList<Goods*>* goods);
    void refreshGoods(int amount);
    bool hasGoods(int id);

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    int adx;
    int ady;
    QList<Goods*>* goodslist =new QList<Goods*>();

public slots:
    void slot();
signals:
    void update(int adx,int ady,int id);    

};

#endif // STORE_H
