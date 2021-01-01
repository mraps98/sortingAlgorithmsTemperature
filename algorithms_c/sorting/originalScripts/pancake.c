/* Source: https://github.com/diptangsu/Sorting-Algorithms/blob/master/C/PancakeSort.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
static void doFlip(int *, int, int);
 
int pancake_sort(int *list, unsigned int length)
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
 

static void doFlip(int *list,  int length,  int num)
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
 

void printArray(int list[], int length)
{
    int i;
    for (i = 0;i < length;i++)
    {
        printf("%d ", list[i]);
    }
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
        pancake_sort(a, N);
        for (i = 0; i < N; i++)
            printf("%3d ", a[i]);
        printf("\n");
        free(a);
    }
    return 0;
}