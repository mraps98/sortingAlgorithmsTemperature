/* Source: https://github.com/diptangsu/Sorting-Algorithms/blob/master/C/BogoSort.c*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bogo.h"

static bool check_sorted(long *a, int n)
{
    while (--n >= 1)
    {
        if (a[n] < a[n - 1])
            return false;
    }
    return true;
}

static void shuffle(long *a, int n)
{
    int i, t, r;
    for (i = 0; i < n; i++)
    {
        t = a[i];
        r = rand() % n;
        a[i] = a[r];
        a[r] = t;
    }
}

void bogo_sort(long *a, int n)
{
    while (!check_sorted(a, n))
        shuffle(a, n);
}