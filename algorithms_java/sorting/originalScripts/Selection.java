/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_sorting_methods/6.02-selection_sort/examples/prog-6.2-selection_sort.c */
public class Selection{
	private static boolean less(long A, long B){
		return (A < B);
	}
	
	private static void exch(long[] a, int i, int j){
		long t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	
	private static void compexch(long[] a, int i, int j){
		if(less(a[j], a[i])){
			exch(a, i, j);
		}
	}

	public static void selection_sort(long a[], int l, int r){
		for (int i = l; i <r; i++){
			int min = i;
			for(int j = i + 1; j <= r; j++){
				if(less(a[j], a[min])){
					min = j;
				}
			}
			exch(a, i, min);
		}
	}
}