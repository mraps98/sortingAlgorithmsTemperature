/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_sorting_methods/6.04-bubble_sort/examples/prog_6.4-bubble_sort.c*/

public class Bubble{
	
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

	public static void bubbleSort(long a[], int l, int r){
		for(int i = l; i < r; i++){
			for(int j = r; j > i; j--){
				compexch(a, j-1, j);
			}
		}
	}
}
