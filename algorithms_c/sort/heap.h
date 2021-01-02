/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/09-priority_queues_and_heapsort/9.04-heapsort/prog_9.7-heapsort/main.c*/
#ifndef HEAP_H
#define HEAP_H
typedef long Item;

void fixUp(Item a[], int k);
void fixDown(Item a[], int k, int N);
void PQinit(int maxN);
int PQempty(void);
void PQinsert(Item v);
Item PQdelmax(void);
void heap_sort(Item a[], int l, int r);
#endif