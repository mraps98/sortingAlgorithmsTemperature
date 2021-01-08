/* Source: https://github.com/TheAlgorithms/Java/blob/master/Sorts/BubbleSortRecursion.java */
public class BubbleRec{
	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}

	private static void exch(Comparable[] a, int i, int j){
		Comparable swap = a[i];
		a[i] = a[j];
		a[j] = swap;
	}
	
	private static <T extends Comparable<T>> void bubbleSort(T[] unsorted, int len) {
   		boolean swapped = false; /* flag to check if array is sorted or not */
    	for (int i = 0; i < len - 1; ++i) {
      		if (!less(unsorted[i], unsorted[i + 1])) {
        	exch(unsorted, i, i + 1);
        	swapped = true;
   		 	}
   		}
   		if (swapped) {
      		bubbleSort(unsorted, len - 1);
   		}
 	}

	public static <T extends Comparable<T>> T[] bubbleSort(T[] unsorted) {
  		bubbleSort(unsorted, unsorted.length);
    	return unsorted;
  }
}
