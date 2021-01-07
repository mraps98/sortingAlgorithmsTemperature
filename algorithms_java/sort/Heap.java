/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/09-priority_queues_and_heapsort/9.04-heapsort/prog_9.7-heapsort/main.c*/

public class Heap{
	private static boolean less(long A, long B){
		return (A < B);
	}
	
	private static void exch(long A, long B){
		long t = A;
		A = B;
		B = t;
	}
	
	private static void fixUp(long a[], int k)
	{
	  while (k > 1 && less(a[k/2], a[k]))
		{
		  exch(a[k], a[k/2]);
		  k = k/2;
		}
	}

	private static void fixDown(long a[], int k, int N)
	{
	  int j;

	  while (2*k <= N)
		{
		  j = 2*k;
		  if (j < N && less(a[j], a[j+1]))
		j++;
		  if (!less(a[k], a[j]))
		break;
		  exch(a[k], a[j]);
		  k = j;
		}
	}

	private void sink(int k, int N){
		while(2*k <= N){
			int j = 2 * k;
			if(j<N && less(j, j+1)) j++;
			if(!less(k, j)) break;
			exch(k, j); k = j;
		}
	}

	public static void heap_sort(long a[], int l, int r)
	{
		for(int k = N/2; k >= 1; k--){
			sink(k, N);
		}
		while(N>1){
			exch(1, N);
			sink(1, --N);
		}	
	}
}
