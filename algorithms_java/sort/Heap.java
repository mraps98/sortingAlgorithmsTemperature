/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/09-priority_queues_and_heapheapSort/9.04-heapheapSort/prog_9.7-heapheapSort/main.c*/

public class Heap{
	private static boolean less(Comparable[] pq, int i, int j) {
        return pq[i-1].compareTo(pq[j-1]) < 0;
    }
	
	private static void exch(Comparable[] a, int i, int j){
		Comparable swap = a[i-1];
		a[i-1] = a[j-1];
		a[j-1] = swap;
	}
	
	private static void sink(Comparable[] pq, int k, int n) {
        while (2*k <= n) {
            int j = 2*k;
            if (j < n && less(pq, j, j+1)) j++;
            if (!less(pq, k, j)) break;
            exch(pq, k, j);
            k = j;
        }
    }
	public static void heapSort(Comparable[] pq) {
        int n = pq.length;

        // heapify phase
        for (int k = n/2; k >= 1; k--)
            sink(pq, k, n);

        // heapSortdown phase
        int k = n;
        while (k > 1) {
            exch(pq, 1, k--);
            sink(pq, 1, k);
        }
    }
}
