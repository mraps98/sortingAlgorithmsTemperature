/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_sorting_methods/6.03-insertion_sort/examples/prog-6.3-insetrion_sort.c */
public class Insertion{
	private static boolean less(long A, long B){
		return (A < B);
	}
	
	private static void exch(long A, long B){
		long t = A;
		A = B;
		B = t;
	}
	
	private static void compexch(long A, long B){
		if(less(B, A)){
			exch(A, B);
		}
	}
	
	public static void insertion_sort(long a[], int l, int r)
	{
	  int i;

	  for (i = r; i > l; i--)
		compexch(a[i-1], a[i]);  // put the smallest into first position
	  for (i = l + 2; i <= r; i++)
		{
		  int j = i;
		  long v = a[i];

		  while (less(v, a[j-1]))
			{
			  a[j] = a[j-1];
			  j--;
			}
		  a[j] = v;
		}
	}
}