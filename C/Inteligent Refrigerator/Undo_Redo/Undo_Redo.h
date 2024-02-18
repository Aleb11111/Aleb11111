//
// Created by Ale on 3/20/2023.
//

#ifndef A23_ALEB1111_UNDO_REDO_H
#define A23_ALEB1111_UNDO_REDO_H

#endif //A23_ALEB1111_UNDO_REDO_H
#pragma once
#include "Repository.h"

typedef struct{

    DynamicArray** contents;
    int count,dimension,pos_current,total;


}Undo_Redo;

Undo_Redo* createUndo_Redo(int dimension,Repository* repo);
void distroy_undo_redo(Undo_Redo* ur);
void resize_undo_redo(Undo_Redo* ur);
void add_undo_redo(Undo_Redo* ur,Repository* repo);
int redo(Undo_Redo* ur,Repository* repo);
int undo(Undo_Redo* ur,Repository* repo);
DynamicArray* duplicate_repo(DynamicArray* dy);