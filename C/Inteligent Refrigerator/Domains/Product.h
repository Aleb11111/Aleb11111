//
// Created by Ale on 3/15/2023.
//

#ifndef A23_ALEB1111_PRODUCT_H
#define A23_ALEB1111_PRODUCT_H

#endif //A23_ALEB1111_PRODUCT_H

typedef struct{

    char name[50],type[50],expire_date[10];
    int quantity;

}Product;

Product create_Product(char name[],char type[],int quantity,char expire_date[]);
char* getName(Product* p);
char* getType(Product* p);
int getQuantity(Product* p);
char* getDate(Product* p);