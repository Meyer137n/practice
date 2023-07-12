#ifndef PRODUCTINFO_H
#define PRODUCTINFO_H

#include <QString>
#include <QObject>
#include <QWidget>

struct Product
{
    int id;
    QString name;
    double price;
};


class ProductInfo
{

public:
    ProductInfo();
    void filereader();
    Product get(int id);

private:
    QList<Product>* info = new QList<Product>();
};

#endif // PRODUCTINFO_H
