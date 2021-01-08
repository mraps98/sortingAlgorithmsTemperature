/* Source: https://github.com/TheAlgorithms/Java/blob/master/Sorts/CocktailShakerSort.java */
public class Cocktail{
	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}

	private static void exch(Comparable[] a, int i, int j){
		Comparable swap = a[i];
		a[i] = a[j];
		a[j] = swap;
	}
	
	public static <T extends Comparable<T>> T[] cocktailSort(T[] array) {

    int length = array.length;
    int left = 0;
    int right = length - 1;
    int swappedLeft, swappedRight;
    while (left < right) {
      // front
      swappedRight = 0;
      for (int i = left; i < right; i++) {
        if (less(array[i + 1], array[i])) {
          exch(array, i, i + 1);
          swappedRight = i;
        }
      }
      // back
      right = swappedRight;
      swappedLeft = length - 1;
      for (int j = right; j > left; j--) {
        if (less(array[j], array[j - 1])) {
          exch(array, j - 1, j);
          swappedLeft = j;
        }
      }
      left = swappedLeft;
    }
    return array;
  }
}
