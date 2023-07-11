#include "shoppinglist.h"

Shoppinglist::Shoppinglist()
{

}

void Shoppinglist::write(int id)
{
    list->append(id);
}

void Shoppinglist::strikeout(int id)
{
    list->removeAll(id);
}

int Shoppinglist::read()
{
    return list->first();
}

int Shoppinglist::count(int id)
{
    return list->count(id);
}

bool Shoppinglist::isempty()
{
    return list->count()==0;
}
