/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_bubbleSorting_methods/6.04-bubble_bubbleSort/examples/prog_6.4-bubble_bubbleSort.c*/
/* Second reference: https://github.com/TheAlgorithms/Java/blob/master/Sorts/BubbleSort.java */

public class Bubble{
	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}

	private static void exch(Comparable[] a, int i, int j){
		Comparable exch = a[i];
		a[i] = a[j];
		a[j] = exch;
	}

	public static <T extends Comparable<T>> T[] bubbleSort(T[] array) {
    for (int i = 0, size = array.length; i < size - 1; ++i) {
      boolean exchped = false;
      for (int j = 0; j < size - 1 - i; ++j) {
        if (!less(array[j], array[j + 1])) {
          exch(array, j, j + 1);
          exchped = true;
        }
      }
      if (!exchped) {
        break;
      }
    }
    return array;
  }
}
