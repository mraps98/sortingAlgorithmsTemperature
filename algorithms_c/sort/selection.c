/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_sorting_methods/6.02-selection_sort/examples/prog-6.2-selection_sort.c */
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "selection.h"

typedef long Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch(A, B)

void selection_sort(Item a[], int l, int r)
{
  int i, j;

  for (i = l; i < r; i++)
    {
      int min = i;
      for (j = i+1; j <= r; j++)
	if (less(a[j], a[min]))
	  min = j;
      exch(a[i], a[min]);
    }
}