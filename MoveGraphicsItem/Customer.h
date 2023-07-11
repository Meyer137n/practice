#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "shoppinglist.h"
#include <QObject>
#include <QWidget>

class Customer : public Person
{
public:
    Customer();

private:
    QList<Goods*>* cart = new QList<Goods*>();
    virtual Store* findtarget();
    virtual void do_work(Store* store);
    Shoppinglist* list=new Shoppinglist();
};

#endif // CUSTOMER_H
