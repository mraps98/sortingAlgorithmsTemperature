/* Source: https://github.com/diptangsu/Sorting-Algorithms/blob/master/C/CycleSort.c*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static int cycleSort(int *list, size_t l_len);
static void show_array(int *array, size_t a_len);
/*
 * Sort an array in place and return the number of writes.
 */
int cycle_sort(int *list, size_t l_len)
{
    int cycleStart, writes = 0;

    /* Loop through the array to find cycles to rotate. */
    for (cycleStart = 0; cycleStart < l_len - 1; ++cycleStart)
    {
        int item = list[cycleStart];
        int swap_tmp, i;

        /* Find where to put the item. */
        int pos = cycleStart;
        for (i = cycleStart + 1; i < l_len; ++i)
        {
            if (list[i] < item)
            {
                ++pos;
            }
        }

        /* If the item is already there, this is not a cycle. */
        if (pos == cycleStart)
        {
            continue;
        }

        /* Otherwise, put the item there or right after any duplicates. */
        while (item == list[pos])
        {
            ++pos;
        }
        swap_tmp = list[pos];
        list[pos] = item;
        item = swap_tmp;
        ++writes;

        /* Rotate the rest of the cycle. */
        while (pos != cycleStart)
        {
            /* Find where to put the item. */
            pos = cycleStart;
            for (i = cycleStart + 1; i < l_len; ++i)
            {
                if (list[i] < item)
                {
                    ++pos;
                }
            }

            /* Put the item there or right after any duplicates. */
            while (item == list[pos])
            {
                ++pos;
            }
            swap_tmp = list[pos];
            list[pos] = item;
            item = swap_tmp;
            ++writes;
        }
    }
    return writes;
}
int main(int argc, char *argv[])
{

    int i, N, sw;

    srand(time(NULL));
    if (argc < 3)
        printf("You have not entered enough arguments: N and sw required!\n ");
    else
    {
        N = atoi(argv[1]);
        sw = atoi(argv[2]);
        int *a = malloc(N * sizeof(int));
        if (sw)
            for (i = 0; i < N; i++)
                a[i] = 1000 * (1.0 * rand() / RAND_MAX);
        else
            while (scanf("%d", &a[N]) == 1)
                N++;
        printf("Initial: ");
        for (i = 0; i < N; i++)
            printf("%3d ", a[i]);
        printf("\nAfter: ");
        cycle_sort(a, N);
        for (i = 0; i < N; i++)
            printf("%3d ", a[i]);
        printf("\n");
        free(a);
    }
    return 0;
}