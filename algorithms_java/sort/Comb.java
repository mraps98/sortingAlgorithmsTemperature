/*Source: https://github.com/TheAlgorithms/Java/blob/master/Sorts/CombSort.java */
public class Comb{
	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}

	private static boolean exch(Comparable[] a, int i, int j){
		Comparable swap = a[i];
		a[i] = a[j];
		a[j] = swap;
		return true;
	}
 	private static int nextGap(int gap) {
    	// Shrink gap by Shrink factor
    	gap = (gap * 10) / 13;
    	return (gap < 1) ? 1 : gap;
  	}

	public static <T extends Comparable<T>> T[] combSort(T[] arr) {
    	int size = arr.length;

    	// initialize gap
    	int gap = size;

    	// Initialize swapped as true to make sure that loop runs
    	boolean swapped = true;

    	// Keep running while gap is more than 1 and last iteration caused a swap
    	while (gap != 1 || swapped) {
      		// Find next gap
      		gap = nextGap(gap);

      		// Initialize swapped as false so that we can check if swap happened or not
      		swapped = false;

      		// Compare all elements with current gap
      		for (int i = 0; i < size - gap; i++) {
        		if (less(arr[i + gap], arr[i])) {
          			// Swap arr[i] and arr[i+gap]
          			swapped = exch(arr, i, i + gap);
        		}
      		}
    	} 
	return arr;
  }
}
