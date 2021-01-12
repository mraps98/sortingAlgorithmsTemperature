/* Source: https://github.com/TheAlgorithms/Java/blob/master/Sorts/BubbleSortRecursion.java */
public class BubbleRec{
	public static void bubbleSort(Long A[], int n, int i, int j){
		Long swap = new Long(0);
		if(i >= n-1){
			return;
		}	
		if(j < n - 1){
			bubbleSort(A, n, i, j + 1);
			if(A[j] > A[j+1]){
				swap = A[j];
				A[j] = A[j+1];
				A[j+1] = swap;
				swap = null;
			}
		}
		if(j == 0)
			bubbleSort(A, n, i +1, 0);
	}
}
