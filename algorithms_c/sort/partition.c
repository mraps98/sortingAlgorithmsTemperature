/* Source: https://github.com/TheAlgorithms/C/blob/master/sorting/partition_sort.c */
#include "partition.h"
#include <stdlib.h>

static void swap(long *a, long *b)
{
    long tmp = *a;
    *a = *b;
    *b = tmp;
}

static long partition(long arr[], long low, long high)
{
    long pivot = arr[low];
    long i = low - 1, j = high + 1;

    while (1)
    {
        /* Find leftmost element >= pivot */
        do
        {
            i++;
        } while (arr[i] < pivot);

        /* Find rightmost element <= pivot */
        do
        {
            j--;
        } while (arr[j] > pivot);

        /* if two polongers met */
        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

void partition_sort(long arr[], long low, long high)
{
    if (low < high)
    {
        long value = partition(arr, low, high);
        partition_sort(arr, low, value);
        partition_sort(arr, value + 1, high);
    }
}
