/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/07-quicksort/7.01-the_basic_algorithm/examples/prog_7.1-7.2-quicksort.c */
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "quick.h"

typedef long Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}

int partition(Item a[], int l, int r)
{
  int i = l-1, j = r;
  Item v = a[r];

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

void quick_sort(Item a[], int l, int r)     
{
  int i;

  if (r <= l)
    return;
  i = partition(a, l, r);
  quick_sort(a, l, i-1);
  quick_sort(a, i+1, r);
}