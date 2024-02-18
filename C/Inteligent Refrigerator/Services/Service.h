//
// Created by Ale on 3/15/2023.
//

#ifndef A23_ALEB1111_SERVICE_H
#define A23_ALEB1111_SERVICE_H

#endif //A23_ALEB1111_SERVICE_H

#pragma once
#include "Repository.h"
#include "Undo_Redo.h"
typedef struct
{
    Repository* repository;
    Undo_Redo* undeRedo;
}Service;

Service* createServices(Repository* repo,Undo_Redo* undoRedo);

void add_product_s(Service* service, char name[], char type[], int quantity, char date[]);
int delete_product_s(Service* service, char name[], char type[]);
int update_product_s(Service* service,char name[],char type[],int quantity,char expir_date[]);
void dislay_elements_by_string_s(Service* service,char string[]);
void initialize(Service* serv);
void distroy_serv(Service* serv);
void display_elements_by_category_s(Service* serv,char type[],int x);
void copy_repo_service(Service* service, Undo_Redo* UndoRedo);


