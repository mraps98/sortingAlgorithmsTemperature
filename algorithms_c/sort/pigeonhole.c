/* Source: https://github.com/TheAlgorithms/C/blob/master/sorting/pigeonhole_sort.c */
#include <stdlib.h>
#include "pigeonhole.h"
void pigeonhole_sort(long arr[], long size)
{
    long i, j, min = arr[0], max = arr[0], range;

    // Getting range of the array using max and min
    for (i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    range = max - min + 1;

    // Make 'holes' and put array's numbers in holes
    long *holes = (long *)malloc(sizeof(long) * range);
    for (i = 0; i < range; i++)
    {
        holes[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        holes[arr[i] - min]++;
    }

    // Copy the numbers back to the original array
    j = 0;
    for (i = 0; i < range; i++)
    {
        while (holes[i] > 0)
        {
            arr[j] = i + min;
            holes[i]--;
            j++;
        }
    }

    free(holes);
}
