/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_sorting_methods/6.03-insertion_sort/examples/prog-6.3-insetrion_sort.c */
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "insertion.h"

typedef long Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch(A, B)

void insertion_sort(Item a[], int l, int r)
{
  int i;

  for (i = r; i > l; i--)
    compexch(a[i-1], a[i]);  // put the smallest into first position
  for (i = l + 2; i <= r; i++)
    {
      int j = i;
      Item v = a[i];
      
      while (less(v, a[j-1]))
	{
	  a[j] = a[j-1];
	  j--;
	}
      a[j] = v;
    }
}