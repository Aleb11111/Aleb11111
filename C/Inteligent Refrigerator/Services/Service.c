//
// Created by Ale on 3/15/2023.
//
#include "Service.h"
#include <stdlib.h>

Service* createServices(Repository* repo,Undo_Redo* undoRedo)
{
    /*
     * Parameters: repo = the repository, undoRedo = the repository for the unde_reod
     */
    Service* service =(Service*)malloc(sizeof(Service));

    if(service == NULL)
        return NULL;
    service->repository = repo;
    service->undeRedo = undoRedo;
    return service;
}

void add_product_s(Service* service, char name[], char type[], int quantity, char date[])
{
    /*
     * Parameters: service = the service, name = the name of the product we will add, type = the type of the product, quantity = the quantity of the product
     * date = the expiration date of the product
     */
    add_product_r(service->repository, name, type, quantity, date);
}

int delete_product_s(Service* service, char name[], char type[])
{
    /*
     * Parameters: service = the service, name = the name of the product that we want to delete, type = the type of the product
     * Returns 0 if the product already is deleted from the array / 1 if the product is deleted with success.
     */
    if(delete_product_r(service->repository, name, type) == 0)
        return 0;
    return 1;
}
int update_product_s(Service* service,char name[],char type[],int quantity,char expir_date[])
{
    /*
     * Parameters: service = the service, name = the name of the product we will update, type = the type of the product, quantity = the new quantity,
     * expiration_date = the new expiration date
     *  Return 0 is the product isn't in the array / 1 if the product is updated with success
     */
    if(update_product_r(service->repository,name,type,quantity,expir_date) == 0)
        return 0;
    return 1;
}

void dislay_elements_by_string_s(Service* service,char string[])
{
    /*
     * Parameters: service = the service, string  = the string which we search for
     */
    display_elements_by_string_r(service->repository,string);
}

void display_elements_by_category_s(Service* serv,char type[],int x)
{
    /*
     * Parameters: serv = the service, category = the category that we search for
     * x is the number of days.
     */
    display_elements_by_category_r(serv->repository,type,x);
}
void copy_repo_service(Service* service, Undo_Redo* UndoRedo)
{
    /*
     * Parameters: service = the service, undoRedo = the repository for undo_redo
     * The repository is inlocuit
     */
    service->repository->array->count = UndoRedo->contents[UndoRedo->pos_current]->count;
    service->repository->array->max_length = UndoRedo->contents[UndoRedo->pos_current]->max_length;
    for(int i = 0; i < UndoRedo->contents[UndoRedo->pos_current]->count; i++)
        service->repository->array->data[i] = UndoRedo->contents[UndoRedo->pos_current]->data[i];
}

void initialize(Service* serv)
{
    /*
     * Here are initialized the 10 initial entities.
     */
    add_product_s(serv, "Banana", "fruit", 100, "01.04.2023");
    add_product_s(serv, "Apple", "fruit", 50, "01.04.2024");
    add_product_s(serv, "Lemon", "fruit", 6, "06.04.2024");
    add_product_s(serv, "Chocolate", "sweets", 70, "06.09.2024");
    add_product_s(serv, "Chicken", "meat", 10, "06.02.2023");
    add_product_s(serv, "Pork", "meat", 40, "16.03.2023");
    add_product_s(serv, "IceCream", "sweets", 70, "06.09.2024");
    add_product_s(serv, "Cheese", "diary", 70, "06.09.2023");
    add_product_s(serv, "Beef", "meat", 10, "01.05.2023");
    add_product_s(serv, "Eggs", "diary", 40, "16.03.2023");
    serv->undeRedo->contents[0]= duplicate_repo(serv->repository->array);
}

void distroy_serv(Service* serv)
{
    /*
     * Here the service is distroyed
     */
    if (serv == NULL)
        return;

    free(serv);
}