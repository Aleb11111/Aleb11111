//
// Created by Ale on 3/15/2023.
//
#include "Undo_Redo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./Domains/DynArr.h"
#include "./Repository.h"
#include "../Services/Service.h"
#include "UI.h"
int main()
{
    DynamicArray* da;
    da = careateArray(100);

    Repository* repo;

    repo= createRepo(da);
    Service* serv;
    Undo_Redo* undoRedo;
    undoRedo = createUndo_Redo(20,repo);
    serv = createServices(repo,undoRedo);
    initialize(serv);

    UI* ui;
    ui = create_UI(serv);
    menu();
    start(ui);
    distroy_UI(ui);

}