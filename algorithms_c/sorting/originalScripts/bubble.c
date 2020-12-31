/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_sorting_methods/6.04-bubble_sort/examples/prog_6.4-bubble_sort.c*/
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch(A, B)

typedef int Item;

void sort(Item a[], int l, int r)
{
  int i, j;

  for (i = l; i < r; i++)
    for (j = r;  j > i; j--)
      compexch(a[j-1], a[j]);
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
        bubble_sort(a, N);
        for (i = 0; i < N; i++)
            printf("%3d ", a[i]);
        printf("\n");
        free(a);
    }
    return 0;
}