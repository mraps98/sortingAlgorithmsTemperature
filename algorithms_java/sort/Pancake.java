/* Source: https://www.geeksforgeeks.org/pancake-sorting/ */
public class Pancake{
	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}

	private static void exch(Comparable[] a, int i, int j){
		Comparable swap = a[i];
		a[i] = a[j];
		a[j] = swap;
	}

	private static int findMax(Comparable[] arr, int n) {
		int mx =0;
		for (int i = 1; i < n; i++) if (!less(arr[i], arr[mx])) mx = i;
		return mx;
	}

	private static void flip(Long arr[], int i){
		Long temp;
		int start = 0;
    	while (start < i) {
        	temp = arr[start];
        	arr[start] = arr[i];
        	arr[i] = temp;
        	start++;
        	i--;
    	}
	}
	
	public static void pancakeSort(Long arr[], int n){
		for (int curr_size = n; curr_size > 1; --curr_size) 
    	{
        	int mi = findMax(arr, curr_size);
 
        	if (mi != curr_size - 1) {
            	flip(arr, mi);
 
            	flip(arr, curr_size - 1);
        	}
    	}
	}
}
