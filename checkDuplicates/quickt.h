/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/07-quicksort/7.01-the_basic_algorithm/examples/prog_7.1-7.2-quicksort.c */
#ifndef QUICKT_H
#define QUICKT_H

typedef struct duplicates{
    long location;
    long element;
    unsigned int flag;
}duplicates_t;

int partitiont(duplicates_t a[], int l, int r);
void quick_sortt(duplicates_t a[], int l, int r);
#endif
