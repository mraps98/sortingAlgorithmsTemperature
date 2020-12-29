/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_sorting_methods/6.04-bubble_sort/examples/prog_6.4-bubble_sort.c*/
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "bubble.h"

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch(A, B)

typedef long Item;

void bubble_sort(Item a[], int l, int r)
{
  int i, j;

  for (i = l; i < r; i++)
    for (j = r;  j > i; j--)
      compexch(a[j-1], a[j]);
}