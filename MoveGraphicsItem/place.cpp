#include "place.h"

int Place::count=0;

int Place::type() const
{
    return Type;
}

int Place::placetype()
{
  return 0;
}

Place::Place(QObject *parent) :  QGraphicsItem()
{
    id=count;
    count++;
}

QRectF Place::boundingRect() const
{
    return QRectF (-50,-50,90,200);
}

void Place::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::black);

    QColor color = QColor(205,140,40);
    painter->setBrush(color);

    painter->drawRect(-50,-50,90,200);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

void Place::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void Place::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    if(check==-1)
    {
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
    }
    emit click(this);
}

void Place::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    if(check==-1)
    {
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);

        //emit update();
    }
}

int Place::rowCount(const QModelIndex &parent) const
{

}

QVariant Place::data(const QModelIndex &index, int role) const
{

}

void Place::slot()
{
    check*=-1;
}
