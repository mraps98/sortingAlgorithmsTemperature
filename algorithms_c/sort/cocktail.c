/* Source: https://github.com/TheAlgorithms/C/blob/master/sorting/cocktail_sort.c*/
#include <stdlib.h>
#include "cocktail.h"

#define TRUE 1
#define FALSE 0

void cocktail_sort(long arr[], int size)
{
    int i, changed = TRUE, start = 0, end = size - 1;
    long temp;

    while (changed)
    {
        changed = FALSE;
        for (i = start; i < end; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                changed = TRUE;
            }
        }
        end--;

        if (changed == FALSE)
        {
            break;
        }
        changed = FALSE;

        for (i = end - 1; i >= start; i--)
        {
            if (arr[i + 1] < arr[i])
            {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                changed = TRUE;
            }
        }
        start++;
    }
}