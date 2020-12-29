/* Reference: https://github.com/TheAlgorithms/C/blob/master/sorting/merge_sort_nr.c */
#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

void merge_sort(long x[], int n)
{
    long* temp = (long *) calloc(n, sizeof(long));
    int i, j, k, lb1, lb2, ub1, ub2, size;

    size = 1;
    while (size < n)
    {
        lb1 = 0;
        k = 0;

        while (lb1 + size < n)
        {
            lb2 = lb1 + size;
            ub1 = lb2 - 1;
            if (ub1 + size < n)
                ub2 = ub1 + size;
            else
                ub2 = n - 1;

            i = lb1;
            j = lb2;

            while (i <= ub1 && j <= ub2)
                if (x[i] < x[j])
                    temp[k++] = x[i++];
                else
                    temp[k++] = x[j++];

            while (i <= ub1) temp[k++] = x[i++];

            while (j <= ub2) temp[k++] = x[j++];

            lb1 = ub2 + 1;
        }

        for (i = 0; i <= ub2; i++) x[i] = temp[i];

        size = size * 2;
    }

    free(temp);
}