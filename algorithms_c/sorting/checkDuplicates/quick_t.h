/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/07-quicksort/7.01-the_basic_algorithm/examples/prog_7.1-7.2-quicksort.c */
#ifndef QUICK_T_H
#define QUICK_T_H

typedef struct duplicates{
    long location;
    long element;
}duplicates_t;

int partition(duplicates_t a[], int l, int r);
void quick_sort(duplicates_t a[], int l, int r);
#endif