/*Source: https://www.geeksforgeeks.org/recursive-insertion-sort/ */
public class InsertionRec{
	static void insertionRecSort(Long arr[], int n){
		if(n <= 1)
			return;

		insertionRecSort(arr, n - 1);

		Long last = new Long(arr[n-1]);
		int j = n - 2;

		while(j>= 0 && arr[j] > last)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = last;
	}
}
