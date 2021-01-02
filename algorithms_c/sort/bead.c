/* Source: https://github.com/TheAlgorithms/C/blob/master/sorting/bead_sort.c */
#include <stdlib.h>
#include "bead.h"

#define BEAD(i, j) beads[i * max + j]

void bead_sort(long *a, size_t len)
{
    int i, j; 
    long max, sum;
    unsigned char *beads;

    for (i = 1, max = a[0]; i < len; i++)
        if (a[i] > max)
            max = a[i];

    beads = calloc(1, max * len);

    /* mark the beads */
    for (i = 0; i < len; i++)
        for (j = 0; j < a[i]; j++) BEAD(i, j) = 1;

    for (j = 0; j < max; j++)
    {
        /* count how many beads are on each post */
        for (sum = i = 0; i < len; i++)
        {
            sum += BEAD(i, j);
            BEAD(i, j) = 0;
        }
        /* mark bottom sum beads */
        for (i = len - sum; i < len; i++) BEAD(i, j) = 1;
    }

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < max && BEAD(i, j); j++)
            ;
        a[i] = j;
    }
    free(beads);
}