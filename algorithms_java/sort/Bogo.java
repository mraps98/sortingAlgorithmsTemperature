/* Source: https://github.com/TheAlgorithms/Java/blob/master/Sorts/BogoSort.java */
import java.util.Random;
public class Bogo{
	private static final Random random = new Random();
	
	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}

	private static void exch(Comparable[] a, int i, int j){
		Comparable swap = a[i];
		a[i] = a[j];
		a[j] = swap;
	}

	private static <T extends Comparable<T>> boolean isSorted(T[] array) {
		for (int i = 0; i < array.length - 1; i++) {
			if (less(array[i + 1], array[i])) return false;
		}
    return true;
	}

  // Randomly shuffles the array
  private static <T extends Comparable<T>> void nextPermutation(T[] array) {
    int length = array.length;

    for (int i = 0; i < array.length; i++) {
      int randomIndex = i + random.nextInt(length - i);
      exch(array, randomIndex, i);
    }
  }

  public static <T extends Comparable<T>> T[] bogoSort(T[] array) {
    while (!isSorted(array)) {
      nextPermutation(array);
    }
    return array;
  }
}
