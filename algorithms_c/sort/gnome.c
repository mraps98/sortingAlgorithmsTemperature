/* Source: https://github.com/TheAlgorithms/C/blob/master/sorting/gnome_sort.c*/
#include <stdlib.h>
#include "gnome.h"
void gnome_sort(long *numbers, int size)
{
    int pos = 0;
    while (pos < size)
    {
        if (numbers[pos] >= numbers[pos - 1])
            pos++;
        else
        {
            int tmp = numbers[pos - 1];
            numbers[pos - 1] = numbers[pos];
            numbers[pos] = tmp;
            pos--;

            if (pos == 0)
                pos = 1;
        }
    }
}