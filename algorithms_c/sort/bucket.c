/* Source: https://github.com/diptangsu/Sorting-Algorithms/blob/master/C/BucketSort.c */
#include <stdlib.h>
#include "bucket.h"

static int getMax(long array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}
void bucket_sort(long array[], int size)
{
    const int max = getMax(array, size);
    long *bucket = (long *)calloc(max + 1, sizeof(long));
    for (int i = 0; i <= max; i++)
    {
        bucket[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        bucket[array[i]]++;
    }
    for (int i = 0, j = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            array[j++] = i;
            bucket[i]--;
        }
    }
    free(bucket);
}
