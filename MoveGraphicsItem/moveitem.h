#ifndef MOVEITEM_H
#define MOVEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <widget.h>

class MoveItem : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit MoveItem(QObject *parent = 0);
    ~MoveItem();
    int check=1;

    static int count;
    int id;
    void hello();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    int adx;
    int ady;

public slots:
    void slot();
signals:
    void update(int adx,int ady,int id);


};

#endif // MOVEITEM_H
