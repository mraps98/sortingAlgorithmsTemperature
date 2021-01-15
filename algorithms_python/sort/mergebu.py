#source: https://www.techiedelight.com/iterative-merge-sort-algorithm-bottom-up/
def merge(A, temp, frm, mid, to):
	k = frm
	i = frm
	j = mid + 1

	while i <= mid and j <= to:
		if A[i] < A[j]:
			temp[k] = A[i]
			i = i + 1

		else:
			temp[k] = A[j]
			j = j + 1

		k = k + 1

	while i < len(A) and i <= mid:
		temp[k] = A[i]
		k = k + 1
		i = i + 1

	for i in range(frm, to + 1):
		A[i] = temp[i]

def mergebuSort(A):
	low = 0
	high = len(A) - 1

	temp = A.copy()

	m = 1

	while m <= high - low:
		for i in range(low, high, 2* m):
			frm = i
			mid = i + m - 1
			to = min(i + 2 * m - 1, high)
			merge(A, temp, frm, mid, to)
	
		m = 2 * m
