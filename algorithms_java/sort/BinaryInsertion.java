/* Source: https://algs4.cs.princeton.edu/code/edu/princeton/cs/algs4/BinaryInsertion.java.html */
public class BinaryInsertion{
	private static boolean less(Comparable v, Comparable w) {
        return v.compareTo(w) < 0;
    }

	public static void binsertionSort(Comparable[] a) {
   		int n = a.length;
        for (int i = 1; i < n; i++) {

            // binary search to determine index j at which to insert a[i]
            Comparable v = a[i];
            int lo = 0, hi = i;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2; 
                if (less(v, a[mid])) hi = mid;
                else                 lo = mid + 1;
            }

            // insetion binsertionSort with "half exchanges"
            // (insert a[i] at index j and shift a[j], ..., a[i-1] to right)
            for (int j = i; j > lo; --j)
                a[j] = a[j-1];
            a[lo] = v;
        }
    }
}
