/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/08-merging_and_mergemergeSort/8.03-top_down_mergemergeSort/examples/prog_8.3-top_down_mergemergeSort.c */
public class Merge{	
	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}

	private static void exch(Comparable[] a, int i, int j){
		Comparable swap = a[i];
		a[i] = a[j];
		a[j] = swap;
	}

  	private static void merge(Comparable[] a, Comparable[] aux, int lo, int mid, int hi) {
        // copy to aux[]
        for (int k = lo; k <= hi; k++) {
            aux[k] = a[k]; 
        }

        // merge back to a[]
        int i = lo, j = mid+1;
        for (int k = lo; k <= hi; k++) {
            if      (i > mid)              a[k] = aux[j++];
            else if (j > hi)               a[k] = aux[i++];
            else if (less(aux[j], aux[i])) a[k] = aux[j++];
            else                           a[k] = aux[i++];
        }

    }	

	// mergemergeSort a[lo..hi] using auxiliary array aux[lo..hi]
    private static void mergeSort(Comparable[] a, Comparable[] aux, int lo, int hi) {
        if (hi <= lo) return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(a, aux, lo, mid);
        mergeSort(a, aux, mid + 1, hi);
        merge(a, aux, lo, mid, hi);
    }

    public static void mergeSort(Comparable[] a) {
        Comparable[] aux = new Comparable[a.length];
        mergeSort(a, aux, 0, a.length-1);
    }
}
