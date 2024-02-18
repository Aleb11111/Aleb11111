//
// Created by Ale on 3/20/2023.
//

#include "Undo_Redo.h"
#include <malloc.h>
#include <string.h>
Undo_Redo* createUndo_Redo(int dimension,Repository* repo)
{
    Undo_Redo* unre = (Undo_Redo*)malloc(sizeof(Undo_Redo));

    unre->count = 0;
    unre->dimension = dimension;
    unre->pos_current = 0;
    unre->total = 0;
    unre->contents = (DynamicArray **)malloc(dimension*sizeof(DynamicArray*));
    //for(int i = 0;i<=repo->array->count;i++)
    for(int i=0;i<=dimension;i++)
        unre->contents[unre->pos_current] = (DynamicArray*)malloc(sizeof(DynamicArray)*repo->array->count);

    return unre;
}

void distroy_undo_redo(Undo_Redo* ur)
{
    if (ur == NULL)
        return;
    for(int i=0;i<=ur->count;i++)
        free(ur->contents[i]->data);

    free(ur->contents);
    ur->contents=NULL;
    free(ur);
}

void resize_undo_redo(Undo_Redo* ur)
{
    ur->contents = (DynamicArray**)(realloc(ur,sizeof(DynamicArray*)*ur->dimension*2));
    ur->dimension = ur->dimension*2;
}

DynamicArray* duplicate_repo(DynamicArray* dy)
{
    /*/
     * Here the repo is duplicated and this is used for the undo_redo;*/

    DynamicArray* da = careateArray(100);
    da->max_length = dy->max_length;
    da->count = dy->count;

    da->data = (Product*)malloc(dy->max_length * sizeof(Product));

    for(int i = 0; i<=dy->count; i++)
    {
        strcpy(da->data[i].name, dy->data[i].name);
        strcpy(da->data[i].type, dy->data[i].type);
        strcpy(da->data[i].expire_date, dy->data[i].expire_date);
        da->data[i].quantity = dy->data[i].quantity;
    }
    return da;

}
void add_undo_redo(Undo_Redo* ur,Repository* repo)
{
    if(ur == NULL)
        return;
    if(ur->contents == NULL)
        return;
    if(ur->dimension == ur->pos_current)
        resize_undo_redo(ur);
    //ur->contents[ur->pos_current] = repo->array;
    ur->pos_current++;
    ur->count++;
    ur->total=ur->pos_current;
    ur->contents[ur->pos_current]= duplicate_repo(repo->array);
}

int redo(Undo_Redo* ur,Repository* repo)
{
    if(ur->pos_current == ur->total)
        return 0;
    ur->pos_current++;
    //repo->array = ur->contents[ur->pos_current];
    return 1;
}
int undo(Undo_Redo* ur,Repository* repo)
{
    if(ur->pos_current == 0)
        return 0;
    ur->pos_current--;
    //repo->array = ur->contents[ur->pos_current];
    return 1;
}


