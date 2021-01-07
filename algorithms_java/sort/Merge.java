/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/08-merging_and_mergesort/8.03-top_down_mergesort/examples/prog_8.3-top_down_mergesort.c */
public class Merge{	
	private static long[] aux;
	
	private static boolean less(long A, long B){
		return (A < B);
	}
	
	private static void merge(long a[], int l, int m, int r)
	{
	  int i, j, k;

	  for (i = m+1; i > l; i--)
		aux[i-1] = a[i-1];
	  for (j = m; j < r; j++)
		aux[r+m-j] = a[j+1];
	  for (k = l; k <= r; k++)
		if (less(aux[j], aux[i]))
		  a[k] = aux[j--];
		else
		  a[k] = aux[i++];
	}

	public static void merge_sort(long[] a, int l, int r){
		if(r<=l){
			return;
		}
		int m = (r+l)/2;
		merge_sort(a, l, m);
		merge_sort(a, m+1, r);
		merge(a, l, m, r);
	}
}