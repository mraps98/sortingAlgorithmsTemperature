/* Source: ://github.com/TheAlgorithms/C/blob/master/sorting/bubble_rec_sort_recursion.c */
#include <stdbool.h>
#include <stdlib.h>
#include "bubble_rec.h"
static void swap(long *first, long *second)
{
    long temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * Bubble sort algorithm implements using recursion
 * @param arr array to be sorted
 * @param size size of array
 */
void bubble_rec_sort(long *arr, long size)
{
    if (size == 1)
    {
        return;
    }
    bool swapped = false;
    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr + i, arr + i + 1);
            swapped = true;
        }
    }
    if (swapped)
    {
        bubble_rec_sort(arr, size - 1);
    }
}

