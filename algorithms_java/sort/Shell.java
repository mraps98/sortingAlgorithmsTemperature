/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_sorting_methods/6.06-shell_sort/examples/prog-6.5-shellsort.c */
public class Shell{

	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}

	private static void exch(Comparable[] a, int i, int j){
		Comparable swap = a[i];
		a[i] = a[j];
		a[j] = swap;
	}

	public static void shellSort(Comparable[] a) {
        int n = a.length;

        // 3x+1 increment sequence:  1, 4, 13, 40, 121, 364, 1093, ... 
        int h = 1;
        while (h < n/3) h = 3*h + 1; 

        while (h >= 1) {
            // h-sort the array
            for (int i = h; i < n; i++) {
                for (int j = i; j >= h && less(a[j], a[j-h]); j -= h) {
                    exch(a, j, j-h);
                }
            }
            h /= 3;
        }
    }	
}
