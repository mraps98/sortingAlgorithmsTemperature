/* Source: https://www.geeksforgeeks.org/timsort/ */
#include <stdlib.h>
#include "tim.h" 

typedef long Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define compexch(A, B) if (less(B, A)) exch(A, B)
#define min(X,Y) (((X) < (Y)) ? (X) : (Y))
#define RUN 32

static void insertion_sort(Item a[], long l, long r)
{
  long i;

  for (i = r; i > l; i--)
    compexch(a[i-1], a[i]);  // put the smallest longo first position
  for (i = l + 2; i <= r; i++)
    {
      long j = i;
      Item v = a[i];
      
      while (less(v, a[j-1]))
	{
	  a[j] = a[j-1];
	  j--;
	}
      a[j] = v;
    }
}

static void merge_sort(long arr[], long l, long m, long r) 
{ 
      
    // Original array is broken in two parts 
    // left and right array 
    long len1 = m - l + 1, len2 = r - m; 
	long* left = calloc(len1, sizeof(long));
	long* right = calloc(len2, sizeof(long));
    for (long i = 0; i < len1; i++) 
        left[i] = arr[l + i]; 
    for (long i = 0; i < len2; i++) 
        right[i] = arr[m + 1 + i]; 
  
    long i = 0; 
    long j = 0; 
    long k = l; 
  
    // After comparing, we  
    // merge those two array 
    // in larger sub array 
    while (i < len1 && j < len2) 
    { 
        if (left[i] <= right[j]) 
        { 
            arr[k] = left[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy remaining elements of left, if any 
    while (i < len1) 
    { 
        arr[k] = left[i]; 
        k++; 
        i++; 
    } 
  
    // Copy remaining element of right, if any 
    while (j < len2) 
    { 
        arr[k] = right[j]; 
        k++; 
        j++; 
    } 

	free(left);
	free(right);
}
 
void tim_sort(long arr[], long n) 
{ 
      
    // Sort individual subarrays of size RUN 
    for (long i = 0; i < n; i+=RUN) 
        insertion_sort(arr, i, min((i+31),  
                                    (n-1))); 
  
    // Start merging from size RUN (or 32).  
    // It will merge_sort 
    // to form size 64, then 128, 256  
    // and so on .... 
    for (long size = RUN; size < n;  
                             size = 2*size) 
    { 
          
        // pick starting polong of  
        // left sub array. We 
        // are going to merge_sort  
        // arr[left..left+size-1] 
        // and arr[left+size, left+2*size-1] 
        // After every merge_sort, we  
        // increase left by 2*size 
        for (long left = 0; left < n;  
                             left += 2*size) 
        { 
              
            // find ending polong of  
            // left sub array 
            // mid+1 is starting polong  
            // of right sub array 
            long mid = left + size - 1; 
            long right = min((left + 2*size - 1),  
                                            (n-1)); 
  
            // merge_sort sub array arr[left.....mid] & 
            // arr[mid+1....right] 
            merge_sort(arr, left, mid, right); 
        } 
    } 
} 
