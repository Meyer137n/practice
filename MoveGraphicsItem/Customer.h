#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "cart.h"
#include "productinfo.h"
#include "shoppinglist.h"
#include "paybox.h"
#include "door.h"
#include <QObject>
#include <QWidget>

class Customer : public Person
{
    Q_OBJECT
public:
    Customer(ProductInfo* info);

private:
    virtual Place* findtarget();
    virtual void do_work(Place* store);
    Shoppinglist* list=new Shoppinglist();
    Cart* cart= new Cart();
    ProductInfo* info;

    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
};

#endif // CUSTOMER_H
