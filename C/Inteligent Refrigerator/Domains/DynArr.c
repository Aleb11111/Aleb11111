//
// Created by Ale on 3/15/2023.
//
#include "DynArr.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray* careateArray(int capacity)
{
    /*
     * parameter capacity = the capacity of the array;
     * this function returns a dynamic array
     */
    DynamicArray* arr = (DynamicArray*)malloc(sizeof(DynamicArray));

    if(arr == NULL)
        return NULL;

    arr->max_length = capacity;
    arr->count =0;

    arr->data = (TElem*)malloc((capacity)*sizeof(TElem));

    if(arr->data == NULL)
        return 0;
    return arr;
}

void add_TElem(DynamicArray* array, TElem TElem)
{
    /*
     * Parameters: array = the array where the element will be added
     *              Telem = the element to be added
     */
    if (array == NULL)
        return;
    if(array->data == NULL)
        return;

    // resize the array, if necessary
    if(array->max_length == array->count)
    {
        array->data =realloc(array, sizeof(TElem) * array->max_length * 2);
        array->max_length = array->max_length * 2;
    }
    array->data[array->count] = TElem;
    array->count++;

}

void delete_TElem(DynamicArray* array, int position)
{
    /*
     * Parameters: array = the array from where we will delete the element
     *              position = the position where that element is.
     */
    for (int i = position; i <= array->count - 1; i++)
        array->data[i] = array->data[i + 1];

    array->count--;
}
void update_TElem(DynamicArray* array, TElem TElem, int position)
{
    /*
     * Parameters:  array = the array where we update the element
     *              Telem = the element which will replace that one
     *              position  = the positioon of the element to be updated
     */
    array->data[position] = TElem;
}

void distroy_dynArr(DynamicArray* array)
{
    /*
     * parameters: array = the array to be destroyed;
     */
    if (array == NULL)
        return;
    // free the space allocated for the planets
    free(array->data);
    array->data = NULL;

    // free the space allocated for the dynamic array
    free(array);
}
