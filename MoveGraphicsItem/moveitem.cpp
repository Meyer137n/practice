#include "moveitem.h"
#include "iostream"

int MoveItem::count = 0;

MoveItem::MoveItem(QObject *parent) : QObject(parent), QGraphicsItem()
{
    id=count;
     count++;
}

MoveItem::~MoveItem()
{

}

void MoveItem::hello()
{
cout<<endl<<id<<") Hello";
}


QRectF MoveItem::boundingRect() const
{
    return QRectF (-50,-50,90,200);
}

void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::black);

    QColor color = QColor(205,140,40);
    painter->setBrush(color);

    painter->drawRect(-50,-50,90,200);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

void MoveItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(check==-1)
    {
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
    }
}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    if(check==-1)
    {
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
    }
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    if(check==-1)
    {
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
        cout<<endl<<id<<")"<<x()<<" "<<y();
        adx=x();
        ady=y();
        emit update(adx,ady,id);
    }
}

void MoveItem::slot()
{
    check*=-1;
}
