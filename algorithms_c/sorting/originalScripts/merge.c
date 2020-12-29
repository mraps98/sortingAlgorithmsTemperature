/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/08-merging_and_mergesort/8.03-top_down_mergesort/examples/prog_8.3-top_down_mergesort.c */
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))

typedef int Item;

int *aux;

void merge(Item a[], int l, int m, int r)
{
  int i, j, k;

  for (i = m+1; i > l; i--)
    aux[i-1] = a[i-1];
  for (j = m; j < r; j++)
    aux[r+m-j] = a[j+1];
  for (k = l; k <= r; k++)
    if (less(aux[j], aux[i]))
      a[k] = aux[j--];
    else
      a[k] = aux[i++];
}

void mergesort(Item a[], int l, int r)
{
  int m = (r+l)/2;

  if (r <= l) return;
  mergesort(a, l, m);
  mergesort(a, m+1, r);
  merge(a, l, m, r);
}  
print_array(Item a[], int n)
{
  int i;

  for(i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main(int argc, char *argv[]) 
{
  int i, N, sw, *a;

  srand(time(NULL));
  if (argc < 3)
    printf("You have not entered enough arguments: N and sw required!\n ");
  else
    {
      N = atoi(argv[1]);
      a = malloc(N*sizeof(Item));
      aux = malloc(N*sizeof(Item));
      sw = atoi(argv[2]);
      if (sw)
	for (i = 0; i < N; i++)
	  a[i] = 1000 * (1.0*rand()/RAND_MAX);
      else
	while (scanf("%d", &a[N]) == 1)
	  N++;
      printf("Initial: ");
      print_array(a, N);
      mergesort(a, 0, N-1);
      printf("After: ");
      print_array(a, N);
    }
  return 0;
}