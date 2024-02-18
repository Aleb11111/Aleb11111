//
// Created by Ale on 3/15/2023.
//
#include <string.h>
#include <stdio.h>
#include "UI.h"
#include <malloc.h>
#include <stdlib.h>
UI* create_UI(Service* service)
{
    UI* ui = (UI*)malloc(sizeof (UI));
    if(ui == NULL)
        return NULL;
    ui->service = service;
    return ui;
}

void distroy_UI(UI* ui)
{
    distroy_dynArr(ui->service->repository->array);
    distroy_undo_redo(ui->service->undeRedo);
    distroy_serv(ui->service);
    free(ui);
}

void menu()
{
    printf("Menu:\n");
    printf("1. Add Product.\n");
    printf("2. Delete product.\n");
    printf("3. Update product.\n");
    printf("4. Display all products whose name contains a given string.\n");
    printf("5. Display all the products form a category that expiers in n days.\n");
    printf("6. Undo.\n");
    printf("7. Redo.\n");
    printf("8. Exit.\n");
}
int verificare_type(char type[])
{
    char s[5][10];
    strcpy(s[1],"dairy");
    strcpy(s[2],"fruit");
    strcpy(s[3],"sweets");
    strcpy(s[4],"meat");

    if(strcmp(type,s[1]) !=0 && strcmp(type,s[2]) !=0 && strcmp(type,s[3])!=0 && strcmp(type,s[4])!=0)
        return 0;
    return 1;
}

int verificare_data(char date[])
{
    char new[3][5];
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
    if(day < 0 || day > 31 || month<0 || month > 12 || year < 2023 || year > 2050)
        return 0;
    return 1;
}
void add_product_ui(UI* ui)
{
    //add_undo_redo(ui->service->undeRedo,ui->service->repository);
    char name[100] = "";
    char type[100] = "";
    int quantity;
    char date[100] = "";
    printf("Type in the name of the product: ");
    scanf("%s",name);
    printf("\n");
    printf("Type in the type of the product: ");
    scanf("%s",type);
    while(verificare_type(type)==0)
    {
        printf("Not valid try another one: ");
        scanf("%s",type);
    }
    printf("\n");

    printf("Type the quantity: ");
    scanf("%d",&quantity);
    while(quantity <0 || quantity > 100000 || (quantity*2)/2 != quantity)
    {
        printf("Not valid type another quantity: ");
        scanf("%d",&quantity);
    }

    printf("\n");
    printf("Type the new expiration date: ");
    scanf("%s",date);
    while(verificare_data(date) == 0)
    {
        printf("Not valid try another date: ");
        scanf("%s",date);
    }
    printf("\n");
    add_product_s(ui->service,name,type,quantity,date);

    add_undo_redo(ui->service->undeRedo,ui->service->repository);

}
void delete_product_ui(UI* ui)
{
    //add_undo_redo(ui->service->undeRedo,ui->service->repository);
    char name[100] = "";
    char type[100] = "";
    printf("Type in the name of the product: ");
    scanf("%s",name);
    printf("\n");
    printf("Type in the type of the product: ");
    scanf("%s",type);
    while(verificare_type(type)==0)
    {
        printf("Not valid try another one: ");
        scanf("%s",type);
    }
    printf("\n");
    int sem;
    sem = delete_product_s(ui->service,name,type);
    if(sem ==1)
        printf("The product was deleted.\n");
    add_undo_redo(ui->service->undeRedo,ui->service->repository);
}

void update_product_ui(UI* ui)
{
    //add_undo_redo(ui->service->undeRedo,ui->service->repository);
    char name[100] = "";
    char type[100] = "";
    printf("Type in the name of the product: ");
    scanf("%s",name);
    printf("\n");
    printf("Type in the type of the product: ");
    scanf("%s",type);
    while(verificare_type(type)==0)
    {
        printf("Not valid try another one: ");
        scanf("%s",type);
    }
    printf("\n");

    int quantity;
    printf("Type the new quantity: ");
    scanf("%d",&quantity);
    while(quantity <0 || quantity > 100000)
    {
        printf("Not valid type another quantity: ");
        scanf("%d",&quantity);
    }

    char date[100] = "";

    printf("\n");
    printf("Type the new expiration date: ");
    scanf("%s",date);
    while(verificare_data(date) == 0)
    {
        printf("Not valid try another date: ");
        scanf("%s",date);
    }
    printf("\n");

    update_product_s(ui->service,name,type,quantity,date);
    //2
    add_undo_redo(ui->service->undeRedo,ui->service->repository);
}

void dislay_elements_by_string_ui(UI* ui)
{
    char string[50];
    printf("Type a string: ");
    scanf("%s",string);
    //printf("\n");
    dislay_elements_by_string_s(ui->service,string);

}

void display_by_category_ui(UI* ui)
{
    char type[20];
    int days;
    printf("Type a category.");
    scanf("%s",type);
    printf("\nHow many days are left?");
    scanf("%d",&days);
    display_elements_by_category_s(ui->service,type,days);
}

void Undo(UI* ui)
{
    if(undo(ui->service->undeRedo,ui->service->repository) == 0)
        printf("There is no operation to undo.\n");
    else
    {
        copy_repo_service(ui->service,ui->service->undeRedo);
        printf("Undo done\n");
    }
}

void Redo(UI* ui)
{
    if(redo(ui->service->undeRedo,ui->service->repository) == 0)
        printf("There is no operation to redo.\n");
    else
    {
        copy_repo_service(ui->service,ui->service->undeRedo);
        printf("Redo done.\n");
    }
}


void start(UI* ui)
{
    int gata=0;
    while(gata == 0)
    {
        char command[100];

        printf("\n");
        printf("Command> ");
        scanf("%s", command);
        printf("\n");

        if(strlen(command)!=1)
            printf("Invalid command!\n");
        else
            switch(command[0])
            {
                case '1':
                    add_product_ui(ui);
                    break;
                case '2':
                    delete_product_ui(ui);
                    break;

                case '3':
                    update_product_ui(ui);
                    break;

                case '4':
                    dislay_elements_by_string_ui(ui);
                    break;

                case '5':
                    display_by_category_ui(ui);
                    break;
                case '6':
                    Undo(ui);
                    break;
                case '7':
                    Redo(ui);
                    break;
                case '8':
                    gata =1;
                    break;
                default:
                    printf("Invalid command!\n");
            }
        }
    }


