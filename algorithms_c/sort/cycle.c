/* Source: https://github.com/diptangsu/Sorting-Algorithms/blob/master/C/CycleSort.c*/
#include <stdlib.h>
#include "cycle.h"
int cycle_sort(long *list, size_t l_len)
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