#include "paybox.h"
#include "productinfo.h"

Paybox::Paybox(ProductInfo *info)
    : Place()
{
    this->info=info;
}

int Paybox::placetype()
{
    return 2;
}

QRectF Paybox::boundingRect() const
{
    return QRectF (-30,-30,180,90);
}

void Paybox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::black);
    QColor color = QColor(100,200,255);
    painter->setBrush(color);

    painter->drawRect(-30,-30,150,70);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

int Paybox::rowCount(const QModelIndex &parent) const
{
    return transactions->count()+4;
}

QVariant Paybox::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    switch (role) {
    case Qt::DisplayRole:
        if (index.row() == 0)
        {
            return "Сумма:";
        }
        else if (index.row() == 1)
        {
            return cash;
        }
        else if (index.row() == 2)
        {
            return " ";
        }
        else if (index.row() == 3)
        {
            return "Транзакции: ";
        }
        else {
            return "+" + QString::number(transactions->at(index.row()-4));
        }

    default:
        return QVariant();
    }
}

void Paybox::calculation(Cart *cart)
{
    double summ=0;
    for(int i=0;i<cart->count();i++)
    {
        Goods* goods = cart->getAt(i);
        Product product=info->get(goods->id);
        summ += product.price * goods->amount;
    }
    cash+=summ;
    transactions->append(summ);
    cart->clear();
    this->update(transactions->count()+4);
}
