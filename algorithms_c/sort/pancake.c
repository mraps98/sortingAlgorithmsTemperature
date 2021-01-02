/* Source: https://github.com/diptangsu/Sorting-Algorithms/blob/master/C/PancakeSort.c */
#include <stdlib.h>
#include "pancake.h"
 
static void doFlip(long *list,  int length,  int num)
{
    int swap;
    int i = 0;
    for (i;i < --num;i++)
    {
        swap = list[i];
        list[i] = list[num];
        list[num] = swap;
    }
}
int pancake_sort(long *list, unsigned int length)
{
    if (length < 2)
        return 0;
    int i, a, max_num_pos, moves;
 
    moves = 0;
    for (i = length;i > 1;i--)
    {
        max_num_pos = 0;
        for (a = 0;a < i;a++)
        {
            if (list[a] > list[max_num_pos])
                max_num_pos = a;
        }
        if (max_num_pos ==  i - 1)
            continue;
        if (max_num_pos)
        {
            moves++;
            doFlip(list, length, max_num_pos + 1);
        }
        doFlip(list, length, i);
    }
    return moves;
}