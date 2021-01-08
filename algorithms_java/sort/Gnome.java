/*Source: https://github.com/TheAlgorithms/Java/blob/master/Sorts/GnomeSort.java */
public class Gnome{
	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}

	private static void exch(Comparable[] a, int i, int j){
		Comparable swap = a[i];
		a[i] = a[j];
		a[j] = swap;
	}

	public static <T extends Comparable<T>> T[] gnomeSort(T[] arr) {
    	int i = 1;
    	int j = 2;
    	while (i < arr.length) {
      		if (less(arr[i - 1], arr[i])) i = j++;
      		else {
        		exch(arr, i - 1, i);
        		if (--i == 0) {
          			i = j++;
        		}
      		}
    	}
    return null;
  }
}
