//
// Created by Ale on 3/15/2023.
//
#include "Product.h"
#include <string.h>
Product create_Product(char name[],char type[],int quantity,char expire_date[])
{
    /*
     * Here the product is created and the parameters: name = name of the product, type = the type of the product, quantity = the quantity of the product and
     * expire_date = the expire date of the product
     * Returns a product.
     */
    Product p;
    strcpy(p.name,name);
    strcpy(p.type,type);
    strcpy(p.expire_date,expire_date);
    p.quantity=quantity;

    return p;
}

char* getName(Product* p)
{
    return p->name;
}
char* getType(Product* p)
{
    return p->type;
}
int getQuantity(Product* p)
{
    return p->quantity;
}
char* getDate(Product* p)
{
    return  p->expire_date;
}