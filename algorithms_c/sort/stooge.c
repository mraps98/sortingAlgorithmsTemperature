/* Source: https://github.com/TheAlgorithms/C/blob/master/sorting/stooge_sort.c */
void stooge_sort(long arr[], int i, int j)
{
    int k;
    long temp;
    if (arr[i] > arr[j])
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    if ((i + 1) >= j)
        return;
    k = (int)((j - i + 1) / 3);
    stooge_sort(arr, i, j - k);
    stooge_sort(arr, i + k, j);
    stooge_sort(arr, i, j - k);
}