#include "Store.h"
#include "iostream"
#include <QDebug>

using namespace std;

int Store::count = 0;

Store::Store(QObject *parent) : QObject(parent), QGraphicsItem()
{
    id=count;
     count++;
}

Store::~Store()
{

}

void Store::hello()
{
cout<<endl<<id<<") Hello";
}


QRectF Store::boundingRect() const
{
    return QRectF (-50,-50,90,200);
}

void Store::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::black);

    QColor color = QColor(205,140,40);
    painter->setBrush(color);

    painter->drawRect(-50,-50,90,200);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

void Store::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void Store::mousePressEvent(QGraphicsSceneMouseEvent *event)
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

void Store::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
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

void Store::slot()
{
    check*=-1;
}

int Store::type() const
{
    return Type;
}

int Store::getGoods(int id, int amount)
{

    for(int i=0;i<this->goodslist->count();i++)
    {
        Goods* goods= this->goodslist->at(i);
        if(goods->id==id)
        {
            if(goods->amount>=amount)
            {
                goods->amount-=amount;
                return amount;
            }
            else
            {
                int buf=goods->amount;
                goods->amount=0;
                return buf;
            }
        }
    }
}

int Store::putGoods(int id, int amount)
{
    for(int i=0;i<this->goodslist->count();i++)
    {
        Goods* goods= this->goodslist->at(i);
        if(goods->id==id)
        {
            goods->amount+=amount;
            return goods->amount;
        }
    }
    Goods* goods= new Goods(id,amount);
    this->goodslist->append(goods);
    return amount;

}

void Store::putGoods(QList<Goods *> *goods)
{
    for(int i=0;i<goods->count();i++)
    {
        Goods* g= goods->at(i);
        this->putGoods(g->id,g->amount);
    }
}

void Store::refreshGoods(int amount)
{
    for(int i=0;i<this->goodslist->count();i++)
    {
        Goods* goods = this->goodslist->at(i);
        goods->amount=amount;
    }
}

bool Store::hasGoods(int id)
{
    for(int i=0;i<this->goodslist->count();i++)
    {
        Goods* goods= this->goodslist->at(i);
        if(goods->id==id)
        {
            return true;
        }
    }
    return false;
}
