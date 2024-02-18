//
// Created by Ale on 3/15/2023.
//
#include <time.h>
#include <ctype.h>
#include "Repository.h"
#include "DynArr.h"
//#include "../Domains/Product.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./DynArr.h"

char* get_specific_name_r(Repository* repo,int i)
{
    return repo->array->data[i].name;
}

char* get_specific_type_r(Repository* repo,int i)
{
    return repo->array->data[i].type;
}

int get_specific_quantity_r(Repository* repo, int i)
{
    return repo->array->data[i].quantity;
}

char* get_specific_date_r(Repository* repo, int i)
{
    return repo->array->data[i].expire_date;
}

void set_specific_name(Repository* repo,int i,char new_name[])
{
    strcpy(repo->array->data[i].name,new_name);
}

void set_specific_type(Repository* repo,int i,char new_type[])
{
    strcpy(repo->array->data[i].type,new_type);
}
void set_specific_quantity(Repository* repo,int i,int new_quan)
{
    repo->array->data[i].quantity = new_quan;
}
void set_specific_date(Repository* repo,int i,char new_date[])
{
    strcpy(repo->array->data[i].expire_date,new_date);
}


Repository* createRepo(DynamicArray* arr)
{
    /*
     * creates a repository.
     * the parameter arr is the array of the repository.
     * Return the created repository
     */
    Repository* repo = (Repository*)malloc(sizeof(Repository));
    //make sure that the space was allocated
    if (repo == NULL)
        return NULL;

    repo->array = arr;

    return repo;
}

int does_the_product_exist(Repository* repo, char name[], char type[])
{
    /*
     * Parameters: repo = the repository, name the name of the product we want to see if it exists or not, type = the type of the product.
     * return 0 if the product doesn't exist and if it exits returns it's position.
     */
    for(int i = 0; i <= repo->array->count; i++)
        if((strcmp(get_specific_name_r(repo,i), name) == 0) && (strcmp(get_specific_type_r(repo,i), type)==0))
            return i;
    return -1;
}

void add_product_r(Repository* repo, char name[], char type[], int quantity, char date[])
{
    /*
     * Parameters: repo = the repository, name = the name of the product we will add, type = the type of the product, quantity = the quantity of the product
     * date = the expiration date of the product
     */
    int position;
    position = does_the_product_exist(repo, name, type);
    if(position == -1)
    {
        Product product;
        product = create_Product(name, type, quantity, date);
        add_TElem(repo->array, product);
    }
    else
    {
        repo->array->data[position].quantity = repo->array->data[position].quantity + quantity;
    }


}

int delete_product_r(Repository* repo, char name[], char type[])
{
    /*
     * Parameters: repo = the repository, name = the name of the product that we want to delete, type = the type of the product
     * Returns 0 if the product already is deleted from the array / 1 if the product is deleted with success.
     */
    int position;
    position = does_the_product_exist(repo, name, type);
    if(position == -1)
        return 0;
    else
    {
        delete_TElem(repo->array, position);
        return 1;
    }
}

int update_product_r(Repository* repo,char name[],char type[],int quantity, char expiration_date[])
{
    /*
     * Parameters: repo = the repository, name = the name of the product we will update, type = the type of the product, quantity = the new quantity,
     * expiration_date = the new expiration date
     *  Return 0 is the product isn't in the array / 1 if the product is updated with success
     */
    int position;
    position = does_the_product_exist(repo,name,type);
    if(position == -1)
        return 0;

    set_specific_quantity(repo,position,quantity);
    set_specific_date(repo,position,expiration_date);
    return 1;
}

Repository* sot_asc(Repository* r)
{
    /*
     *Parameters: r = the  repository
     * Here the displayed products are sorted
     */
    for(int i = 0; i < r->array->count-1; i++)
        for(int j = i + 1; j < r->array->count; j++) {
            int e1,e2;
            e1= get_specific_quantity_r(r,i);
            e2 = get_specific_quantity_r(r,j);
            if (e1 > e2) {
                Product aux = r->array->data[i];
                r->array->data[i] = r->array->data[j];
                r->array->data[j] = aux;
            }
        }
    return r;
}

void display_elements_by_string_r(Repository* repo, char string[])
{
    /*
     * Parameters: repo = the repository, string  = the string which we search for
     */
    DynamicArray* da;
    da = careateArray(100);
    Repository* aux;
    aux = createRepo(da);
    if(strcmp(string,"''") == 0)
    {
        for(int i=0;i<repo->array->count;i++)
            add_product_r(aux,repo->array->data[i].name,repo->array->data[i].type, repo->array->data[i].quantity,repo->array->data[i].expire_date);
            /*printf("Name: %s  Type: %s  Quantity: %d  Expiration date: %s\n", repo->array->data[i].name,
                   repo->array->data[i].type, repo->array->data[i].quantity,repo->array->data[i].expire_date);*/
        aux = sot_asc(aux);
        for(int i=0;i<aux->array->count;i++)
            printf("Name: %s  Type: %s  Quantity: %d  Expiration date: %s\n", aux->array->data[i].name,
                   aux->array->data[i].type, aux->array->data[i].quantity,aux->array->data[i].expire_date);
    }
    else
    {
        for(int i=0;i<repo->array->count;i++)
        {
            char nume[50];
            for(int j=0;j<strlen(repo->array->data[i].name);j++)
            {
                nume[j]= tolower(repo->array->data[i].name[j]);
            }
            for(int j=0;j<strlen(string);j++)
            {
                string[j]= tolower(string[j]);
            }
            if(strstr(nume,string))
                add_product_r(aux,repo->array->data[i].name,repo->array->data[i].type, repo->array->data[i].quantity,repo->array->data[i].expire_date);

        }
        for(int i=0;i<aux->array->count;i++)
            printf("Name: %s  Type: %s  Quantity: %d  Expiration date: %s\n", aux->array->data[i].name,aux->array->data[i].type, aux->array->data[i].quantity,aux->array->data[i].expire_date);
    }
    distroy_dynArr(da);

}


void display_elements_by_category_r(Repository* repo,char category[],int x)
{
    /*
     * Parameters: repo = the repository, category = the category that we search for
     * x is the number of days.
     */
    DynamicArray* da;
    da = careateArray(100);
    Repository * aux_repo = createRepo(da);
    if(strcmp(category,"''") == 0)
    {
        //aux_repo->array = repo->array;
        for(int i=0;i<=repo->array->count;i++)
        {
            if(expires_in_x_days(get_specific_date_r(repo,i),x) == 1)
                add_product_r(aux_repo, get_specific_name_r(repo,i), get_specific_type_r(repo,i),
                              get_specific_quantity_r(repo,i), get_specific_date_r(repo,i));
        }
    }
    else
    {
        for(int i=0;i<=repo->array->count;i++)
        {
            char ty[30];
            strcpy(ty,get_specific_type_r(repo,i));
            if(strcmp(get_specific_type_r(repo,i),category)==0)
                if(expires_in_x_days(get_specific_date_r(repo,i),x) == 1)
                    add_product_r(aux_repo, get_specific_name_r(repo,i), get_specific_type_r(repo,i),
                                  get_specific_quantity_r(repo,i), get_specific_date_r(repo,i));
        }
    }
    for(int i=0;i<aux_repo->array->count;i++)
        printf("Name: %s  Type: %s  Quantity: %d  Expiration date: %s\n", aux_repo->array->data[i].name,aux_repo->array->data[i].type, aux_repo->array->data[i].quantity,aux_repo->array->data[i].expire_date);
    distroy_dynArr(da);
    destroy(aux_repo);
}

void destroy(Repository * repo)
{
    /*
     * Here the repository is distroyed
     */
    if (repo == NULL)
        return;

    free(repo->array);
    repo->array->data = NULL;

    free(repo);
}

int expires_in_x_days(char date[],int days)
{
    /*
     * Here we see if the product will expire in x days or not
     */
    char *p;
    char new[3][5];
    int i=0;
    new[0][0]=date[0];
    new[0][1]=date[1];
    new[1][0]=date[3];
    new[1][1]=date[4];
    new[2][0]=date[6];
    new[2][1]=date[7];
    new[2][2]=date[8];
    new[2][3]=date[9];

    int day,month,year;

    day = atoi(new[0]);
    month = atoi(new[1]);
    year = atoi(new[2]);

    time_t t;
    t = time(NULL);

    struct tm today = *localtime(&t);

    int zi_azi,luna_azi,an_azi;

    zi_azi = today.tm_mday;
    luna_azi = today.tm_mon + 1;
    an_azi = today.tm_year + 1900;

    int ex_day,exp_mon,exp_year;

    if(zi_azi + days > 31)
    {
        ex_day = zi_azi + days - 31;
        days-=ex_day;
        luna_azi++;
        while(ex_day > 31)
        {
            ex_day = ex_day - 31;
            days-=ex_day;
            luna_azi++;
        }
        if(luna_azi>12)
        {
            exp_mon = 1;
            exp_year = an_azi +1;
        }
        else
        {
            exp_mon = luna_azi;
            exp_year = an_azi;
        }
    }
    else
    {
        ex_day = zi_azi+days;
        exp_mon = luna_azi;
        exp_year = an_azi;
    }

    if (year > exp_year)
        return 0;
    if(year == exp_year && month > exp_mon)
        return 0;
    if ( year == exp_year && month == exp_mon && day > ex_day)
        return 0;

    return 1;



}