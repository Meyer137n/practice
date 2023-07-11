#ifndef GOODS_H
#define GOODS_H

#include <QObject>
#include <QWidget>

class Goods
{
public:
    Goods();
    Goods(int id, int amount);
    int id;
    int amount=10;
    int attractivness;
};

#endif // GOODS_H
