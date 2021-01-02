/* Source: https://github.com/diptangsu/Sorting-Algorithms/blob/master/C/CountingSort.c */
#include <stdlib.h>

void counting_sort(long a[], int size){
    long max = 0, index = 0;
    for (int i = 0; i < size; i++){
        if (max < a[i]) max = a[i];
    }
    int* count =  (int *)calloc(max, sizeof(int));  
    for (int i = 1; i < size; i++){
        count[ a[i]] ++;
    }
    
    for (int i = 0; i <= max; i++){
        for (int j = 0; j < count[i]; j++){
            a[index] = i;
            index++;
        }

    }
    free(count);
}