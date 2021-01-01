/* Source: https://github.com/diptangsu/Sorting-Algorithms/blob/master/C/RadixSort.c*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
static int getMax(int arr[], int n) {
    int mx = arr[0];
    int i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
static void count_sort(int arr[], int n, int exp) {
    int output[n]; // output array
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
}
 
// The main function to that sorts arr[] of size n using Radix Sort
void radix_sort(int arr[], int n) {
    int m = getMax(arr, n);
 
    int exp;
    for (exp = 1; m / exp > 0; exp *= 10)
        count_sort(arr, n, exp);
}
 int main(int argc, char *argv[])
{

    int i, N, sw;

    srand(time(NULL));
    if (argc < 3)
        printf("You have not entered enough arguments: N and sw required!\n ");
    else
    {
        N = atoi(argv[1]);
        sw = atoi(argv[2]);
        int *a = malloc(N * sizeof(int));
        if (sw)
            for (i = 0; i < N; i++)
                a[i] = 1000 * (1.0 * rand() / RAND_MAX);
        else
            while (scanf("%d", &a[N]) == 1)
                N++;
        printf("Initial: ");
        for (i = 0; i < N; i++)
            printf("%3d ", a[i]);
        printf("\nAfter: ");
        radix_sort(a, N);
        for (i = 0; i < N; i++)
            printf("%3d ", a[i]);
        printf("\n");
        free(a);
    }
    return 0;
}