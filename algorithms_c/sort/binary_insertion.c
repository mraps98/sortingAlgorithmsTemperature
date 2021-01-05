/* Source https://github.com/TheAlgorithms/C/blob/master/sorting/binary_insertion_sort.c */
#include <stdlib.h>
#include "binary_insertion.h"
static long binary_search(long *arr, long key, long low, long high)
{
	if (low >= high)
		return (key > arr[low]) ? (low + 1) : low;
	long mid = low + (high - 1) / 2;
	if (arr[mid] == key)
		return mid + 1;
	else if (arr[mid] > key)
		return binary_search(arr, key, low, mid - 1);
	else
		return binary_search(arr, key, mid + 1, high);
}
/*This is where the sorting of the array takes place
 *  arr[] --- Array to be sorted
 *   size --- Array Size
 *    */
void binsertion_sort(long *arr, long size)
{
	long i, j, key, index;
	for (i = 0; i < size; i++)
	{
		j = i - 1;
		key = arr[i];
		/* Use binary search to find exact key's index */
		index = binary_search(arr, key, 0, j);
		/* Move all elements greater than key from [index...j]  one position */
		while (j >= index)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		/* Insert key value in right place */
		arr[j + 1] = key;
	}
}
