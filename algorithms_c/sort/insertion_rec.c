/* Source https://github.com/TheAlgorithms/C/blob/master/sorting/insertion_sort_recursive.c */
#include "insertion_rec.h"
void insertion_rec_sort(long *arr, long size)
{
	if(size <= 0)
	{
		return;
	}
	        
	// marking recursive call to reach starting element
	insertion_rec_sort(arr,size-1);
		
	long key = arr[size-1];
	long j = size-2;
	// swapping logic for insertion sort
	while(j >= 0 && arr[j] > key)
	{
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1] = key;
}
