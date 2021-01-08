/* Source: https://github.com/TheAlgorithms/Java/blob/master/Sorts/RadixSort.java */
public class Radix{
	private static boolean less(Comparable v, Comparable w){
		return (v.compareTo(w) < 0);
	}

	private static void exch(Comparable[] a, int i, int j){
		Comparable swap = a[i];
		a[i] = a[j];
		a[j] = swap;
	}

	private static Comparable getMax(Comparable[] arr, int n) {
		Comparable mx = arr[0];
		for (int i = 1; i < n; i++) if (!less(arr[i], mx)) mx = arr[i];
		return mx;
	}

	private static void countSort(Comparable[] arr, int n, int exp) {
		Long[] output = new Long[n];
		int i;
		int[] count = new int[10];
		for(i = 0; i < 10; i++){
			count[i] = 0;
		}

		for (i = 0; i < n; i++) count[(arr[i].intValue() / exp) % 10]++;

		for (i = 1; i < 10; i++) count[i] += count[i - 1];

		for (i = n - 1; i >= 0; i--) {
				output[count[(arr[i] / exp) % 10] - 1] = arr[i];
				count[(arr[i] / exp) % 10]--;
		}

		for (i = 0; i < n; i++) arr[i] = output[i];
	}

	public static void radixSort(Comparable[] arr, int n) {

		Comparable m = getMax(arr, n);

		for (int exp = 1; m / exp > 0; exp *= 10) countSort(arr, n, exp);
	}
}
