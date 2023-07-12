#ifndef PLACE_H
#define PLACE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QStandardItemModel>

class Place : public QAbstractListModel, public QGraphicsItem
{
    Q_OBJECT

public:
   Place(QObject *parent = 0);
   int check=1;
   virtual int type() const;
   enum{Type=UserType+1};
   int id;
   virtual int placetype();

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    static int count;

public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;

public slots:
    void slot();

signals:
    void click(QAbstractListModel* model);
};

#endif // PLACE_H
