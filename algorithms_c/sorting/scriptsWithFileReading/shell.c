/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_sorting_methods/6.06-shell_sort/examples/prog-6.5-shellsort.c */
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "shell.h"

typedef long Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch(A, B)

void shell_sort(Item a[], int l, int r)
{
  int i, j, h;

  for (h = 1; h <= (r-l)/9; h = 3*h+1);
  for ( ; h > 0; h /= 3)
      for (i = l+h; i <= r; i++)
	{
	  int j = i;
	  Item  v = a[i];

	  while (j >= l+h && less(v, a[j-h]))
	    {
	      a[j] = a[j-h];
	      j -= h;
	    }
	  a[j] = v;
	}
}