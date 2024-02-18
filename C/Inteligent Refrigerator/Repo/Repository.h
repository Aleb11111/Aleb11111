//
// Created by Ale on 3/15/2023.
//

#ifndef A23_ALEB1111_REPOSITORY_H
#define A23_ALEB1111_REPOSITORY_H

#endif //A23_ALEB1111_REPOSITORY_H
#pragma once
#include "../Domains/DynArr.h"

typedef struct
{
    DynamicArray* array;
}Repository;

Repository* createRepo(DynamicArray* arr);
char* get_specific_name_r(Repository* repo,int i);
char* get_specific_type_r(Repository* repo,int i);
int get_specific_quantity_r(Repository* repo, int i);
char* get_specific_date_r(Repository* repo, int i);
void set_specific_name(Repository* repo,int i,char new_name[]);
void set_specific_type(Repository* repo,int i,char new_type[]);
int does_the_product_exist(Repository* repo, char name[], char type[]);
void add_product_r(Repository* repo, char name[], char type[], int quantity, char date[]);
int delete_product_r(Repository* repo, char name[], char type[]);
int update_product_r(Repository* repo,char name[],char type[],int quantity, char expiration_date[]);
void display_elements_by_string_r(Repository* repo, char string[]);
void display_elements_by_category_r(Repository* repo,char category[],int x);
void destroy(Repository * array);
int expires_in_x_days(char date[],int days);

