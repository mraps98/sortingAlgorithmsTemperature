/* Source: https://algs4.cs.princeton.edu/21elementary/Selection.java.html */
public class Selection{
	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}
	
	private static void exch(Comparable[] a, int i, int j){
		Comparable swap = a[i];
		a[i] = a[j];
		a[j] = swap;
	}
	
	public static void selectionSort(Comparable[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++) {
            int min = i;
            for (int j = i+1; j < n; j++) {
                if (less(a[j], a[min])) min = j;
            }
            exch(a, i, min);
        }
    }
}
