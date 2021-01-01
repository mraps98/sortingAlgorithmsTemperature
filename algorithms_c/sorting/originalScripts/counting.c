/* Source: https://github.com/diptangsu/Sorting-Algorithms/blob/master/C/CountingSort.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void counting_sort(int a[], int size){
    int max = 0, index = 0;
    for (int i = 0; i < size; i++){
        if (max < a[i]) max = a[i];
    }
    int* count =  (int *)calloc(max, sizeof(int));  
    for (int i = 1; i < size; i++){
        count[ a[i]] ++;
    }
    
    for (int i = 0; i <= max; i++){
        for (int j = 0; j < count[i]; j++){
            a[index] = i;
            index++;
        }

    }
    free(count);
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
        counting_sort(a, N);
        for (i = 0; i < N; i++)
            printf("%3d ", a[i]);
        printf("\n");
        free(a);
    }
    return 0;
}