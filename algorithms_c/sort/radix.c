/* Source: https://github.com/diptangsu/Sorting-Algorithms/blob/master/C/RadixSort.c*/
#include<stdlib.h>
#include "radix.h"
static long getMax(long arr[], int n) {
    long mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
static void count_sort(long arr[], int n, int exp) {
    long* output = calloc(n, sizeof(long)); // output array
    int i, count[10] = { 0 };
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);
}
 
// The main function to that sorts arr[] of size n using Radix Sort
void radix_sort(long arr[], int n) {
    long m = getMax(arr, n);
 
    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        count_sort(arr, n, exp);
}
