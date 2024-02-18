//
// Created by Ale on 3/22/2023.
//

#ifndef A23_ALEB1111_UNDO_REDO_H
#define A23_ALEB1111_UNDO_REDO_H

#endif //A23_ALEB1111_UNDO_REDO_H

#import "DynArr.h"


typedef struct{

    DynamicArray* undo;
    DynamicArray* redo ;
    int count_undo,count_redo,pos_undo,pos_redo;

}UndoRedo;

UndoRedo* createUndoRedo(DynamicArray* undo,DynamicArray* redo, int count_undo, int count_redo, int pos_undo,int pos_redo);
void add_Undo_Redo(UndoRedo* ur, int x);