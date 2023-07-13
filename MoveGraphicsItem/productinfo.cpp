#include "productinfo.h"

ProductInfo::ProductInfo()
{


}

void ProductInfo::filereader()
{
    this->info->append( {1,"    Молоко",100} );
    this->info->append( {2,"    Хлеб",200} );
    this->info->append( {3,"    Овощи",300} );
    this->info->append( {4,"    Фрукты",400} );
    this->info->append( {5,"    Напитки",500} );
    this->info->append( {6,"    Мясо",600} );
    this->info->append( {7,"    Конфеты",700} );
    this->info->append( {8,"    Алкоголь",800} );
}

Product ProductInfo::get(int id)
{
    Product a;
    for(int i=0;i < info->count() ;i++)
    {
        a=info->at(i);
        if(a.id==id)
        {
            return a;
        }
    }
    return {id, "неизв", 0};
}
