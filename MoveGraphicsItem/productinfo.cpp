#include "productinfo.h"

ProductInfo::ProductInfo()
{


}

void ProductInfo::filereader()
{
    this->info->append( {1,"Молоко",100} );
    this->info->append( {2,"bread",200} );
    this->info->append( {3,"vegetables",300} );
    this->info->append( {4,"fruits",400} );
    this->info->append( {5,"drink",500} );
    this->info->append( {6,"meat",600} );
    this->info->append( {7,"sweet",700} );
    this->info->append( {8,"alcochol",800} );
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
