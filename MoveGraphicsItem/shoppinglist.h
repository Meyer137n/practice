#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H

#include <QObject>
#include <QWidget>

class Shoppinglist
{
public:
    Shoppinglist();
    void write(int id);
    void strikeout(int id);
    int read();
    int count(int id);
    bool isempty();
private:
    QList<int>* list = new QList<int>();
};

#endif // SHOPPINGLIST_H
