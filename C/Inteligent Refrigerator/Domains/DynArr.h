//
// Created by Ale on 3/15/2023.
//

#ifndef A23_ALEB1111_DYNARR_H
#define A23_ALEB1111_DYNARR_H

#endif //A23_ALEB1111_DYNARR_H

#pragma once
#include "Product.h"

typedef Product TElem;
/*
 * Here the dynamic array is defined.
 * The Telem field holds the vector of elements.
 * The field count is the number of elements in the array and the field max_length is the maximum length which the array can have.
 */
typedef struct
{
    TElem* data;
    int count;
    int max_length;

} DynamicArray;

DynamicArray* careateArray(int capacity);
void add_TElem(DynamicArray* array, TElem TElem);
void delete_TElem(DynamicArray* array, int position);
void update_TElem(DynamicArray* array, TElem TElem, int position);
void distroy_dynArr(DynamicArray* array);
