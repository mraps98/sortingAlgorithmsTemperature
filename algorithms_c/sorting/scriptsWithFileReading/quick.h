/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/07-quicksort/7.01-the_basic_algorithm/examples/prog_7.1-7.2-quicksort.c */
#ifndef QUICK_H
#define QUICK_H
typedef long Item;

int partition(Item a[], int l, int r);
void quick_sort(Item a[], int l, int r);
#endif