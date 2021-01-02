/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/07-quicksort/7.01-the_basic_algorithm/examples/prog_7.1-7.2-quicksort.c */
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "quickt.h"

#define key(A) (A.element)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {duplicates_t t = A;  A = B; B = t;}

int partition(duplicates_t a[], int l, int r)
{
  int i = l-1, j = r;
  duplicates_t v = a[r];

  for (;;)
    {
      while (less(a[++i], v));
      while (less(v, a[--j]))
	if (j == l)
	  break;
      if (i >= j)
	break;
      exch(a[i], a[j]);
      
    }
  exch(a[i], a[r]);
  return i;
}

void quick_sort(duplicates_t a[],  int l, int r)     
{
  int i;

  if (r <= l)
    return;
  i = partition(a, l, r);
  quick_sort(a, l, i-1);
  quick_sort(a, i+1, r);
}